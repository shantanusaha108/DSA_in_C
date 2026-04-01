//BSF TRAVERSAL


#include<stdio.h>

typedef struct Queue
{
    int insert_end;
    int delete_end;
    int size;
    int *arr;
} queue ;

void enqueue(queue *a){
    int value;
    printf("Enter the value to be inserted in the loop : ");
    scanf(" %d" , &value);
    if(a->insert_end == a->size-1){
        printf("Queue is full , dequeue elemets to inserts more elements.\n\n");
    }else{
        a->insert_end++;
        a->arr[a->insert_end] = value;
    }
}

void dequeue(queue *a){
    if(a->insert_end == -1){
        printf("Queue is empty , no elements to dequeue.\n\n");
        return;
    }else{
        int ch;
        ch = a->arr[a->delete_end];
        printf("%d dequeued from the queue.\n" , ch);
        a->delete_end++;
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
    return 0;
}