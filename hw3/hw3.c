/*
Noah Le
nhle
Homework Assignment #3
To compile: make or gcc -o hw3 hw3.c
To run: make run or ./hw3 <condition if wanted ex. (-s, -v, -L)
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

void executeUnixCommand (char *command,const char *filename) {
    __pid_t pid;
    pid = fork();

    if (pid == 0) {
        char *args[64];
        char *token;
        int i =0;

        token = strtok((char *)command, " ");
        while(token !=NULL){
            args[i++] = token;
            token = strtok(NULL," ");
        }
        args[i] = NULL;
        // Child process
        execvp(args[0],args);
        // If execlp fails, print an error message
        perror("Error executing command RAHHHHH");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for child process to complete
    } else {
        // Fork failed
        perror("Error creating child process");
        exit(EXIT_FAILURE);
    }
}


void listFiles(char *basePath, const int root, int depth, int size, char *pattern, int v, char *command) {

    char path[1024];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

//IF NO DIRECTORY IS AVALIABLE
    if (!dir)
        return;
// CREATES A RECURSIVE FUNCTION UNTIL THE PROGRAM HAS READ THE ENTIRE DIRECTORY

    while ((dp = readdir(dir)) != NULL) {
//ADDS ALL THE FILE INFORMATION TO THE path VARIABLE
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            struct stat stats;
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            stat(path, &stats);
        //PRINTS OUT FOLDERS/FILES IN HIERARCHY 
            if (S_ISDIR(stats.st_mode)) {
                printf("%*s %s\n", depth, "", dp->d_name);
                listFiles(path, root, depth + 2, size, pattern, v, command);
            } 
            else {
        //CONDITION FOR s OPTION
                if (pattern != NULL && strstr(dp->d_name, pattern) == NULL)
                    continue; // IF CONDITIONS FAIL, USE CONTINUE TO MOVE ON TO NEXT CONDITION
        //CONDITION FOR L OPTION
                if (size > 0 && stats.st_size < size) 
                    continue; // IF CONDITIONS FAIL, USE CONTINUE TO MOVE ON TO NEXT CONDITION
        //CONDITION FOR v OPTION
                if (v) { 
                    printf("%*s- %s (%ld bytes, %o, %s)\n", depth, "", dp->d_name, stats.st_size, stats.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO), ctime(&stats.st_mtime));
                } else {
                    printf("%*s%s\n", depth, "", dp->d_name);
                }
                if(command){
                    executeUnixCommand(command,path);
                }
            }
        }
    }
//CLOSE DIRECTORY WHEN THE RECURSIVE FUNCTION ENDS
    closedir(dir);
}

int main(int argc, char *argv[]) {
    int size = 0;
    char *pattern = NULL;
    int v = 0;
    char *command = NULL;
    //char *operation = NULL;

    void (*funPointer)(char*,int,int,int,char*,int,char*) = &listFiles;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-L") == 0 && i + 1 < argc) {
            size = atoi(argv[++i]); //converts string value to integer value

        } else if (strcmp(argv[i], "-s") == 0 && i + 2 < argc) {
            pattern = argv[++i];

        } else if (strcmp(argv[i], "-v") == 0) {
            v = 1;
        }
        if (strcmp(argv[i],"-e") == 0){
            command = argv[i+1]; 
        }
    }

    (*funPointer)(".", 0, 0, size, pattern, v,command);

    return 0;
}