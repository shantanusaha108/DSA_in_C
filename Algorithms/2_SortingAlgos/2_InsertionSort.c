//INSERTION SORT

#include<stdio.h>
#include<stdlib.h>

void display(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
}

void insertion_sort_ascending(int *arr , int n){
    int key , j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; //j+1 becuz when j while loop is over j = -1 , so j+1 to make j=0 and also when it dosent enters while loop we know that j+1 = i , so the value at arr[i] is preserved
    }
    printf("The sorted array in ascending order is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
    
}

void insertion_sort_descending(int *arr , int n){
    int key , j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] < key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; //j+1 becuz when j while loop is over j = -1 , so j+1 to make j=0 and also when it dosent enters while loop we know that j+1 = i , so the value at arr[i] is preserved
    }
    printf("The sorted array in descending order is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
    
}

int main()
{
    int n;
    printf("Enter the size of the array : \n");
    scanf(" %d" , &n);
    int *arr = (int*) malloc (n*sizeof(int));
    int *arr2 = (int*) malloc (n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);\
        arr2[i]=arr[i];
    }
    printf("The original array is : ");
    display(arr,n);

    insertion_sort_ascending(arr,n);
    insertion_sort_descending(arr2,n);

    free(arr);
    free(arr2);
    return 0;
}
