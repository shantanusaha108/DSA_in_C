#include<stdio.h>

void linear_search(int *arr , int n){
    int element;
    printf("Eneter the element to be searched : ");
    scanf("%d" , &element);
    for (int i = 0; i < n ; i++)
    {
        if(arr[i] == element){
            printf("The %d element in found at index %d" , element , i+1);
            return;
        }
    }
    printf("The specified element that is %d is not present in the array." , element);
    
}

void binary_search(int *arr , int n){
    int element;
    printf("Enter the element to be searched for : ");
    scanf("%d" , &element);
    int low = 0 , mid , high = n-1;
    while(low<=high){
        mid = (low+high)/2;
        
        //code to look if character is present in low , mid or high begins
        // if(arr[low] == element){
        //     printf("The specified element that is %d is found at index[%d] \n" , element , low+1);
        //     return;
        // }
        // if(arr[high] == element){
        //     printf("The specified element that is %d is found at index[%d] \n" , element , high+1);
        //     return;
        // }  
        if(arr[mid] == element){
            printf("The specified element that is %d is found at index[%d] \n" , element , mid+1);
            return;
        }
        //code to look if character is present in low , mid or high ends
        
        //code for specifing actions when the element is not present in low , mid or high and what to do if its greater than or less the value at mid
        if(arr[mid] < element){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    printf("The specified element that is %d is not present in the array." , element);
}



//code with harry binary search code
// int binarySearch(int arr[], int size, int element){
//     int low, mid, high;
//     low = 0;
//     high = size-1;
//     // Keep searching until low <= high
//     while(low<=high){
//         mid = (low + high)/2;
//         if(arr[mid] == element){
//             return mid;
//         }
//         if(arr[mid]<element){
//             low = mid+1;
//         }
//         else{
//             high = mid -1;
//         }
//     } 
//     return -1;
    
// }

// The first binary search code has some redundant code to check if the element is present at low or high indices, which may increase the number of comparisons made during the search. On the other hand, the second binary search code is more concise and optimized, and does not have any such redundant code.

// Therefore, the second binary search code may be slightly faster than the first one, but the difference in performance may not be significant.



int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d" , &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the array : \n" , i+1);
        scanf("%d" , &arr[i]);
    }
    char ch;
    printf("Follow the instructions below : \n1> Enter \"L/l\" for linear search , and\n2>Enter \"B/b\" for binary search.\n");
    scanf(" %c" , &ch);
    //The issue with the code is that when the user enters the size of the array, the newline character ('\n') is still in the input buffer, so when the program tries to read the character for the search method, it reads the newline character instead of the intended input.
    //solutions : 
    //1>> To fix this, we need to add a space before the %c format specifier in the scanf function to consume the newline character:
    //2>> Or we can simply write a fflush(stdin); before the scanf function.

    if(ch=='L' || ch=='l'){
        linear_search(arr,n);
    }else if(ch== 'B' || ch=='b'){
        printf("Note : For binary search the array must be sorted.\n");
        binary_search(arr,n);
    }

    
    return 0;
}