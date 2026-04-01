//TRAVERSAL , INSERTION AND DELETION OPEATION IN A CIRCULAR LINKED LIST


#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}n;

void LinkedListTraversal(n*first){
    int a = 1 ;
    n *ptr = first;
    do{
        printf("Element %d in the Linked List is : %d\n" , a , ptr->data);
        ptr = ptr->next;
        a++;
    }while(ptr != first);
    printf("\n");
}


//Insertion operation's code begins
n *InsertionAtBegining(n*head){ //this function return data and a pointer
    int f;
    printf("Enter the data that is to be inserted at the begining of the linked list : \n");
    scanf(" %d" , &f);
    n *ptr = (n*) malloc(sizeof(n));
    ptr->data = f;
    ptr->next = head;
    n* lastNode = head;
    while(lastNode->next != head){
        lastNode = lastNode->next;
    }
    lastNode->next = ptr;
    return ptr;
}

n *InsertionInBetween(n*first){
    int index , data;
    printf("Enter the index where u want to create a new node : ");
    scanf("%d" , &index);
    printf("Enter the data which u want to input in the newly created node : ");
    scanf("%d" , &data);

    n *ptr = (n*) malloc (sizeof(n));
    ptr->data = data;
    n *p = first;

    int i = 1;
    while(i < (index-1)){ //index-1 beacause we need p to point the element present before the index no where we want to create a new node
        // if(p->next = p){
        //     printf("The index entered dosent exist in the list.\n\n");
        //     return first;
        // }
        p = p->next;//the address of the next node gets stored in p continuously
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return first;


}

n *InsertionAtEnd(n*first){
    int value;
    printf("Enter the value that is to be inserted at the end of the Linked List : ");
    scanf(" %d" , &value);
    n *ptr = (n*) malloc(sizeof(n));
    ptr->data = value;
    n *p = first;
    while ( p->next != first )
    {
        p = p->next;
    }
    ptr->next = first;
    p->next = ptr;
    return first;
}

n*IndentiyingNode(n*first){
    int index;
    printf("Enter the index number of the node after which u want to insert : ");
    scanf(" %d" , &index);
    n*ptr = first;
    int i = 1;
    while(i < index && ptr->next != first){
        ptr = ptr->next;
        i++;
    }

    //code to display error if invalid index is given
    if(index+1 > i+2){
        printf("That index dosen't exits in the list.\n\n");
        return first;
    }

    return ptr;
}
n *InsertionAfterANode(n*first , n*prevNode){
    int value;
    printf("Enter the value to be inserted : ");
    scanf(" %d" , &value);
    n *ptr = (n*) malloc(sizeof(n));
    ptr->data = value;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return first;
}
//Insertion operation's code ends


//Deletion operation's code begins
n *DeletingTheFirstNode(n*first){
    n *p = first;
    while(p->next != first){
        p = p->next;
    }
    //p->next points to first/head node
    p->next = first->next;
    n *ptr = first;
    first = first->next;//the second node now becomes the head
    free(ptr);
    return first;
}

n *DeletingNodeAtAIndex(n*first){
    int index;
    printf("Enter the index where u want to delete a node : ");
    scanf("%d" , &index);

    n *p = first;
    n *q = first->next;
    int i = 1;
    while(i < index-1 && p != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    

    //code to display error if invalid index is given
    if(index+1 > i+2){
        printf("That index dosen't exits in the list.\n\n");
        return first;
    }
    p->next = q->next;
    free(q);
    return first;
}

n *DeletingLastNode(n*first){
    n *p = first; 
    n *ptr = first; 
    while (p->next != first)
    {
        p = p->next;
    }
    while(ptr->next != p){
        ptr = ptr->next;
    }
    ptr->next = first;
    free(p);
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
        return first;
    }
    
    n *p = first;
    n *ptr = first->next;
    while(ptr->data != value && p->next != first){
        p = p->next;
        ptr = ptr->next;
    }
    if(p->next == first){
        printf("There is no node in the list with the given value.\n\n");
    }
    p->next = ptr->next;
    free(ptr);
    return first;
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
    eighth->next = first;
    
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
            n *p = IndentiyingNode(first);
            first = InsertionAfterANode(first , p);
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