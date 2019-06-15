#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

#include "Timer.h"
#include "FibonacciIO.h"



long queryValueOfN(){
    long n;
    printf("Enter value of n: ");
    scanf("%ld", &n);

    return n;
}

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



void printResults(Timer * timer, long n, long fibN){
    printf("Fibonacci(%ld) = %ld\n", n, fibN);
    printf("Total Time: %.8f seconds\n", getTotalSeconds(timer));
}

long fibonacci3(long n){
    long nOver2, fibNOver2, fibNOver2Minus1, result;

    if(n<=0) return 0;
    if(n<=2) return 1;

    if(n%2 ==0) nOver2 = n/2;
    else    nOver2 = (n+1)/2;

    fibNOver2 = fibonacci3(nOver2);
    fibNOver2Minus1 = fibonacci3(nOver2 -1);

    if (n%2 ==0)
        result = (2*fibNOver2Minus1 + fibNOver2) * fibNOver2;
    else
        result = (fibNOver2 * fibNOver2 + fibNOver2Minus1 * fibNOver2Minus1);

    return result;

}

int main(){
    Timer * myTimer = createTimer();
    long num, fibonacciNum;

    num = queryValueOfN();

    printf("Calculating... ");
    startTimer(myTimer);
    fibonacciNum=fibonacci3(num);
    stopTimer(myTimer);
    printf("Finished!\n");

    printResults(myTimer, num, fibonacciNum);
    return 0;
}

