#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];
    FILE *fp;
    char output[1024];

    printf("=== Lab 12 Assignment ===\n");
    printf("Enter commands (type 'quit' to exit):\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "quit") == 0) {
            printf("Exiting program...bye!\n");
            break;
        }

        // Execute the command using popen
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("Error executing command");
            continue;
        }

        // Read and display the output
        while (fgets(output, sizeof(output), fp) != NULL) {
            printf("%s", output);
        }

        // Close the pipe
        pclose(fp);
    }

    return 0;
}
