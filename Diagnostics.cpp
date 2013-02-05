
#include "Synchronized.h"
#include "Diagnostics.h"

Diagnostics::Diagnostics() {
	m_buf = m_buf_a;
	m_buf_len = 0;

	m_log = fopen("/3322-diag.txt", "w");
	m_task = new Task("3322Diagnostics", (FUNCPTR)Diagnostics::InitTask);
	m_flushing = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	m_writing = semBCreate(SEM_Q_PRIORITY, SEM_FULL);

	if (!m_task->Start((INT32)this)) {
		// FIXME: how to use WPI error handling?
	}
}

void Diagnostics::InitTask(Diagnostics *d) {
	d->Run();
}

void Diagnostics::Run() {
	fprintf(m_log, "Diagnostics started\n");
	fflush(m_log);

	while (true) {
		// Wait for a writer to signal ready to flush the buffer
		semTake(m_flushing, WAIT_FOREVER);

		fprintf(m_log, "Data ready\n");
		fflush(m_log);

		char* temp_buf = m_buf;
		int temp_buf_len;

		// Flip buffers and let the writers continue writing
		{
			Synchronized sync(m_writing);

			temp_buf_len = m_buf_len;
			m_buf = (m_buf == m_buf_a) ? m_buf_b : m_buf_a;
			m_buf_len = 0;
		}

		fprintf(m_log, "Buffer flip. len=%d\n", temp_buf_len);
		fflush(m_log);

		// Flush the buffer, then go back to waiting
		fwrite(temp_buf, temp_buf_len, 1, m_log);
		fflush(m_log);
	}
}

void Diagnostics::Snapshot(char *mode, double start, double end, double gyroAngle) {
	Synchronized sync(m_writing);

	if (m_buf_len < DIAG_SIZE - DIAG_LINE_SIZE) {
		// The writer must guarantee never to use more than DIAG_LINE_SIZE bytes.
		// If that amount of buffer space is not available, it means buffer flushing
		// is lagging behind. Skip writing until the buffer flushes. TODO: it's
		// not clear whether new snapshots are more valuable than old -- we could
		// push older snapshots out of the buffer if the buffer is full.

		int len = sprintf(m_buf + m_buf_len, "%s,%.8f,%.8f,%.8f\n", mode, start, end, gyroAngle);
		m_buf_len += len;

		if (m_buf_len > DIAG_SIZE / 2) {
			// If the buffer is full enough, start flushing.
			semGive(m_flushing);
		}
	}
}
