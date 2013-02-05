
#include <stdio.h>
#include "Task.h"

#define DIAG_LINE_SIZE 2048
#define DIAG_SIZE 32*DIAG_LINE_SIZE

class Diagnostics {
public:
	char* m_buf;
	char m_buf_a[DIAG_SIZE];
	char m_buf_b[DIAG_SIZE];
	int m_buf_len;

	FILE* m_log;
	Task* m_task;
	SEM_ID m_flushing;
	SEM_ID m_writing;

	Diagnostics();

	static void InitTask(Diagnostics *d);
	void Run();

	// FIXME: need a much more granular API so all the data doesn't
	// funnel through a single method.
	void Snapshot(char *mode, double start, double end, double gyroAngle = 0);
};
