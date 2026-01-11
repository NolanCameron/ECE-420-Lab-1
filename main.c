#include <stdlib.h>
#include <pthread.h>
#include <memory.h>
#include <math.h>
#include "lab1_IO.h"
#include "timer.h"

int **A, **B, **C;
int n;
int numOfThreads;

void* calMatrixBlock(void* threads){

}

int main (int argc, char* argv[]){

    double start;
    double end;

    numOfThreads = atoi(argv[1]);

    pthread_t* threadHandles = malloc(numOfThreads*sizeof(pthread_t)); 
    Lab1_loadinput(&A, &B, &n);

    C = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        C[i] = (int *)malloc(n * sizeof(int));
    }

    GET_TIME(start)    //Start time
    for (int thread = 0; thread < numOfThreads; thread++) {
        pthread_create(&threadHandles[thread], NULL, calMatrixBlock, (void*)thread);
    }


    for (int thread = 0; thread < numOfThreads; thread++) {
        pthread_join(threadHandles[thread], NULL);
    }
    GET_TIME(end);    //End Time

    Lab1_saveoutput(C, &n, end-start);

    for(int i = 0; i < n; i++){
        free(C[i]);
    }
    free(C);

    return 0;

}