/************************************************
*   FileName: pmod.c
*   Author: James F. Connelly
*   Date: 11/10/2026
*   Discription: Gathers information from the OS and prints it to the console
************************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    int result;
    
    result = nice(10);

    printf("New nice value: %d\n", result);

    struct timespec delay;
    delay.tv_sec = 1;
    delay.tv_nsec = 837272638;

    printf("Sleeping...\n");
    nanosleep(&delay, NULL);
    printf("Goodbye\n");

    return 0;
}