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