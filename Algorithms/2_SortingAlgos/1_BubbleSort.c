//BUBBLE SORT

#include<stdio.h>
#include <stdlib.h>

void bubble_sort_ascending(int *arr , int n){
    int temp;
    //to make bubble sort adaptive
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //modifying bubble sort to return if the array is sorted in O(n)
                isSorted = 0;
            }
        } 
        if(isSorted) {
            break;
        }
        
    }
    printf("The sorted array in ascending order(using bubble sort) is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
    
}

void bubble_sort_descending(int *arr , int n){
    int temp;
    //to make bubble sort adaptive
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //modifying bubble sort to return if the array is sorted in O(n)
                isSorted = 0;
            }
        } 
        if(isSorted) {
            break;
        }
        
    }
    printf("The sorted array in descending order(using bubble sort) is : ");
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

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);
        arr2[i] = arr[i];
    }

    printf("The orginal array is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");

    

    bubble_sort_ascending(arr,n);
    bubble_sort_descending(arr2,n);

    free(arr);
    free(arr2);
    
    return 0;
}

