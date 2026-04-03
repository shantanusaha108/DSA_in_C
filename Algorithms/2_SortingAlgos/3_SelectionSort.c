//SELECTION SORT


#include<stdio.h>
#include<stdlib.h>

void display(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");
}

void SelectionSort_ascending(int *arr , int n){
    int minIndex , temp;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;  
    }
    printf("The sorted array in ascending form is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ," , arr[i]);
    }
    printf("\n");  
}

void SelectionSort_descending(int *arr , int n){
    int maxIndex , temp;
    for (int i = 0; i < n; i++)
    {
        maxIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
            
        }
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp; 
    }
    printf("The sorted array in descending form is : ");
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
    int *arr = (int*)malloc(n*sizeof(int));
    int *arr2 = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);
        arr2[i]=arr[i];
    }
    printf("The original array is : ");
    display(arr,n);
    SelectionSort_ascending(arr,n);
    SelectionSort_descending(arr2,n);
    free(arr);
    free(arr2);
    return 0;
}