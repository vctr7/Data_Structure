// Timer_MacUnix.c
// Written by David Wagner
// This file contains functions to take high precision timings

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "Timer.h"

// Create a timer, initialize its state and frequency, 
// and return the new timer
Timer * createTimer()
{
	Timer * newTimer = malloc(sizeof(Timer));

	newTimer->timerState = NOT_STARTED;
	initClockFrequency(newTimer);

	return newTimer;
}

// Initialize the frequency of the clock
void initClockFrequency(Timer * timer)
{
	timer->clockFrequency = 1000000;
}

// Start the timer
void startTimer(Timer * timer)
{
	struct timeval timeStamp;
	
	gettimeofday(&timeStamp, NULL);
	timer->startClock = (timeStamp.tv_sec * 1000000) + timeStamp.tv_usec;
	timer->timerState = RUNNING;
}

// Stop the timer
void stopTimer(Timer * timer)
{
	struct timeval timeStamp;
	
	if (timer->timerState == NOT_STARTED) {
		printf("Error: Timer Not Started\n");
	} else {
		gettimeofday(&timeStamp, NULL);
		timer->finishClock = (timeStamp.tv_sec * 1000000) + timeStamp.tv_usec;
		timer->timerState = FINISHED;
	}
}

// Calculate and return the total number of seconds
// that elapsed while the timer was running
double getTotalSeconds(Timer * timer)
{
	if (timer->timerState != FINISHED) {
		printf("Error: Timer not Finished\n");
		return 0.0;
	} else {
		return (timer->finishClock - timer->startClock) / 
			timer->clockFrequency;
	}
}


