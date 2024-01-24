#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int numberTransformer(int n);
char* UABNumber();
int reverseNum(int n3);
int smallerThanIndex(int arr[5]);
void arrayDetails(int arr[]);

int main(int argc, char**agrv){
    //initial variables
    int n2;
    int arr[5] = {10,20,1,2,30};
    int arr2[6] = {-8,18,103,1,-4,631};

    printf("***Question 1*** \n");
    numberTransformer(3);

    printf("***Question 2*** \n");
    char* result = UABNumber();
    printf("%s \n",result);

    printf("***Question 3*** \n");
    printf("%d \n",reverseNum(1234));
    
    printf("***Question 4*** \n");
    printf("%d \n", smallerThanIndex(arr));

    printf("***Question 5*** \n");
    arrayDetails(arr2);

}

/*Question 1 DONE */

/*3 Functions to help solve prime num, nearest prime num, sum of nums in int*/

int primeNum(int num){
    if(num<=1){
        return 0;
    }
    for(int i =2;i*i<=num;i++){
        if(num % i ==0){
            return 0;
        }
    }
    return 1;
}
int nearestPrimeNum(int num){
    for(int i=num-1; i>=2; i--){
        if(primeNum(i)){
            return i;
        }
    }
}

int sumOfNum(int num){
    int sum =0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}

//Main Function for Question 1

int numberTransformer(int n){
    if(primeNum(n)&& n!=3 && n!=5){
        printf("Go Blazers \n");
    }
    else if ( n%3 == 0 && n%5 == 0){
        printf("UAB CS 332&532 \n");
    }
    else if(sumOfNum(n)%3 ==0){
        printf("CS \n");
    }
    else if(pow(2, log2(n))==n){
        int nearestPrime = nearestPrimeNum(n);
        int result = n + nearestPrime;
        printf("%d \n",result);
    }
    else{
        int squaredSum = pow(sumOfNum(n),2);
        printf("%d \n",squaredSum);
    }
}

/*Question 2 DONE*/
char* UABNumber() {
    int n2 = 0;
    char* boolVal = "False";

    printf("Enter an integer: ");
    scanf("%d", &n2);

    // Base Case
    if (n2 == 0) {
        return 0;
    }
    
    int divisors = 0;
    for (int i = 1; i <= n2 / 2; i++) {
        if (n2 % i == 0) {
            divisors += i;
        }
    }
    
    if(divisors == n2){
        boolVal = "True";
    }
    return boolVal;
}

/*Question 3 DONE*/
int reverseNum(int n3){
    int ans = 0;
    while(n3 > 0){
        ans = ans * 10 + n3 % 10;
        n3 = n3/10;
    }
    return ans;
}

/*Question 4 DONE*/
int smallerThanIndex(int arr[5]){
    int ans = 0;
    
    for(int i=0;i<5;i++){
        if(arr[i]<i){
            ans++;
        }
    }
    return ans;
}

/*Question 5 DONE */
    void arrayDetails(int arr[]) {
    
    int min = arr[0];
    int minIndex = 0;
    int max = arr[0];
    int maxIndex = 0;
    double sum = 0;

    for (int i = 0; i < 6; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
        sum += arr[i];
    }

    double mean = sum / 6.0;

    printf("[%d,%d,%0.2f,%d,%d] \n",min,minIndex,mean,max,maxIndex);
}
