
#include <stdio.h>
#include <stdarg.h>
#include "Task.h"

#define DIAG_LINE_SIZE 2048			//7 characters used for line number
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

	void Snapshot(char *mode, double start, double end);
	void MotorSnapShot(unsigned int motorNumber, float busVoltage = 0, float outputCurrent = 0);
	void FlushToDisk();
	int bufferPrintf(const char* format,...);
};
