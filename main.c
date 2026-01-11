#include <pthread.h>
#include <math.h>

int **A, **B, **C;
int n;
double time;

int** calMatrixBlock(int threads){

}

int main (int argc, char* argv[]){

    int numOfThreads = atoi(argv[1]);
    pthread_t* threadHandles = malloc(numOfThreads*sizeof(pthread_t)); 
    int numberOfBlocks = sqrt(numOfThreads);

    Lab1_loadinput(&A, &B, &n);

    for(int i = 0; i++; )

    int numberOfBlocks = sqrt(numOfThreads);

    for (int thread = 0; thread < numOfThreads; thread++) {
        pthread_create(&threadHandles[thread], NULL, calMatrixBlock, (void*)thread);
    }

}