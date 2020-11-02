#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define Asiz 100000
long int arr[Asiz];
long int arr_sort[Asiz];
typedef struct Arguments_for_threading{
    int str;
    int mid;
    int end;
}args;
void* merge(void *args);
void* insertionSort(void *args);
int main() {
	srand(time(0));
	int i;
    for(i =0 ;i<Asiz;i++)
	{
		arr[i]=rand();
	}
    int str1,str2,str3,str4;
    int end1,end2,end3,end4;
    str1=0;
    end1=Asiz*0.25-1;
    str2=end1+1;
    end2=Asiz*0.5-1;
    str3=end2+1;
    end3=Asiz*0.75-1;
    str4 = end3+1;
    end4=Asiz-1;
    pthread_t threads[5];
    args TA1[5];
    TA1[0].str = str1;
    TA1[0].end = end1;
    pthread_create(&threads[0], NULL, insertionSort, &TA1[0]);

    TA1[1].str = str2;
    TA1[1].end = end2;
    pthread_create(&threads[1], NULL, insertionSort, &TA1[1]);
    
    TA1[2].str = str3;
    TA1[2].end = end3;
    pthread_create(&threads[2], NULL, insertionSort, &TA1[2]);
	TA1[3].str = str4;
    TA1[3].end = end4;
    pthread_create(&threads[3], NULL, insertionSort, &TA1[3]);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);
    TA1[4].str = str1;
    TA1[4].mid = str1;
    TA1[4].end = end4;
    pthread_create(&threads[4], NULL, merge, &TA1[4]);
    pthread_join(threads[4], NULL);
//	for(i=0;i<Asiz;i++)
//	{
//		printf(" %d ",arr_sort[i]);
//	}
	printf("Array Sorted succesfully using Pthreads");
    return 0;
}
void* merge(void *arguments) {
    args *params = (args*) arguments;
    int begin = params->str,
        mid = params->mid,
        end = params->end;


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
void* insertionSort(void *arguments)
{
    args *TA2 = (args*) arguments;
    int str = TA2->str,
    end = TA2->end;

    int i = str;
	int key,j;
	for (i =str; i<=end; i++) 
   { 
       key = arr[i]; 
       j = i-1;
       while (j >=0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j--; 
       }
      arr[j+1]= key;
   } 
}
