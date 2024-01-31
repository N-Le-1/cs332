#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

void listFiles(char *basePath, const int root, int depth, int size, char *pattern, int v) {

    char path[1024];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

//IF NO DIRECTORY IS AVALIABLE
    if (!dir)
        return;
// CREATES A RECURSIVE FUNCTION UNTIL THE PROGRAM HAS READ THE ENTIRE DIRECTORY

    while ((dp = readdir(dir)) != NULL) {

        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            struct stat stats;
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            stat(path, &stats);
        //PRINTS OUT FOLDERS/FILES IN HIERARCHY 
            if (S_ISDIR(stats.st_mode)) {
                printf("%*s %s\n", depth, "", dp->d_name);
                listFiles(path, root, depth + 2, size, pattern, v);
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

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-L") == 0 && i + 1 < argc) {
            size = atoi(argv[++i]); //converts string value to integer value

        } else if (strcmp(argv[i], "-s") == 0 && i + 2 < argc) {
            pattern = argv[++i];

        } else if (strcmp(argv[i], "-v") == 0) {
            v = 1;
        }
    }

    listFiles(".", 0, 0, size, pattern, v);

    return 0;
}