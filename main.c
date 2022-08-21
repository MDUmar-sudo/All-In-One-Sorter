#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max(x,y) (x>y)?x:y

void BubbleSort();
void InsertionSort();
void SelectionSort();
void QuickSort();
void MergeSort();
void CountSort();
void printArray();

//global variables
int arr[];

int main()

{
    int choice,n;
    printf("_______________________________________\n");
    printf("ULTIMATE SORTING PROGRAM\n");
    printf("_______________________________________\n");

    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);
    printf("\nENTER THE ELEMENTS IN ARRAY : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("----------------------------------\n");
    printf("PLEASE SELECT A SORTING ALGORITHM\n");
    printf("\n(1)BUBBLE SORT\n(2)INSERTION SORT\n(3)SELECTION SORT\n(4)QUICK SORT\n(5)MERGE SORT\n(6)COUTNING SORT\n(0)EXIT\n");
    printf("----------------------------------\n");


    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

   switch(choice)
    {
      case 1:   printf("\nrunning bubble sort......\n");
                BubbleSort(arr,n);
                printf("\nARRAY AFTER BUBBLE SORT: ");
                printArray(arr,n);
                break;


      case 2:   printf("\nrunning insertion sort......\n");
                InsertionSort(arr,n);
                printf("\nARRAY AFTER INSERTION SORT : ");
                printArray(arr,n);
                break;

      case 3:   printf("\nrunning selection sort......\n");
                SelectionSort(arr,n);
                printf("\nARRAY AFTER SELECTION SORT : ");
                printArray(arr,n);
                break;

      case 4:   printf("\nrunning quick sort......\n");
                QuickSort(arr,0,n-1);
                printf("\nARRAY AFTER QUICK SORT : ");
                printArray(arr,n);
                break;

      case 5:   printf("\nrunning merge sort......\n");
                MergeSort(arr,0,n-1);
                printf("\nARRAY AFTER MERGE SORT : ");
                printArray(arr,n);
                break;

      case 6:   printf("\nrunning counting sort......\n");
                CountSort(arr,n);
                printf("\nARRAY AFTER COUNTING SORT : ");
                printArray(arr,n);
                break;

     case 0: exit(1);

     default : printf("INVALID CHOICE!!\nEXITING....\n\n");

    }


    getch();
    return 0;
}

//function to print array

void printArray(int arr[],int size){
    for(int i=0;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
}

//swaps two elements in array

void swap(int *x ,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Partition function for quick sort algorithm

int partition(int arr[],int low,int high)
{

    int pivot=arr[low]; //first element of array taken as pivot element
    int i = low+1,j=high;

    do
    {
        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<j)
         {
            swap(&arr[j],&arr[i]);

         }

    }while(i<j);

    swap(&arr[low],&arr[j]);
    return j;

}

//Merging function for merging sub-arrays in merge sort algorithm

void mergeArrays(int arr[],int low,int mid,int high){
    int temp[50];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}

//Bubble sort function,made adaptive

void BubbleSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int isSorted=0;
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                isSorted=1;
            }
        }
        if(isSorted==0)
            return;
    }
}


//Insertion sort function

void InsertionSort(int arr[],int size)
{
    int key;
    for(int i=1;i<size;i++)
    {
       key = arr[i];
       int j=i-1;
       while(j>=0 && arr[j]>key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
    }
}


//Selection sort function

void SelectionSort(int arr[],int size)
{
    int min_index;
    for(int i=0;i<size-1;i++){ //n-1 passes required to sort the array
        min_index = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }

        swap(&arr[i],&arr[min_index]);
    }
}


//Quick sort function

void QuickSort(int arr[],int low,int high)
{
 if(low<high)
 {
     int partitionPoint = partition(arr,low,high);
     QuickSort(arr,low,partitionPoint-1);
     QuickSort(arr,partitionPoint+1,high);

 }

}

//Merge sort function

void MergeSort(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;

        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        mergeArrays(arr,low,mid,high);
    }
}

//Counting sort function

void CountSort(int arr[],int size){

    int max_element=INT_MIN;
    for(int i=0;i<size;i++){
        max_element=max(max_element,arr[i]);
    }

    int k = max_element+1;
    int count_arr[k];
    memset(count_arr, 0, sizeof(count_arr)); //initialized count_arr elements to zero

    for(int i=0;i<size;i++){
        count_arr[arr[i]]++;
    }

    int i=0,j=0;
    while(i<k){
        if(count_arr[i]>0){
            arr[j]=i;
            --count_arr[i];
            j++;
        }
        else i++;

    }

}
