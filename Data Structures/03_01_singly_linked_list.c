//CREATON AND TAVERSAL OF A LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// code for creating a node begins
typedef struct Node
{
    int data;
    struct Node *next; // self refering structure
    // this is a pointer as we create int *p or char *p in this case as we need a structure pointer beacause we gonna be ponting at nodes that are of same type of structure therefore we need to create a pointer as the same type as the structure

} n;
// code for creating a node ends

void LinkedListTraversal(n *ptr)
{
    int n = 1; 
    while (ptr != NULL)
    {
        printf("%d Element is : %d\n", n , ptr->data); // prints the value of ptr->data
        ptr = ptr->next;           // the address to the next node gets stored in ptr
        //remeber ptr is a pointer that stores address of elements so ptr->data mean the data that is at the address stored in ptr 
        n++;
    }
}

int main()
{
    n *first = (n *)malloc(sizeof(n));
    n *second = (n *)malloc(sizeof(n));
    n *third = (n *)malloc(sizeof(n));
    n *fourth = (n *)malloc(sizeof(n));
    n *fifth = (n *)malloc(sizeof(n));

    first->data = 7;
    first->next = second;

    second->data = 43;
    second->next = third;

    third->data = 78;
    third->next = fourth;

    fourth->next = fifth;
    fourth->data = 433;

    fifth->data = 956;
    fifth->next = NULL;

    LinkedListTraversal(first); 
    return 0;
}






//INSERTION AND DELETION OPEATION IN A LINKED LIST


#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}n;

void LinkedListTraversal(n*first){
    int a = 1 ;
    while(first != NULL){
        printf("Element %d in the Linked List is : %d\n" , a , first->data);
        first = first->next;
        a++;
    }
    printf("\n");
}
//while (first != NULL):
//This condition is used to traverse the linked list and perform an operation on each node. The loop continues as long as the current pointer is not pointing to NULL, which means there are still nodes left in the linked list to process. In other words, the loop iterates through each node in the linked list, including the last node (where current is NULL).


//Insertion operation's code begins
n *InsertionAtBegining(n*head){ //this function return data and a pointer
    int f;
    printf("Enter the data that is to be inserted at the begining of the linked list : \n");
    scanf(" %d" , &f);
    n *ptr = (n*) malloc(sizeof(n));
    ptr->data = f;
    ptr->next = head;
    return ptr;
}

