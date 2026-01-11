#include <pthread.h>
#include <math.h>

int **A, **B, **C;
int n;
int p;

int** calMatrixBlock(int thread){

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

}

int main (int argc, char* argv[]){

    p = atoi(argv[1]);
    pthread_t* threadHandles = malloc(p*sizeof(pthread_t)); 
    int numberOfBlocks = sqrt(p);

    Lab1_loadinput(&A, &B, &n);

    for(int i = 0; i++; )

    int numberOfBlocks = sqrt(p);

    for (int thread = 0; thread < p; thread++) {
        pthread_create(&threadHandles[thread], NULL, calMatrixBlock, (void*)thread);
    }

}