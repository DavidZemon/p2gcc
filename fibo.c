#include <stdio.h>
#include "propeller.h"

unsigned int _clkfreq = 80000000;

unsigned int clock(void)
{
    return CNT;
}

unsigned int fibo (unsigned int n)
{
    if (n < 2)
    {
        return (n);
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

extern unsigned int clock(void);

void main (int argc,  char* argv[])
{
    int n;
    int result;
    unsigned int startTime;
    unsigned int endTime;
    unsigned int executionTime;
    unsigned int rawTime;

    waitcnt(CNT+12000000);
    printf("hello, world!\r\n");
    for (n = 0; n <= 26; n++)
    {
        printf("fibo(%02d) = ", n);
        startTime = clock();
        result = fibo(n);
        endTime = clock();
        rawTime = endTime - startTime;
        executionTime = rawTime / (CLKFREQ / 1000);
        printf ("%06d (%05ums) (%u ticks)\n", result, executionTime, rawTime);
    }
}
