#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_JOBS 100
#define MAX_COMMAND_LENGTH 1000

// Structure to hold information about each job
typedef struct {
    pid_t pid;          // Process ID
    char command[MAX_COMMAND_LENGTH]; // Command to execute
    int status;         // Status: 0 for waiting, 1 for running
} Job;

Job jobs[MAX_JOBS];     // Array to store job information
int num_jobs = 0;       // Number of currently active jobs
int max_jobs;           // Maximum number of concurrent jobs

// Function to submit a new job
void submit_job(char *command) {
    if (num_jobs >= MAX_JOBS) {
        printf("Error: Maximum number of jobs reached.\n");
        return;
    }

    // Create a new process
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        printf("Error: Failed to fork.\n");
        return;
    } else if (pid == 0) {
        // Child process
        // Execute the command and redirect output and error streams
        char output_file[MAX_COMMAND_LENGTH];
        char error_file[MAX_COMMAND_LENGTH];
        sprintf(output_file, "%d.out", getpid());
        sprintf(error_file, "%d.err", getpid());
        freopen(output_file, "w", stdout);
        freopen(error_file, "w", stderr);
        execlp(command, command, NULL);
        // If execlp returns, it means an error occurred
        perror("Error");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Add the job to the list
        strcpy(jobs[num_jobs].command, command);
        jobs[num_jobs].pid = pid;
        jobs[num_jobs].status = 1; // Running
        num_jobs++;
        printf("Job submitted with jobid: %d\n", pid);
    }
}

// Function to list all jobs
void show_jobs() {
    printf("Job ID\tStatus\n");
    for (int i = 0; i < num_jobs; i++) {
        int status;
        // Check if the process is still running
        if (waitpid(jobs[i].pid, &status, WNOHANG) == 0) {
            printf("%d\tRunning\n", jobs[i].pid);
        } else {
            printf("%d\tCompleted\n", jobs[i].pid);
            // Shift remaining jobs in the array
            for (int j = i; j < num_jobs - 1; j++) {
                jobs[j] = jobs[j + 1];
            }
            num_jobs--;
            i--; // Adjust the index as we shifted the array
        }
    }
}

int main(int argc, char *argv[]) {
 
    max_jobs = atoi(argv[1]);

    printf("====Welcome to the Job Scheduler for CS332====\n");

    while (1) {
        // Print prompt and wait for user input
        printf("Enter a command (submit,showjobs,or exit): \n");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse input command
        char command[MAX_COMMAND_LENGTH];
        char args[MAX_COMMAND_LENGTH];
        sscanf(input, "%s %[^\n]", command, args);

        if (strcmp(command, "submit") == 0) {
            submit_job(args);
        }else if (strcmp(command, "showjobs") == 0) {
            show_jobs();
        }
        else if (strcmp(command,"exit")==0) {
            printf("Goodbye!");
            exit(1);
        }
    }
    return 0;
}
