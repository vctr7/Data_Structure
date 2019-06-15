// Timer.h
// Header file for Timer_Windows.c and Timer_MacUnix.c

typedef enum { NOT_STARTED, RUNNING, FINISHED } TimerState;

typedef
struct TIMER
{
		// Timing Data
		int startClock, finishClock;
		float clockFrequency;

		// Timer State
		TimerState timerState;
	
}Timer;

Timer * createTimer(void);
void initClockFrequency(Timer * timer);
void startTimer(Timer * timer);
void stopTimer(Timer * timer);
double getTotalSeconds(Timer * timer);


