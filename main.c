#include <stdlib.h>
#include <pthread.h>
#include <memory.h>
#include <math.h>
#include <stdint.h>
#include "lab1_IO.h"
#include "timer.h"

int **A, **B, **C;
int n;
int p;

void* calMatrixBlock(void* threadNum){

    int thread = (int)(intptr_t)threadNum;

    int threadX = floor(thread / n);
    int threadY = thread % n;
    //ADD ERROR CHECKING
    int blockWidth = n/sqrt(p);
    int sum;

    for(int i = 0; i < blockWidth; ++i){
        for(int j = 0; j<blockWidth; ++j){
            sum = 0;
            for(int k = 0; k<n; ++k){
                sum+=A[i+threadX*blockWidth][k]*B[k][j+threadY*blockWidth];
            }

            C[i+threadX*blockWidth][threadY*blockWidth] = sum;

        }
    }

    return 0;

}


int main (int argc, char* argv[]){

    p = atoi(argv[1]);
    pthread_t* threadHandles = malloc(p*sizeof(pthread_t)); 

    double start;
    double end;

    Lab1_loadinput(&A, &B, &n);

    C = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        C[i] = (int *)malloc(n * sizeof(int));
    }

    GET_TIME(start)    //Start time
    for (int thread = 0; thread < p; thread++) {
        pthread_create(&threadHandles[thread], NULL, calMatrixBlock, (void*)(intptr_t) thread);
    }


    for (int thread = 0; thread < p; thread++) {
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