#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *arr;
} stack;

void showStack(stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d element in stack is : %d\n", i + 1, ptr->arr[i]);
    }
    printf("\n");
}

void isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("The stack is full!!\n");
    }
    else
    {
        printf("The stack is not full!\n");
    }
}

void isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("The stack is empty!!\n");
    }
    else
    {
        printf("The stack is not empty!\n");
    }
}

void push(stack *ptr)
{
    int value;
    printf("Enter the data to input in stack : ");
    scanf("%d", &value);
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack Overflow!! , no more space to insert new elements");
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return;
    }
}

void pop(stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack Underflow!! , no elements to pop out from stack");
        return;
    }
    else
    {
        printf("Poped %d from the stack\n\n", ptr->arr[ptr->top]);
        ptr->top--;
        return;
    }
}

void peek(stack *s)
{
    int index;
    printf("Enter the index number of the element which u want to check : ");
    scanf(" %d", &index);
    if (index < 0 && index > s->size - 1)
    {
        printf("Invalid index!!");
    }
    else
    {
        printf("The value present at index[%d] is : %d\n\n", index, s->arr[index - 1]);
    }
}

void stackTop(stack *s)
{
    if (s->top == -1)
    {
        printf("There are no elements in the stack");
        return;
    }
    printf("The element at the top of the stack is %d\n\n", s->arr[s->top]);
}

void stackBottop(stack *s)
{
    if (s->top == -1)
    {
        printf("There are no elements in the stack");
        return;
    }
    printf("The element at the bottom of the stack is %d\n\n", s->arr[0]);
}

int main()
{
    stack s;
    s.size = 10;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    s.arr[0] = 8;
    s.top++;
    s.arr[1] = 18;
    s.top++;
    s.arr[2] = 34;
    s.top++;
    s.arr[3] = 46;
    s.top++;
    s.arr[4] = 75;
    s.top++;
    s.arr[5] = 108;
    s.top++;
    s.arr[6] = 23;
    s.top++;
    s.arr[7] = 54;
    s.top++;
    s.arr[8] = 69;
    s.top++;
    // final value of top is 9 , and arr starts from 0 last element is in arr[8] so arr[top] i.e arr[9] is empty

    int dec;

    while (dec != 0)
    {
        printf("Follow the instructions below : \n1> Enter 0 to exit from the program.\n2> Enter 1 to check whther the stack is full or empty.\n3> Enter 2 to display the elements of the stack.\n4> Enter 3 to push a element into the stack.\n5> Enter 4 to pop the topmost element from the stack.\n6> Enter 5 to check the element present at a particular index\n7> Enter 6 to see the element at the top of the array.\n7> Enter 7 to see the element at the bottom of the array.\n");
        scanf(" %d", &dec);

        if (dec == 1)
        {
            isFull(&s);
            isEmpty(&s);
        }
        if (dec == 2)
        {
            showStack(&s);
        }
        if (dec == 3)
        {
            push(&s);
        }
        if (dec == 4)
        {
            pop(&s);
        }
        if (dec == 5)
        {
            peek(&s);
        }
        if (dec == 6)
        {
            stackTop(&s);
        }
        if (dec == 7)
        {
            stackBottop(&s);
        }
    }

    return 0;
}











// IMPLEMENTING STACK USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} n;

void display_stack(n*first){
    n *p = first;
    printf("The elements present in the stack are : \n");
    while(p->next != NULL){
        printf(" %d " , p->data);
        p = p->next;
    }
    printf("\n\n");
}

void isFull(){
    n *ptr = (n*) malloc (sizeof(n));
    if(ptr == NULL){
        printf("The stack is full.");
    }else{
        printf("The stack is not full.");
    }
}

void isEmpty(n*first){
    if(first == NULL){
        printf("Stack is empty.\n");
    }else{
        printf("The stack is not empty.\n");
    }
}

n *push(n*first){
    int data;
    printf("Enter the the data to push into stack : ");
    scanf(" %d" , &data);
    n *ptr = (n*) malloc(sizeof(n));
    if(ptr == NULL){
        printf("Stack Overflow! No more space to push elements");
    }else{
        ptr->data = data;
        ptr->next = first;
        first = ptr;
        return first;
    }
}

n *pop(n*first){
    if(first == NULL){
        printf("Stack Underflow , no elements to pop from stack");
        return first;
    }
    else{
        n *ptr = first;
        first = first->next;
        printf("Poped %d from the stack.\n\n" , ptr->data);
        free(ptr);
        return first;
    }
}

void peek(n*first){
    int index;
    printf("Enter the index number of the element u want to see(elements are viewed from the top) : ");
    scanf(" %d" , &index);
    int i = 1;
    n *ptr = first;
    while (i < index){
        ptr = ptr->next;
        i++;
    }
    printf("The value at index %d is : %d\n" , index , ptr->data);
}

void stackTop(n*first){
    printf("The value present at the top of the stack is : %d\n" , first->data);
}

void stackBottom(n*first){
    n*ptr= first;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    printf("The value present at the bottom of the stack is : %d\n", ptr->data);
}

