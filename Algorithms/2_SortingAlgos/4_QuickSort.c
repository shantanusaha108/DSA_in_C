//QUICK SORT

#include<stdio.h>
#include<stdlib.h>

void display(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
}


//sorting in ascending order
int partition_ascending(int *arr , int low , int high){
    int pivot = arr[low];
    int i = low + 1;
    int j =  high;
    int temp;

    do{
        while (arr[i] <= pivot)
        {
            i++;//this mean incrementation of i will stop when arr[i] is greater than pivot
        }
        while (arr[j] > pivot)
        {
            j--;//this mean decrementation of j will stop when a value less than the value of pivot is found
        }
        if(i<j){ //here if still i is less than j then we swap arr[i] and arr[j]
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }while(i<j);

    //after exiting from the loop now i>j , so we swap arr[pivot] with arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;//because arr[j] is now the new pivot
}

void quickSort_ascending(int *arr , int low , int high){
    int partitionIndex;
    if(low < high){
        partitionIndex = partition_ascending(arr , low , high);
        quickSort_ascending(arr , low , partitionIndex - 1);
        quickSort_ascending(arr , partitionIndex + 1 , high);
    }
}

//sorting in descending order
int partition_descending(int *arr , int low , int high){
    int pivot = arr[high];
    int i = high - 1;
    int j =  low;
    int temp;

    do{
        while (arr[i] <= pivot)
        {
            i--;//this mean decrementation of i will stop when arr[i] is greater than pivot
        }
        while (arr[j] > pivot)
        {
            j++;//this mean incrementation of j will stop when a value less than the value of pivot is found
        }
        if(j<i){ //here if still j is less than i then we swap arr[i] and arr[j]
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }while(j<i);

    //after exiting from the loop now j>i , so we swap arr[pivot] with arr[j]
    temp = arr[high];
    arr[high] = arr[j];
    arr[j] = temp;
    return j;//because arr[j] is now the new pivote
}
void quickSort_descending(int *arr , int low , int high){
    int partitionIndex;
    if(low < high){
        partitionIndex = partition_descending(arr , low , high);
        quickSort_descending(arr , low , partitionIndex - 1);
        quickSort_descending(arr , partitionIndex + 1 , high);
    }
}



int main()
{
    int n;
    printf("Enter the size of the array : \n");
    scanf(" %d" , &n);
    int *arr=(int*)malloc(n*sizeof(int));
    int *arr2=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);
        arr2[i]=arr[i];;
    }
    printf("The original array is : ");
    display(arr,n);

    quickSort_ascending(arr,0,n-1);
    printf("The sorted array in ascending order is : ");
    display(arr,n);
    quickSort_descending(arr2,0,n-1);
    printf("The sorted array in descending order is : ");
    display(arr2,n);
    free(arr);
    free(arr2);

    return 0;
}