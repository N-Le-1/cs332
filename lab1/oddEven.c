#include <stdio.h>

int main (int argc, char**argv){
    int given_number;

    printf("Enter an integer: ");
    scanf("%d",&given_number);

    if(given_number % 2 == 0){
        printf("The number is even \n");
    }
    else{
        printf("The number is odd \n");
    }

    return 0;
}