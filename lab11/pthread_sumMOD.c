/* 
  Simple Pthread Program to find the sum of a vector.
  Uses mutex locks to update the global sum. 
  Author: Purushotham Bangalore
  Date: Jan 25, 2009

  To Compile: gcc -O -Wall pthread_psum.c -lpthread
  To Run: ./a.out 1000 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct ThreadData {
    double *a;
    double sum;
    int N;
    int size;
    long tid;
};

void *compute(void *arg) {
    // Cast the argument to the ThreadData structure
    struct ThreadData *data = (struct ThreadData *)arg;

    // Calculate start and end indices
    int myStart = data->tid * (data->N / data->size);
    int myEnd = myStart + (data->N / data->size);
    if (data->tid == (data->size - 1)) myEnd = data->N;

    // Compute partial sum
    double mysum = 0.0;
    for (int i = myStart; i < myEnd; i++) {
        mysum += data->a[i];
    }

    // Update global sum with mutex protection
    pthread_mutex_lock(&mutex);
    data->sum += mysum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <# of elements> <# of threads>\n", argv[0]);
        exit(-1);
    }

    int N = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Allocate vector and initialize
    double *a = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++) {
        a[i] = (double)(i + 1);
    }

    // Create thread data structures
    struct ThreadData *threadData = (struct ThreadData *)malloc(sizeof(struct ThreadData) * size);

    // Create threads
    pthread_t *tid = (pthread_t *)malloc(sizeof(pthread_t) * size);
    for (int i = 0; i < size; i++) {
        threadData[i].a = a;
        threadData[i].sum = 0.0;
        threadData[i].N = N;
        threadData[i].size = size;
        threadData[i].tid = i;
        pthread_create(&tid[i], NULL, compute, &threadData[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < size; i++) {
        pthread_join(tid[i], NULL);
    }

    // Calculate total sum from partial sums
    double totalSum = 0.0;
    for (int i = 0; i < size; i++) {
        totalSum += threadData[i].sum;
    }

    printf("The total is %g, it should be equal to %g\n", totalSum, ((double)N * (N + 1)) / 2);
    
    return 0;
}
