#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *get_last_node(node *head)
{
    // whenever we update a element in the list the first node pointers gets updated but to traverse the elemnet in backward manner we also need to update the last node
    node *last = head;
    while (last != NULL && last->next != NULL)
    {
        last = last->next;
    }
    return last;
}

void traversalForward(node *head)
{
    printf("Doubly Linked List (forward traversal):\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n\n");
}

void traversalBackward(node *tail)
{
    printf("Doubly Linked List (backward traversal):\n");
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n\n");
}

// insertion code begin here
node *insertAtBeginning(node *head)
{
    int data;
    printf("Enter the data to be inserted at the beginnin of the list : \n");
    scanf(" %d", &data);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    return newNode;
}
node *insertInBetween(node *first)
{
    int n, data;
    printf("Enter the index number where u want to create a new node : ");
    scanf(" %d", &n);
    printf("Enter the data that u want ti input in the new node : ");
    scanf(" %d", &data);
    node *p = (node *)malloc(sizeof(node));
    node *ptr = first;
    node *ftr = first->next;
    int i = 1;
    while (i < (n - 1))
    {
        ptr = ptr->next;
        ftr = ftr->next;
        i++;
    }
    p->data = data;
    p->next = ftr;
    p->prev = ptr;
    ptr->next = p;
    ftr->prev = p;
    return first;
}
node *insertAtTheEnd(node *first)
{
    int data;
    printf("Enter the data that u want to input in the new node : ");
    scanf(" %d", &data);
    node *newNode = (node *)malloc(sizeof(node));
    node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = p;
    return first;
}
// insertion code ends here

// deletion code begin here
node *DeleteNodeWithSpecificValue(node *first)
{
    int value;
    printf("Enter the value u want to be deleted (Note: Only the first node with the same value will be deleted) : ");
    scanf(" %d", &value);

    // code to delete the first element if the given value is in it
    if (first->data == value)
    {
        node *ftr = first;
        first = ftr->next;
        first->prev = NULL;
        free(ftr);
        return first;
    }

    node *p = first;
    node *ptr = p->next;
    while (ptr->data != value)
    {
        p = p->next;
        ptr = ptr->next;
    }
    if (p->next == NULL)
    {
        printf("There is no node in the list with the given value.\n\n");
    }
    p->next = ptr->next;
    node *ftr = ptr->next;
    ftr->prev = p;
    free(ptr);
    return first;
}
int main()
{
    node *first = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));
    node *fifth = (node *)malloc(sizeof(node));

    first->data = 45;
    first->prev = NULL;
    first->next = second;

    second->data = 34;
    second->prev = first;
    second->next = third;

    third->data = 65;
    third->prev = second;
    third->next = fourth;

    fourth->data = 25;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 90;
    fifth->prev = fourth;
    fifth->next = NULL;

    int dec;
    while (dec != 0)
    {
        printf("Follow the following instructions : \n1> Enter 0 to exit from the program.\n2> Enter 1 to display the Linked List in forward manner.\n3> Enter 2 to display the Linked List in backward manner.\n4> Enter 3 for insertion at the begining of the Linked List.\n5> Enter 4 for insertion at the middle of the linked list.\n6> Enter 5 for insertion at the end of the Linked List.\n7> Enter 6 for insertion after a node of the Linked List.\n8> Enter 7 to delete the first node from the program.\n9> Enter 8 to delete the node at a present specific index\n10> Enter 9 to delete the last node.\n11> Enter 10 to delete a node with a specific value.\n");
        scanf(" %d", &dec);

        if (dec == 0)
        {
            break;
        }
        if (dec == 1)
        {
            traversalForward(first);
        }
        if (dec == 2)
        {
            fifth = get_last_node(first); // updated last node gets stored in last
            traversalBackward(fifth);
        }
        if (dec == 3)
        {
            first = insertAtBeginning(first);
        }
        if (dec == 4)
        {
            first = insertInBetween(first);
        }
        if (dec == 5)
        {
            // node *p = IndentiyingNode(first);
            // first = InsertionAfterANode(first , p);
        }
        if (dec == 6)
        {
            first = insertAtTheEnd(first);
        }
        if (dec == 7)
        {
            // first =DeletingNodeAtAIndex(first);
        }
        if (dec == 8)
        {
            // first = DeletingLastNode(first);
        }
        if (dec == 9)
        {
            first = DeleteNodeWithSpecificValue(first);
            fifth = get_last_node(first);
        }
    }
    return 0;
}
