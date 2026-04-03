//SELECTION SORT


#include<stdio.h>

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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);
    }
    printf("The original array is : ");
    display(arr,n);
    SelectionSort_ascending(arr,n);
    SelectionSort_descending(arr,n);
    return 0;
}







//QUICK SORT

#include<stdio.h>

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
    return j;//because arr[j] is now the new pivote
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the list : " , i+1);
        scanf(" %d" , &arr[i]);
    }
    printf("The original array is : ");
    display(arr,n);

    quickSort_ascending(arr,0,n-1);
    printf("The sorted array in ascending order is : ");
    display(arr,n);
    quickSort_descending(arr,0,n-1);
    printf("The sorted array in descending order is : ");
    display(arr,n);

    return 0;
}









// //MERGE SORT

//my code
// #include<stdio.h>
// #include<stdlib.h>

// void display(int *arr , int n){
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d " , arr[i]);
//     }
//     printf("\n\n");
// }

// void merge(int *arr , int low , int mid , int high){
//     int i = low;
//     int k = low;
//     int j = mid+1;
//     int n = high-low + 1;
//     int arr2[n];
//     while(i<=mid && j<=high){
//         if(arr[i] < arr[j]){
//             arr2[k] = arr[i];
//             i++;
//             k++;
//         }else{
//             arr2[k] = arr[j];
//             j++;
//             k++;
//         }

//     }
//     while(i<=mid){//for leftover elements if any in i subarray
//         arr2[k] = arr[i];
//         i++;
//         k++;
//     }
//     while(j<=high){//for leftover elements if any in j subarray
//         arr2[k] = arr[j];
//         j++;
//         k++;
//     }
//     for (int i = 0; i <= high; i++)//copying all the sorted elements back in the original array
//     {
//         arr[i] = arr2[i];
//     }
    
// }

// void merge_sort(int *arr , int low , int high){
//     int mid;
//     if(low<high){
//         mid = (low+high)/2;
//         merge_sort(arr,low,mid);
//         merge_sort(arr,mid+1,high);
//         merge(arr,low,mid,high);
//     }
//     printf("merge_sort finished with low=%d, high=%d\n", low, high);
// }

// int main()
// {
//     int n;
//     printf("Enter the size of the array : ");
//     scanf(" %d" , &n);
//     int *arr = (int*) malloc (n * sizeof(int));
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter the %d element of the array : " , i+1);
//         scanf("%d" , &arr[i]);
//     }
//     printf("The original array is : \n");
//     display(arr,n);
//     printf("\n\n");
//     merge_sort(arr,0,n-1);
//     printf("The sorted array is : \n");
//     display(arr,n);
//     return 0;
// }


//code with harry code
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}









//COUNT SORT


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d " , arr[i]);
    }
    printf("\n\n");
}

int max_value(int *arr , int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
    
}

void countSort(int *arr , int n){
    int max = max_value(arr,n);
    int *count_arr = (int*) malloc ((max+1) * sizeof(int) );
    for (int i = 0; i <= max; i++)
    {
        count_arr[i] = 0;//initializez the  value of every index in count_arr to 0
    }

    for (int i = 0; i < n ; i++)
    {
        count_arr[arr[i]] = count_arr[arr[i]] + 1; //here the index of count_arr is given by the value present at arr[i] , thats why we write i<n
    }
    int i = 0;
    int j = 0;
    while(i<=max){
        if(count_arr[i]>0){
            arr[j] = i;
            count_arr[i] = count_arr[i] - 1;
            j++;
        }else{
            i++;
        }
    }
    
}

int main()
{
    int n;
    printf("Enter the sie of the array : ");
    scanf("%d" , &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the array : ");
        scanf("%d" , &arr[i]);
    }
    printf("The original array is : ");
    printArray(arr,n);
    countSort(arr,n);
    printf("The sorted array is : ");
    printArray(arr,n);

    return 0;
}
     







//  SHELL SORT



#include<stdio.h>
#include<stdlib.h>

void display(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d " , arr[i]);
    }
    printf("\n\n");
}

void shellSort(int *arr , int n){

    //first loop runs for n/2 - 1 times from n/2 to n=1
    for (int interval = n/2 ; interval > 0 ; interval /= 2)
    {
        //second loop also runs for n/2 - 1 times but from n/2 to n-1
        for (int i = interval; i < n; i++)
        {
            //we store the value of the element present at n/2 pos away from the element to be compared in temp
            int temp = arr[i];
            int j;
            //third loop travels in backward direction from the swaped element to compare it with the elements before it
            for (j = i; j >= interval && arr[j-interval] > temp ; j -= interval )
            {
                arr[j] = arr[j - interval];
            }
            //now j points to the index from where the greater element was swaped but this index still contains the same element therefore to swap the element present with the smaller element we write this line and if no swapped happened then the original value of arr[j] will remain the same
            arr[j] = temp;
        }
        
    }
    
}

void shellSort_descending(int *arr , int n){

    //first loop runs for n/2 - 1 times from n/2 to n=1
    for (int interval = n/2 ; interval > 0 ; interval /= 2)
    {
        //second loop also runs for n/2 - 1 times but from n/2 to n-1
        for (int i = interval; i < n; i++)
        {
            //we store the value of the element present at n/2 pos away from the element to be compared in temp
            int temp = arr[i];
            int j;
            //third loop travels in backward direction from the swaped element to compare it with the elements before it
            for (j = i; j >= interval && arr[j-interval] < temp ; j -= interval )
            {
                arr[j] = arr[j - interval];
            }
            //now j points to the index from where the greater element was swaped but this index still contains the same element therefore to swap the element present with the smaller element we write this line and if no swapped happened then the original value of arr[j] will remain the same
            arr[j] = temp;
        }
        
    }
    
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d" , &n );
    int *arr = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
        printf("Enter the %dst element of the array : " , i+1);
        scanf("%d" , &arr[i]);
        }
        else if (i == 1)
        {
            printf("Enter the %dnd element of the array : " , i+1);
            scanf("%d" , &arr[i]);
        }
        else if (i == 2)
        {
            printf("Enter the %drd element of the array : " , i+1);
            scanf("%d" , &arr[i]);
        }
        else
        {
            printf("Enter the %dth element of the array : " , i+1);
            scanf("%d" , &arr[i]);
        }
        
        
        
    }
    printf("The original array : \n");
    display(arr,n);
    shellSort(arr,n);
    printf("The sorted array (ascending order) : \n");
    display(arr,n);
    shellSort_descending(arr,n);
    printf("The sorted array (descending order) : \n");
    display(arr,n);
    return 0;
}