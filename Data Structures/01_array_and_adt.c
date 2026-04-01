#include<stdio.h>
#include<stdlib.h>

//creating a structure to create a array adt
typedef struct my_Array
{
    int total_size;
    int used_size;
    int *ptr;
} arr ;

//creating the array
void createArray(arr *marks , int usize , int tsize){
    marks->total_size = tsize;
    marks->used_size = usize;
    marks->ptr = (int*) malloc(tsize * sizeof(int));
}

//code for inputting values in the array
void SetValue(arr *marks){
    for (int i = 0; i < (marks->used_size); i++)
    {
        printf("Enter the %d element of the array : \n" , i + 1);
        scanf("%d" , &marks->ptr[i]);
    }
    
}

//Insertion code
void Index_Insertion(arr *marks){
    int element , index;
    printf("Enter the element to be inserted : ");
    scanf("%d" , &element);
    printf("Enter the index numbere where the element is to be inserted : ");
    scanf("%d" , &index);
    if((marks->used_size) >= (marks->total_size)){
        printf("The array is full no more storage left for insertion");
        return;
    }   
    for (int i = ((marks->used_size)-1) ; i >= index-1 ; i--)
    {
        marks->ptr[i+1] = marks->ptr[i];
    }
    marks->ptr[index-1] = element;
    marks->used_size++;
}


//Deletion code
void deletion(arr *marks){
    int index;
    printf("Enter the index number where the deletion is to be done : ");
    scanf("%d" , &index);
    if(index > marks->used_size){
        printf("Invalid index number !!!");
        return;
    }
    for (int i = index-1; i < marks->used_size ; i++)
    {
        marks->ptr[i] = marks->ptr[i+1];
    }
    marks->used_size--;
    
}

//Traversal code to display the array
void show(arr *marks){
    for (int i = 0; i < (marks->used_size); i++)
    {
        printf("The %d element is %d\n" ,i+1 , (marks->ptr)[i]);
    }
    
}

//Search code to fetch a particular element from the array
void get_elem(arr *marks){
    int y , i , m;
    printf("\nEnter the 0 if u want to search by index no.\nEnter 1 if u want to search by entering the element\n");
    scanf("%d" , &y);
    if(!y){//if y=0 dat means false but not false means true so it will enter the if block and if y=1 that means true but mot true means false so it will not enter the if block
        printf("Enter the index number : ");
        scanf("%d" , &i);
        if(i > marks->total_size){
            printf("Invalid input!!");
            exit(0);
        }
        printf("The element at index[%d] is %d\n" , i , marks->ptr[i-1]);
    }else if(y=1){ 
        printf("Enter the element u want to search for : ");
        scanf("%d" , &m);
        int found = 0;
        for (int i = 0; i < marks->used_size; i++)
        {
            if(m==marks->ptr[i]){
                printf("The entered element , %d was found at index[%d]\n" , m , i+1);
                found = 1;
            }
        }
        if(!found){//same as the above condition
            printf("Entered element is not present in the array!!!");
        }
        
    }
}



int main()
{
    int d;
    arr marks;
    createArray(&marks,5 ,20);
    label:
    printf("\nFollow the instructions below : \n1> Enter 1 if u want to set values in the array.\n2> Enter 2 if u want to display the array.\n3> Enter 3 if u want to insert elements in the array.\n4> Enter 4 if you want to delete elements from the array.\n5> Enter 5 if u want to search for element in the array or the index number of a element\n6> Press 0 to exit from the program\n");
    scanf("%d" , &d);
    
    if(d==1){
        printf("\n");
        SetValue(&marks);
    }else if(d==2){
        printf("\n");
        show(&marks);
    }else if(d==3){
        printf("\n");
        Index_Insertion(&marks);
    }else if(d==4){
        printf("\n");
        deletion(&marks);
    }else if(d==5){
        printf("\n");
        get_elem(&marks);
    }else if(d==0){
        printf("\n");
        goto end;
    }
    goto label;
    end:
    printf("\n"); 
    return 0;
}