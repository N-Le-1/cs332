#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void listFiles(const char *basePath);

int main (int argc, char **argv) { 
  struct dirent *dirent; 
  DIR *parentDir; 

  if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
  } 
  parentDir = opendir (argv[1]); 
  if (parentDir == NULL) { 
    printf ("Error opening directory '%s'\n", argv[1]); 
    exit (-1);
  } 
  listFiles(argv[1]);

  closedir (parentDir); 

  return 0; 
} 

void listFiles(const char *basePath){

    struct dirent *dirent;
    struct stat statbuf;
    int count = 1;
    char path[1024];

    DIR *dir = opendir(basePath);
    if(!dir){
        perror("Error opening directory :(");
        return;
    }

    while((dirent = readdir(dir))!= NULL){
        snprintf(path, sizeof(path), "%s/%s", basePath, dirent -> d_name);

        if(stat(path,&statbuf) == -1){
            perror("Error getting file");
            continue;
        }
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(dirent -> d_name, ".")!= 0 && strcmp(dirent -> d_name, "..")!= 0){
                printf("[%d] %s (Directory)\n",count,path);
                count++;
                listFiles(path);
            }
        }
        else{
            printf("[%d] %s (File)\n",count,path);
            count++;
        }
    }
    
    closedir(dir);
}
