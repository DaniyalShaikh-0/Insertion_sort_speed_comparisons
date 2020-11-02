#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
using namespace std;
#define size1 80
void insertionsort(int arr[],int size)
{
	int i, key, j;int count=0;
   for (i = 1; i<size; i++) 
   { 
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j--; 
       }
      arr[j+1] = key;
   } 

}
int arr[size1];
int main()
{
   int i;
   srand(time(NULL));
   for (i=0; i<size1; i++)
       arr[i] = rand() % 100994;
	insertionsort(arr,size1);
	cout<<"\n\n\nSorted Array unthreaded :  ";
	for(int i=0;i<size1;i++)
	{
      cout<<arr[i]<<"\t";
	}
}
