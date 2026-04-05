//MERGE SORT

#include<stdio.h>
#include<stdlib.h>

void display(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d " , arr[i]);
    }
    printf("\n\n");
}

void merge(int *arr , int low , int mid , int high){
    int i = low;
    int k = low;
    int j = mid+1;
    int n = high-low + 1;
    int arr2[100];
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            arr2[k] = arr[i];
            i++;
            k++;
        }else{
            arr2[k] = arr[j];
            j++;
            k++;
        }

    }
    while(i<=mid){//for leftover elements if any in i subarray
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){//for leftover elements if any in j subarray
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i <= high; i++)//copying all the sorted elements back in the original array
    {
        arr[i] = arr2[i];
    }
    
}

void merge_sort(int *arr , int low , int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    printf("merge_sort finished with low=%d, high=%d\n", low, high);
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf(" %d" , &n);
    int *arr = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the array : " , i+1);
        scanf("%d" , &arr[i]);
    }
    printf("The original array is : \n");
    display(arr,n);
    printf("\n\n");
    merge_sort(arr,0,n-1);
    printf("The sorted array is : \n");
    display(arr,n);
    return 0;
}