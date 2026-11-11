/**********************************************
* Filename: finfo.c
* Description: Display file information
* Compile: gcc finfo.c -o finfo
* Author: James F. Connelly
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat file_info;

    if(argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if(stat(argv[1], &file_info) != 0)
    {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);

    printf("Type: ");

    if(S_ISREG(file_info.st_mode)){
        printf("Regular File\n");
    }
    else if(S_ISDIR(file_info.st_mode)){
        printf("Directory\n");
    }
    else if(S_ISLNK(file_info.st_mode)) {
        printf("Symbolic Link\n");
    }
    else if(S_ISCHR(file_info.st_mode)) {
        printf("Character Device\n");
    }
    else if(S_ISBLK(file_info.st_mode)) {
        printf("Block Device\n");
    }
    else if(S_ISFIFO(file_info.st_mode)) {
        printf("FIFO\n");
    }
    else if(S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    }
    else{
        printf("Unknown\n");
    }

    printf("Permissions: ");

    printf((file_info.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_info.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_info.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_info.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_info.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_info.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_info.st_mode & S_IROTH) ? "r" : "-");
    printf((file_info.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_info.st_mode & S_IXOTH) ? "x" : "-");

    printf("\n");

    printf("Owner UID: %d\n", file_info.st_uid);

    printf("Size: %ld bytes\n", file_info.st_size);

    char *time_string = ctime(&file_info.st_mtime);

    if(time_string != NULL){
        printf("Last Modified: %s", time_string);
    }

    return 0;
}