int main()
{
    n *first = (n *)malloc(sizeof(n));
    n *second = (n *)malloc(sizeof(n));
    n *third = (n *)malloc(sizeof(n));
    n *fourth = (n *)malloc(sizeof(n));
    n *fifth = (n *)malloc(sizeof(n));
    n *sixth = (n *)malloc(sizeof(n));
    n *seventh = (n *)malloc(sizeof(n));

    first->data = 45;
    first->next = second;

    second->data = 01;
    second->next = third;
    
    third->data = 81;
    third->next = fourth;

    fourth->data = 69;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = sixth;

    sixth->data = 89;
    sixth->next = seventh;

    seventh->data = 65;
    seventh->next = NULL;
    
    int dec = 69;
    //the value of dec is initialized to 69 beacause the while loop in the main function is not repeating itself after the push function because the value of the "dec" variable is not being initialized before the loop starts. This means that if the push function is called and the user inputs a value for "dec" other than 0, the loop will not repeat itself because the value of "dec" from the previous iteration is still stored.To fix this issue, you should initialize the "dec" variable to a non-zero value before the loop starts. For example, you can set "dec" to 1 before the loop:
    while (dec != 0)
    {
        printf("Follow the following instructions : \n1> Enter 0 to exit from the program.\n2> Enter 1 to display the stack.\n3> Enter 2 to check whether stack is empty or full.\n4> Enter 3 to push a element in the stack.\n5> Enter 4 to pop a element from the stack.\n6> Enter 5 to peek a element from the stack.\n7> Enter 6 to check the element present at the top of the stack.\n8> Enter 7 to check the element present at the bottom of the stack.\n");
        scanf(" %d" , &dec);


        if(dec==0){
            break;
        }
        if(dec==1){
            display_stack(first);
        }
        if(dec==2){
            isFull();
            isEmpty(first);
        }
        if(dec==3){
            first = push(first);
        }
        if(dec==4){
            first = pop(first);
        }
        if(dec==5){
            peek(first);
        }
         if(dec==6){
            stackTop(first);
        } 
        if(dec==7){
            stackBottom(first);
        }
    }
    
    return 0;
}

















//PARENTHESIS MATCHING PROBLEM : IN THIS PROBLEM WE NEED TO CHECK IF THE PARENTHESIS IN A EXPRESSION ARE BALANCED OR NOT

//EXAMPLES : 
//         1> (656() - NOT A BALANCED EXPRESSION
//         2> (3434()) - A BALANCED EXPRESSION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
    int size;
    int top;
    int *arr;
} stack ;

int sting_size_determiner(char *str){
    int i = 0 , c = 0;
    while(str[i] != '\0'){
        c++;
        i++;
    }
    return c;  
}

void push(stack *a , char value){
    if(a->top == a->size){
        printf("Stack overflow no place to push elements.\n");
    }
    else{
        a->top++;
        a->arr[a->top] = value;
    }
}

int pop(stack *a){
    if(a->top == -1)
    {
        return 0;
    }else{
        a->top--;
        return 1;
    }
}

int isEmpty(stack *a){
    if(a->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void parenthesis_matching(stack *a , char *str){
    int push_count = 0 , pop_count = 0;
    for (int i = 0; i < a->size; i++)
    {
        if(str[i] == '('){
            push(a , '(');
            push_count++;
        }else if(str[i] == ')'){
            if(isEmpty(a)){
                printf("The stack became  empty while poping elements !!! the expression is not balanced.");
                return;
            }
            pop(a);
            pop_count++;
        }
    }
    printf("Total no of times a character was pushed in the stack is %d times.\n" , push_count);
    printf("Total no of times a character was poped from the stack is %d times.\n" , push_count);
    
    if(isEmpty(a)){
        printf("Expression is balanced.\n");
    }else{
        printf("Stack is not empty , thus the expression is not balanced.\n");
    }
    
}

int main()
{
    int n;
    printf("Enter the size of the string : ");
    scanf(" %d" , &n);
    fflush(stdin);
    char *str = (char*) malloc (n*sizeof(char));
    printf("Enter the expresion whose parenthesis matching is to be checked : ");
    gets(str);
    int actual_string_size = sting_size_determiner(str);

    //stack creation
    stack *a;
    a->size = n;
    a->top = -1;
    a->arr = (int*) malloc (a->size * sizeof(int));

    parenthesis_matching(a,str);
    free(str);
    free(a->arr);
    return 0;
}







//INFIX TO POSTFIX


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} stack ;

void push(stack *a , int value){
    a->top++;
    a->arr[a->top] = value;
}

char pop(stack *a){
    char ch = a->arr[a->top];
    a->top--;
    return ch;
}

int isEmpty(stack *a){
    if(a->top == -1){
        return 1;
    }else{
        return 0;
    }
}

char stackTop(stack *a){
    return a->arr[a->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }else{
        return 0;
    }
}

char *infix_to_postfix(stack *a , char *infix){
    char *postfix = (char*) malloc ((strlen(infix)+1)*sizeof(char));
    int i=0 , j=0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else if (isEmpty(a) || precedence(infix[i]) > precedence(stackTop(a))){
            push(a,infix[i]);
            i++;
        }else{
            postfix[j] = pop(a);
            j++;
        }
    }
    while(!isEmpty(a)){
        postfix[j] = pop(a);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    int n;
    printf("Enter the size of the string : ");
    scanf(" %d" , &n);
    fflush(stdin);
    char *infix = (char*) malloc (n * sizeof(char));
    printf("Enter the infix expression : \n");
    gets(infix);

    //stack creation
    stack *a = (stack*) malloc (sizeof(stack));
    a->size = n;
    a->top = -1;
    a->arr = (char*) malloc (a->size * sizeof(char));

    char *postfix = infix_to_postfix(a , infix);
    printf("The infix expression in postfix is : %s\n" , postfix);
    return 0;
}
