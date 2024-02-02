#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *file1,*file2;
    char reader;
//CHECKING IF FILES AND EX. LINE IS PRESENT
    if(argc != 3){
        printf("Usage: ./main file1 file2\n");
        return 1;
    }
//CHECKING IF FILES ARE THE SAME
    if(strcmp(argv[1], argv[2]) == 0){
        printf("Error: The file names are the same. \n");
        return 1;
    }
//FILE ERROR MESSAGES
    file1 = fopen(argv[1],"a");
    if(file1 ==NULL){
        printf("File 1 Error: %s", argv[1]);
        return 1;
    }
    file2 = fopen(argv[2],"r");
    if(file2 == NULL){
        printf("File 2 Error: %s",argv[2]);
        return 1;
    }
//FILE READING AND COPYING FUNCTION
    while((reader = fgetc(file2))!= EOF ){
        fputc(reader,file1);
    }

    fclose(file1);
    fclose(file2);
//CONFIRMATION MESSAGE
    printf("OPERATION COMPLETED!\n");

    return 0;
}