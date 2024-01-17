#include <stdio.h>

void insertionSort(int numArray[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = numArray[i];
        j = i - 1;

        while (j >= 0 && numArray[j] > key) {
            numArray[j + 1] = numArray[j];
            j = j - 1;
        }
        numArray[j + 1] = key;
    }
}

int main() {
    int arr[10];
    int n = 10;

    printf("Enter 10 integers: (Please include spaces in between the integers.):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