n *InsertionInBetween(n*first){
    int index , data;
    printf("Enter the index where u want to create a new node : ");
    scanf("%d" , &index);
    printf("Enter the data which u want to input in the newly created node : ");
    scanf("%d" , &data);
    n *ptr = (n*) malloc (sizeof(n));
    n *p = first;

    int i = 1;
    while(i < (index-1)){ //index-1 beacause we need p to point the element present before the index no where we want to create a new node
        p = p->next;//the address of the next node gets stored in p continuously
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

n *InsertionAtEnd(n*first){
    int value;
    printf("Enter the value that is to be inserted at the end of the Linked List : ");
    scanf(" %d" , &value);
    n *ptr = (n*) malloc(sizeof(n));
    n *p = first;
    while ( p->next != NULL )
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = value;
    ptr->next = NULL;
    return first;
}
//while (p->next != NULL):
//This condition is often used when iterating through the linked list to perform an operation on the second-to-last node or to stop at the last node. The loop continues as long as the current->next pointer is not pointing to NULL, which means there is at least one more node after the current node. The loop stops before reaching the last node, as the last node's next pointer is NULL.

n*IndentiyingNode(n*first){
    int index;
    printf("Enter the index number of the node after which u want to insert : ");
    scanf(" %d" , &index);
    n*ptr = first;
    int i = 1;
    while(i < index-1){
        ptr = ptr->next;
        i++;
    }
    return ptr;
}
n *InsertionAfterANode(n*first){
    n *ftr = IndentiyingNode(first);
    int value;
    printf("Enter the value to be inserted : ");
    scanf(" %d" , &value);
    n *ptr = (n*) malloc(sizeof(n));
    ptr->data = value;
    ptr->next = ftr->next;
    ftr->next = ptr;
    return first;
}
//Insertion operation's code ends


//Deletion operation's code begins
n *DeletingTheFirstNode(n*first){
    n *ptr = first;
    first = first->next;
    free(ptr);
    return first;
}

n *DeletingNodeAtAIndex(n*first){
    int index;
    printf("Enter the index number of the node to be deleted : ");
    scanf(" %d" , &index);
    n *p = first; 
    n *ptr = first->next; 
    for (int i = 1; i < index-1; i++)
    {
        p = p->next;
        ptr = ptr->next;
    }
    
    p->next = ptr->next;
    free(ptr);
    return first;
}

n *DeletingLastNode(n*first){
    n *p = first; 
    n *ptr = first->next; 
    while (ptr->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return first;
}

n *DeleteNodeWithSpecificValue(n*first){
    int value;
    printf("Enter the value u want to be deleted (Note: Only the first node with the same value will be deleted) : ");
    scanf(" %d" , &value);

    //code to delete the first element if the given value is in it
    if(first->data == value){
        n *ftr = first;
        first = ftr->next;
        free(ftr);
    }
    
    n *p = first;
    n *ptr = first->next;
    while(ptr->data != value && ptr->next != NULL){
        p = p->next;
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        printf("There is no node in the list with the given value.\n\n");
        return;
    }
    else{
        p->next = ptr->next;
        free(ptr);
        return first;
    }
}
//Deletion operation's code ends

int main()
{
    n *first = (n*) malloc(sizeof(n));   
    n *second = (n*) malloc(sizeof(n));
    n *third = (n*) malloc(sizeof(n));
    n *fourth = (n*) malloc(sizeof(n));
    n *fifth = (n*) malloc(sizeof(n));
    n *sixth = (n*) malloc(sizeof(n));
    n *seventh = (n*) malloc(sizeof(n));
    n *eighth = (n*) malloc(sizeof(n));

    first->data = 7;
    first->next = second;

    second->data = 32;
    second->next = third;

    third->data = 323;
    third->next = fourth;

    fourth->data = 23;
    fourth->next = fifth;

    fifth->data = 345;
    fifth->next = sixth;

    sixth->data = 67;
    sixth->next = seventh;

    seventh->data = 56;
    seventh->next = eighth;

    eighth->data = 45;
    eighth->next = NULL;
    
    int dec;
    while (dec != 0)
    {
        printf("Follow the following instructions : \n1> Enter 0 to exit from the program.\n2> Enter 1 to display the Linked List.\n3> Enter 2 for insertion at the begining of the Linked List.\n4> Enter 3 for insertion at the middle of the linked list.\n5> Enter 4 for insertion at the end of the Linked List.\n6> Enter 5 for insertion after a node of the Linked List.\n7> Enter 6 to delete the first node from the program.\n8> Enter 7 to delete the node at a present specific index\n9> Enter 8 to delete the last node.\n10> Enter 9 to delete a node with a specific value.\n");
        scanf(" %d" , &dec);


        if(dec==0){
            break;
        }
        if(dec==1){
            LinkedListTraversal(first);
        }
        if(dec==2){
            first = InsertionAtBegining(first);
        }
        if(dec==3){
            first = InsertionInBetween(first);
        }
        if(dec==4){
            first = InsertionAtEnd(first);
        }
        if(dec==5){
            first = InsertionAfterANode(first);
        }
         if(dec==6){
            first =DeletingTheFirstNode(first);
        } 
        if(dec==7){
            first =DeletingNodeAtAIndex(first);
        }
        if(dec == 8){
            first = DeletingLastNode(first);
        }
        if(dec == 9){
            first = DeleteNodeWithSpecificValue(first);
        }
    }
    
    return 0;
}