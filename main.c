#include <pthread.h>
#include <math.h>

int main (int argc, char* argv[]){

    int **A, **B, **C;
    int n;
    double time;

    int numOfThreads = atoi(argv[1]);
    int numberOfBlocks = sqrt(numOfThreads);

    Lab1_loadinput(&A, &B, &n);

    int numberOfBlocks = sqrt(numOfThreads);

    for (int thread = 0; thread < numOfThreads; thread++) {
        
    }

}