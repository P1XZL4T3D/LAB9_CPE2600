/************************************************
*   FileName: info.c
*   Author: James F. Connelly
*   Date: 11/10/2026
*   Discription: Gathers information from the OS and prints it to the console
************************************************/

#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>


int main(int argc, char* argv[])
{
    struct timespec ts;
    struct utsname uts;

    char hostname[256];

    clock_gettime(CLOCK_REALTIME, &ts);

    printf("Current Time\n");
    printf("Seconds     : %ld\n", ts.tv_sec);
    printf("Nanoseconds : %ld\n\n", ts.tv_nsec);

    if(gethostname(hostname, sizeof(hostname)) == 0){
        if(hostname[0] != '\0'){
            printf("Hostname: %s\n", hostname);
        }
    }

    if(uname(&uts) == 0){
        if(uts.sysname[0] != '\0'){
            printf("OS Name: %s\n", uts.sysname);
        }

        if(uts.release[0] != '\0'){
            printf("OS Release: %s\n", uts.release);
        }

        if(uts.version[0] != '\0'){
            printf("OS Version: %s\n", uts.version);
        }

        if(uts.machine[0] != '\0'){
            printf("Hardware Type: %s\n", uts.machine);
        }
    }

    printf("CPUs: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));

    struct sysinfo info;

    if(sysinfo(&info) == 0){
        unsigned long long total = (unsigned long long)info.totalram * info.mem_unit;

        unsigned long long free = (unsigned long long)info.freeram * info.mem_unit;

        printf("Total Memory: %llu bytes\n", total);
        printf("Free Memory : %llu bytes\n", free);
    }

    printf("Page Size: %d bytes\n", getpagesize());

    return 0;
}