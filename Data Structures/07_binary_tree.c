//REPRESENTATION OF TREE USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
}btree;

btree *create_node(){
    int data;
    printf("Enter the data for the new node : ");
    scanf("%d" , &data);
    btree *ptr = (btree*) malloc (sizeof(btree));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int main()
{   //root node
    btree *root = (btree*) malloc (sizeof(btree)); 

    //parent and child nodes
    btree *p1 = create_node();
    btree *p2 = create_node();
    btree *p3 = create_node();

    root->left = p1;
    root->right = p2;
    
    p1->left = p3;
    p1->right = NULL;

    p2->left = NULL;
    p2->right = NULL;

    p3->left = NULL;
    p3->right = NULL;
    

    return 0;
}






//TRAVERSAL IN BINARY TREE
//PRE-ORDER TRAVERSAL
//POST-ORDER TRAVERSAL
//IN ORDER  ORDER TRAVERSAL



#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
}btree;

btree *create_node(){
    int data;
    printf("Enter the data for the new node : ");
    scanf("%d" , &data);
    btree *ptr = (btree*) malloc (sizeof(btree));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

//PREORDER TRAVERSAL
void preorder_traversal(btree *root){
    if(root!=NULL){
        printf(" %d " , root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

//POSTORDER TRAVERSAL
void postorder_traversal(btree *root){
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf(" %d " , root->data);
    }
}

//IN ORDER TRAVERSAL
void in_order_traversal(btree *root){
    if(root != NULL){
        in_order_traversal(root->left);
        printf(" %d " , root->data);
        in_order_traversal(root->right);
    }
}

int main()
{   //root node
    btree *root = create_node();

    //parent and child nodes
    btree *p1 = create_node();
    btree *p2 = create_node();
    btree *p3 = create_node();
    btree *p4 = create_node();
    btree *p5 = create_node();
    btree *p6 = create_node();
    btree *p7 = create_node();
    btree *p8 = create_node();
    btree *p9 = create_node();
    btree *p10 = create_node();
    btree *p11 = create_node();
    btree *p12 = create_node();
    btree *p13 = create_node();
    btree *p14 = create_node();


    root->left = p1;
    root->right = p2;
    
    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    p3->left = p7;
    p3->right = p8;

    p4->left = p9;
    p4->right = p10;

    p5->left = p11;
    p5->right = p12;

    p6->left = p13;
    p6->right = p14;

    p7->left = NULL;
    p7->right = NULL;

    p8->left = NULL;
    p8->right = NULL;

    p9->left = NULL;
    p9->right = NULL;

    p10->left = NULL;
    p10->right = NULL;

    p11->left = NULL;
    p11->right = NULL;

    p12->left = NULL;
    p12->right = NULL;

    p13->left = NULL;
    p13->right = NULL;

    p14->left = NULL;
    p14->right = NULL;

    
    printf("Preorder traversal : \n");
    preorder_traversal(root);
    printf("\n\n");
    printf("Postorder traversal : \n");
    postorder_traversal(root);
    printf("\n\n");
    printf("In order traversal : \n");
    in_order_traversal(root);
    return 0;
}



















//BINARY SEARCH TREE


#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
}btree;

btree *create_node(){
    int data;
    printf("Enter the data for the new node : ");
    scanf("%d" , &data);
    btree *ptr = (btree*) malloc (sizeof(btree));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

//PREORDER TRAVERSAL
void preorder_traversal(btree *root){
    if(root!=NULL){
        printf(" %d " , root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

//POSTORDER TRAVERSAL
void postorder_traversal(btree *root){
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf(" %d " , root->data);
    }
}

//IN ORDER TRAVERSAL
void in_order_traversal(btree *root){
    if(root != NULL){
        in_order_traversal(root->left);
        printf(" %d " , root->data);
        in_order_traversal(root->right);
    }
}

//to check if its a BST or not!!!
int isBST(btree *root){
    static btree *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

//search function in a BST
btree *search_value(btree *root , int value){
    btree *ptr = root;
    if(ptr == NULL){
        return NULL;
    }else if (ptr->data == value)
    {
        return ptr;
    }
    
    else if (ptr->data > value)
    {
        search_value(ptr->left , value);
    }else{
        return search_value(ptr->right , value);
    }
}


btree *search_value_by_iteration(btree *root , int value){
    btree *ptr = root;
    while(ptr != NULL){
        if (ptr->data == value)
        {
            return ptr;
        }
        else if (ptr->data > value)
        {
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    return NULL;
}

//INSERTION IN A BST
void insertion(btree *root){
    btree *new = create_node();
    btree *ptr = root;
    btree *prev = NULL;
    int value = new->data;
    while(ptr != NULL){
        prev = ptr;
        if(value == ptr->data){
            printf("Cant insert!!!.. data already present in BST\n");
            return;
        }else if(value < ptr->data){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    if(prev->data > value){
        prev->left = new;
    }else{
        prev->right = new;
    }
}

btree *inOrderPredecessor(btree *root){
    btree *ptr = root;
    ptr = ptr->left;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    return ptr;
}

btree *deletion(btree *root , int key){
    btree *iPre = NULL;
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL){//checking for if its leaf node
        free(root);
        return NULL;
    }

    //searching the value to be deleted
    else if (key < root->data)
    {
        root->left = deletion(root->left , key);
    }
    else if(key > root->data){
        root->right = deletion(root->right , key);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deletion(root->left , iPre->data); 
    }
    return root;
}

int main()
{   
    btree *root;
    
    int dec = 2000;
    while(dec != 0){
        printf("Follow the following instruction : \n1> Enter 0 to exit from the program.\n2> Enter 1 to create the tree.\n3> Enter 2 to check if the tree is BST or not.\n4> Enter 3 to to do preorder traversal.\n5> Enter 4 to do postorder traversal.\n6> Enter 5 to do in order traversal.\n7> Enter 6 to search for a element using recursiion in the BST.\n8> Enter 7 to search for  a element using iteration in the BST.\n9> Enter 8 to insert a new element in the BST\n10> Enter 9 to delete a node from the BST.\n");
        scanf(" %d" , &dec);

        if(dec==0){
            exit(0);
        }
        else if(dec == 1){
            //root node
            root = create_node();

            //parent and child nodes
            btree *p1 = create_node();
            btree *p2 = create_node();
            btree *p3 = create_node();
            btree *p4 = create_node();
            // btree *p5 = create_node();
            // btree *p6 = create_node();
            // btree *p7 = create_node();
            // btree *p8 = create_node();
            // btree *p9 = create_node();
            // btree *p10 = create_node();
            // btree *p11 = create_node();
            // btree *p12 = create_node();
            // btree *p13 = create_node();
            // btree *p14 = create_node();


            root->left = p1;
            root->right = p2;
            
            p1->left = p3;
            p1->right = p4;

            p2->left = NULL;
            p2->right = NULL;

            p3->left = NULL;
            p3->right = NULL;

            p4->left = NULL;
            p4->right = NULL;

            // p5->left = NULL;
            // p5->right = NULL;

            // p6->left = NULL;
            // p6->right = NULL;

            // p7->left = NULL;
            // p7->right = NULL;

            // p8->left = NULL;
            // p8->right = NULL;

            // p9->left = NULL;
            // p9->right = NULL;

            // p10->left = NULL;
            // p10->right = NULL;

            // p11->left = NULL;
            // p11->right = NULL;

            // p12->left = NULL;
            // p12->right = NULL;

            // p13->left = NULL;
            // p13->right = NULL;

            // p14->left = NULL;
            // p14->right = NULL;

        }
        else if (dec == 2)
        {
            if(!isBST(root)){
                printf("The tree is not a BST!!!\n");
            }else{
                printf("Its a BST!!!\n\n");
            }
        }
        else if (dec==3)
        {
            preorder_traversal(root);
            printf("\n\n");
        }
        else if (dec==4)
        {
            postorder_traversal(root);
            printf("\n\n");
        }
        else if (dec==5)
        {
            in_order_traversal(root);
            printf("\n\n");
        }
        else if (dec==6)
        {
            int value;
            printf("Enter the value to searched : ");
            scanf(" %d" , &value);
            btree *n = search_value(root , value);
            if (n != NULL)
            {
                printf(" Found : %d \n" , n->data);
            }else{
                printf("Element not found.\n");
            }
            printf("\n\n");
        }
        else if (dec==7)
        {
            int value;
            printf("Enter the value to searched : ");
            scanf(" %d" , &value);
            btree *n = search_value_by_iteration(root , value);
            if (n != NULL)
            {
                printf(" Found : %d \n" , n->data);
            }else{
                printf("Element not found.\n");
            }
            printf("\n\n");
        }
        else if (dec==8)
        {
            insertion(root);
        }
        else if (dec==9)
        {
            int key;
            printf("Enter the value of the node to be deleted : ");
            scanf(" %d" , &key);
            deletion(root , key);
        }
    }
    return 0;
}

