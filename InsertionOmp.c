#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Asiz 200
long int arr[Asiz];
long int arr_sort[Asiz];
void insertionsort(long int vetor[], int siz)
{
    int i, j, key;

    #pragma omp parallel for shared (vetor, siz, key) private (i,j) ordered
    for(i = 1; i < siz; i++)
    {
        j = i;

      #pragma omp ordered
       {
        while(j > 0 && vetor[j-1] > vetor[j])
        {

            key = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = key;
            j--;
        }
       }
    }

}
void merge(int begin,int mid,int end) {


    int i = begin, j = mid, tpos = begin;

    while (i<mid&&j<=end)
    {
        if (arr[i]<arr[j])
            arr_sort[tpos++]= arr[i++];
        else
            arr_sort[tpos++]= arr[j++];
    }

    while (i<mid)
        arr_sort[tpos++] = arr[i++];
    while (j<=end)
        arr_sort[tpos++] = arr[j++];
}
int main()
{
	srand(time(0));
	omp_set_num_threads(4);
	int i;
    #pragma omp parallel private(i) num_threads(4)
    {
    #pragma omp for
    for(i =0 ;i<Asiz;i++)
	{
		arr[i]=rand()%100000;
	}
	}
	insertionsort(arr,Asiz);
    for(i =0 ;i<Asiz;i++)
	{
		printf("  %ld  ",arr[i]);
	}
}