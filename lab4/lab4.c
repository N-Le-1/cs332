#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *file1,*file2;
    char ch;

    if(argc != 3){
        printf("Usage: ./main file1 file2\n");
        return 1;
    }

    if(strcmp(argv[1], argv[2]) == 0){
        printf("Error: The file names are the same. \n");
        return 1;
    }

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

    while((ch = fgetc(file2))!= EOF ){
        fputc(ch,file1);
    }

    fclose(file1);
    fclose(file2);

    printf("OPERATION COMPLETED!\n");

    return 0;
}