//craetion of a queue and basics methods using array


#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int insert_end;
    int delete_end;
    int size;
    int *arr;
} queue ;

void display(queue *a){
    printf("The elements in the queue are : ");
    for (int i = a->delete_end; i <= a->insert_end; i++)
    {
        printf(" %d " , a->arr[i]);
    }
    printf("\n\n");
}


void enqueue(queue *a){
    int value;
    printf("Enter the value to be inserted in the loop : ");
    scanf(" %d" , &value);
    if(a->insert_end == a->size-1){
        printf("Queue is full , cant insert %d , dequeue elemets to inserts more elements.\n\n" , value);
    }else{
        a->insert_end++;
        a->arr[a->insert_end] = value;
    }
}

//this dequeue shifts the element towards the frm of the quess rather than incrementing delete_end b 1.
// void dequeue(queue *a){
//     if(a->insert_end == -1){
//         printf("Queue is empty , no elements to dequeue.\n\n");
//         return;
//     }else{
//         int ch;
//         ch = a->arr[a->delete_end];
//         printf("%d dequeued from the queue.\n" , ch);
//         for (int i = 0; i <= a->insert_end ; i++)
//         {
//             a->arr[i] = a->arr[i+1];
//         }
//         a->insert_end--;
        
//     }
// }

void dequeue(queue *a){
    if(a->delete_end >= a->insert_end + 1){
        printf("Queue is empty , no elements to dequeue.\n\n");
        return;
    }else{
        printf("%d dequeued from the queue.\n\n" , a->arr[a->delete_end]);
        a->delete_end++;
        
    }
}


void firstVal(queue *a){
    printf("The first value of the queue is %d" , a->arr[a->delete_end]);
}
void lastVal(queue *a){
    printf("The last value of the queue is %d" , a->arr[a->insert_end]);
}
void peek(queue *a){
    int index;
    printf("Specify the index number of the element u want to check : ");
    scanf(" %d" , &index);
    if(index-1 > a->size)
    {
        printf("Invalid index!!!!!\n\n");
        return;
    }
    else if(index-1 < a->delete_end || index-1 > a->insert_end){
        printf("No element is present at that index!!!!\n\n");
        return;
    }
    else{
        printf("The element present at index[%d] is %d" , index , a->arr[index-1]);
    }
}

void isFull(queue *a){
    if(a->insert_end == a->size-1){
        printf("The queue is full!\n\n");
        return;
    }else{
        printf("The queue is not full.\n\n");
    }
}
void isEmpty(queue *a){
    if(a->insert_end == -1 || a->delete_end >= a->insert_end){
        printf("The queue is empty!\n\n");
        return;
    }else{
        printf("The queue is not empty.\n\n");
    }
}
int main()
{
    int n;
    printf("Enter the size of the queue : ");
    scanf(" %d" , &n);

    //queue creation
    queue *a = (queue*) malloc (sizeof(queue));
    a->insert_end = -1;
    a->delete_end = 0;
    a->size = n;
    a->arr = (int*) malloc (a->size * sizeof(int));

    int dec ;
    while (dec != 0)
    {
        printf("1> Enter 0 to exit.\n2> Enter 1 to display the queue.\n3> Enter 2 to enqueue elements in the queue.\n4> Enter 3 to dequeue the first element.\n5> Enter 4 to check the first value of the queue.\n6> Enter 5 to check the last value of the queue.\n7> Enter 6 to check the value present at a specfic function.\n8> Enter 7 to check the status of the queue.\n");
        scanf(" %d" , &dec);

        if(dec == 0){
            exit(0);
        }
        else if (dec==1)
        {
            display(a);
        }
        else if (dec==2)
        {
            enqueue(a);
        }
        else if (dec==3)
        {
            dequeue(a);
        }
         else if (dec==4)
        {
            firstVal(a);
        }
         else if (dec==5)
        {
            lastVal(a);
        }
        else if (dec==6)
        {
            peek(a);
        }
        else if (dec==7)
        {
            isFull(a);
            isEmpty(a);
        }
    }
    free(a->arr);
    
    return 0;
}








//CIRCULAR QUEUE USING ARRAY


#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int insert;
    int delete;
    int size;
    int *arr;
} queue ;

// void display(queue *a){
//     printf("The elements in the queue are : ");
//     for (int i = 1; i <= a->insert; (i+1)/a->size)
//     {
//         printf(" %d " , a->arr[i]);
//     }
//     printf("\n\n");
// } DISPLAY FUNCTION NOT WORKING

void isFull(queue *a){
    if(a->insert + 1)%a->size == a->delete{
        printf("Queue is full!!!\n\n");
        return;
    }else{
        printf("The queue is not full!!!!\n\n");
    }
}
void isEmpty(queue *a){
    if(a->insert == a->delete){
        printf("Queue is Empty!!!\n\n");
        return;
    }else{
        printf("The queue is not empty!!!!\n\n");
    }
}
void enqueue(queue *a){
    int value;
    printf("Enter the value to be enqueued in the queue : ");
    scanf(" %d" , &value);
    if((a->insert + 1)%a->size == a->delete){
        printf("Queue overflow\n\n");
        return;
    }else{
        a->insert = (a->insert + 1)%a->size;
        a->arr[a->insert] = value;
    }
}

