/************************************************
*   FileName: pinfo.c
*   Author: James F. Connelly
*   Date: 11/10/2026
*   Discription: Takes a process ID and prints it to the console
************************************************/


#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sched.h>
#include <errno.h>



int main(int argc, char *argv[]){
    int pid;

    if(argc > 1){
        pid = atoi(argv[1]);
    }
    else{
        pid = getpid();
    }

    errno = 0;

    int priority = getpriority(PRIO_PROCESS, pid);

    if(errno != 0){
        printf("Error: Process does not exist.\n");
        return 1;
    }

    int policy = sched_getscheduler(pid);

    if(policy == -1){
        printf("Error: Process does not exist.\n");
        return 1;
    }

    printf("PID: %d\n", pid);
    printf("Priority: %d\n", priority);
    printf("Scheduling Method: ");

    switch(policy){
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;

        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;

        case SCHED_RR:
            printf("SCHED_RR\n");
            break;

        case SCHED_BATCH:
            printf("SCHED_BATCH\n");
            break;

        case SCHED_IDLE:
            printf("SCHED_IDLE\n");
            break;

        default:
            printf("UNKNOWN\n");
            break;
    }

    return 0;
}