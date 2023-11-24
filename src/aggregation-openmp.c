
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

int N = 64; // The size of the array must be a power of 2
int n = 4; // The number of potential threads must divide N

void initTab(int* T){

    for(int i = 0; i < N; i++){
        T[i] = i;
    }
} // initTab

void printTab(int* T){

    for(int i = 0; i < N; i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");
} // printTab

int sumTabSeq(int* T){

    int sum = 0;

    for(int i = 0; i < N; i++){
        sum += T[i];
    }
    return(sum);
} // data aggregation (sum)


int sumTabPar(int *T)
{
    for(int i = 0; i < n; i++){
        int rootIndex = (i * N/n);
        for (int j = 1; j < N/n; j++){
            T[rootIndex] += T[rootIndex + j];
        }
    }

    printf("T before final aggregation: ");
    printTab(T);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += T[i * (N/n)];
    }

    return(sum);
}

int sumTabParOpenMp(int *T){

    // To be implemented
    return(0);
}

int main(int argc,char *argv[])
{

    int *T = (int *)malloc(N * sizeof(int));
    initTab(T);
    printTab(T);

    printf("\n=== SUM - Sequential version ===\n");
    printf("Sum of elements of T: %d\n", sumTabSeq(T));

    initTab(T);
    printf("\n=== SUM - Parallel version 1 ===\n");
    printf("Sum of elements of T: %d\n", sumTabPar(T));

    initTab(T);
    printf("\n=== SUM - Parallel Open MP version ===\n");
    printf("Sum of elements of T: %d\n", sumTabParOpenMp(T));

}