void dequeue(queue *a){
    if(a->insert == a->delete){
        printf("Queue underflow\n\n");
        return;
    }else{
        a->delete = (a->delete + 1)%a->size;
        printf("%d is dequeued from the queue" , a->arr[a->delete]);
    }
}

void firstVal(queue *a){
    printf("The first value of the queue is : %d\n\n" , a->arr[a->delete]);
}
void lastVal(queue *a){
    printf("The last value of the queue is : %d\n\n" , a->arr[a->insert]);
}

void peek(queue *a){
    int index;
    printf("Enter the index number which u want to check  : ");
    scanf(" %d" , &index);
    if(index > a->size-1){
        printf("Inavlid index!!!\n\n");
        return;
    }
    else if (index < a->delete && index > a->insert)
    {
        printf("No elemnts present in the index\n\n");
        return;
    }else{
        printf("The element in index[%d] is %d\n\n" , index , a->arr[index-1]);
    }
    
}


int main()
{
    int n;
    printf("Enter the size of the queue : ");
    scanf(" %d" , &n);

    //queue creation
    queue *a = (queue*) malloc (sizeof(queue));
    a->size = n;
    a->insert = 0;
    a->delete = 0;
    a->arr = (int*) malloc (a->size * sizeof(int));

    int dec ;
    while (dec != 0)
    {
        printf("1> Enter 0 to exit.\n2> Enter 1 to display the queue.\n3> Enter 2 to enqueue elements in the queue.\n4> Enter 3 to dequeue the first element.\n5> Enter 4 to check the first value of the queue.\n6> Enter 5 to check the last value of the queue.\n7> Enter 6 to check the value present at a specfic function.\n8> Enter 7 to check the status of the queue.\n");
        scanf(" %d" , &dec);

        if(dec == 0){
            exit(0);
        }
        else if (dec==1)
        {
            display(a);
        }
        else if (dec==2)
        {
            enqueue(a);
        }
        else if (dec==3)
        {
            dequeue(a);
        }
         else if (dec==4)
        {
            firstVal(a);
        }
         else if (dec==5)
        {
            lastVal(a);
        }
        else if (dec==6)
        {
            peek(a);
        }
        else if (dec==7)
        {
            isFull(a);
            isEmpty(a);
        }
    }
    free(a->arr);
    
    return 0;
}






//QUEUE USING LINKED LIST



#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} queue ;

queue *r = NULL;
queue *f = NULL;

void display(){
    printf("The elements of the linked list : ");
    queue *n = f;
    while (n != NULL)
    {
        printf(" %d " , n->data);
        n = n->next;
    }
    printf("\n\n");
}

void enqueue(){
    int value;
    printf("Enter the value to be enqueued in the linked list : ");
    scanf(" %d" , &value);
    queue *n = (queue*) malloc (sizeof(queue));
    if(n==NULL){
        printf("Queue overflow !!! \n");
    }else
    {
        n->data = value;
        n->next = NULL;
        if(f==NULL){//to check if front delete pointer is NULL or not if its NULL then we move it to the next node along with rear pointer , beacause if front pointer is NULL then rear pointer will also be NULL since the first time updation of the rear pointer happens with the updation of the front pointer , so if front pointer is NULL then it means rear pointer is also NULL and no enqueue operations were performed before
            f=r=n;
        }else
        {
            r->next = n;
            r=n;
        }
        
    }
    
}


void dequeue(){
    if(f==NULL){
        printf("Queue underflow!!!!\n\n");
        return;
    }else{
        queue *n = f;
        f = f->next;
        printf("%d dequeued from the queue.\n\n" , n->data);
        free(n);
    }
}

void peek(){
    int index;
    printf("Enter the index number of the element u want to peek : ");
    scanf(" %d" , &index);
    queue *ptr = f;
    int i = 0;
    while(i <  index){
        ptr = ptr->next;
        i++;
    }
    printf("The value at index[%d] is %d\n\n" , index , ptr->data);
}

void firstVal(){
    printf("The first value of the queue is : %d\n\n" , f->data);
}
void lastVal(){
    printf("The last value of the queue is : %d\n\n" , r->data);
}

void isEmpty(){
    if(f==NULL){
        printf("The queue is empty.");
    }
}
void isFull(){
    queue *n = (queue*) malloc (sizeof(queue));
    if (n==NULL)
    {
        printf("The queue is full");
    }
    
}

int main(){

    int dec = 69 ;
    while (dec != 0)
    {
        printf("1> Enter 0 to exit.\n2> Enter 1 to display the queue.\n3> Enter 2 to enqueue elements in the queue.\n4> Enter 3 to dequeue the first element.\n5> Enter 4 to check the first value of the queue.\n6> Enter 5 to check the last value of the queue.\n7> Enter 6 to check the value present at a specfic function.\n8> Enter 7 to check the status of the queue.\n");
        scanf(" %d" , &dec);

        if(dec == 0){
            exit(0);
        }
        else if (dec==1)
        {
            display();
        }
        else if (dec==2)
        {
            enqueue();
        }
        else if (dec==3)
        {
            dequeue();
        }
         else if (dec==4)
        {
            firstVal();
        }
         else if (dec==5)
        {
            lastVal();
        }
        else if (dec==6)
        {
            peek();
        }
        else if (dec==7)
        {
            isFull();
            isEmpty();
        }
    }

    return 0;
}