/* Simple program to illustrate the use of fork-exec-wait pattern. 
 * This version uses execvp and command-line arguments to create a new process.
 * To Compile: gcc -Wall forkexecvp.c
 * To Run: ./a.out <command> [args]
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int signum) {
    if (signum == SIGINT) {
        printf("Child process received Interrupt Signal (Ctrl-C)\n");
    } else if (signum == SIGTSTP) {
        printf("Child process received Suspend Signal (Ctrl-Z)\n");
        raise(SIGSTOP);  // Suspend the child process
    } else if (signum == SIGQUIT) {
        if (getpid() == getpgrp()) {  // Check if this is the parent process
            printf("Parent process received Quit Signal (Ctrl-\\)\n");
            exit(0);
        }
    }
}

int main(int argc, char **argv) {
    pid_t pid;
    int status;

    if (argc < 2) {
        printf("Usage: %s <command> [args]\n", argv[0]);
        exit(-1);
    }

    signal(SIGINT, signalHandler);
    signal(SIGTSTP, signalHandler);
    signal(SIGQUIT, signalHandler);

    pid = fork();
    if (pid == 0) { /* this is child process */
        sleep(20); //Pauses processes for me to test signals
        execvp(argv[1], &argv[1]);
        printf("If you see this statement then execl failed ;-(\n");
	perror("execvp");
	exit(-1);
    } else if (pid > 0) { /* this is the parent process */
        printf("Wait for the child process to terminate\n");
        wait(&status); /* wait for the child process to terminate */
        if (WIFEXITED(status)) { /* child process terminated normally */
            printf("Child process exited with status = %d\n", WEXITSTATUS(status));
        } else { /* child process did not terminate normally */
            printf("Child process did not terminate normally!\n");
            /* look at the man page for wait (man 2 wait) to determine
               how the child process was terminated */
        }
    } else { /* we have an error */
        perror("fork"); /* use perror to print the system error message */
        exit(EXIT_FAILURE);
    }
    
    printf("[%ld]: Exiting program .....\n", (long)getpid());

    return 0;
}
