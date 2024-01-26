#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    char* readString(char ***arr, int *size);
    void insertionSort(char **arr, int size);
    void displayStrings(char **arr, int size);


    int main(int argc, char** argv){
        char **strings;
        int size;

        readString(&strings, &size);

        insertionSort(strings, size);

        displayStrings(strings,size);

        }
    
    char* readString(char ***arr, int *size){

        printf("Please enter the number of strings you will input: ");
        scanf("%d",size);

        *arr=(char **)malloc(*size * sizeof(char*));

        printf("Please enter the strings: ");
        for(int i=0;i<*size;i++){
            char buffer[256];
            scanf("%s",buffer);
            (*arr)[i] = strdup(buffer);
        }
    }

    void insertionSort(char **arr, int size){
        for(int i=1; i< size; i++){
            char *key = arr[i];
            int j = i-1;

            while(j>=0 && strcmp(arr[j],key)>0){
                arr[j+1] = arr[j];
                j = j -1;
            }

            arr[j+1] = key;
        }
    }

    void displayStrings(char **arr, int size){
        printf("Sorted Strings: \n");
        printf("[");
        for(int i =0; i< size ;i++){
            printf("%s ", arr[i]);
        }
        printf("]");
    }