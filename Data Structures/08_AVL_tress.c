#include<stdio.h>
#include<stdlib.h>

typedef struct AVL_TRESS
{
    int data;
    int height;
    struct AVL_TRESS *left;
    struct AVL_TRESS *right;
} avltress;

avltress *create_node(int key){
    avltress *root = (avltress*) malloc (sizeof(avltress));
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    
    return root;
}

int height_of_a_node(avltress *root){
    if(root == NULL)
        return 0;
    return root->height;
}

int balance_factor(avltress *root){
    if (root == NULL)
    {
        return 0;
    }else{
        return height_of_a_node(root->left) - height_of_a_node(root->right);
    }
}

int max(int a , int b){
    return (a>b)?a:b;
}

// the avl  tree
//          tree to be right rotated         y
//                                       R/    \/
//                                       x      T3
//                                    R/   \/
//                                    T1    T2

avltress *right_rotate(avltress *y){
    avltress *x = y->left;
    avltress *t2 = x->right;
    
    //specifying the new position for y and t2
    x->right = y;
    y->left = t2; 

    //updating height of x and y
    y->height = max(height_of_a_node(y->left) , height_of_a_node(y->right)) + 1;
    y->height = max(height_of_a_node(x->left) , height_of_a_node(x->right)) + 1;

    return x;
}

// the avl  tree
//          tree to be left rotated          x
//                                        /    \/
//                                       T1     Y
//                                            /   \/
//                                           T2    T3

avltress *left_rotate(avltress *x){
    avltress *y = x->right;
    avltress *t2 = y->left;

    //specifying the new position for x and t2
    y->left = x;
    x->right = t2;

    //updating height of x and y
    x->height = max(height_of_a_node(x->left) , height_of_a_node(x->right)) + 1;
    y->height = max(height_of_a_node(y->left) , height_of_a_node(y->right)) + 1;

    return y;
}

avltress *insertion(avltress *root , int key){
    if(root == NULL){
        return create_node(key);
    }
    else if(key < root->left->data)
    {
        root->left = insertion(root->left , key);
    }
    else if (key > root->right->data)
    {
        root->right = insertion(root->right , key);
    }

    root->height = max(height_of_a_node(root->left) , height_of_a_node(root->right)) + 1;
    int bf = balance_factor(root);

    //for left left case
    if(bf>1 && key < root->left->data){
       return  right_rotate(root);
    }
    
    //for right right case
    if(bf<-1 && key > root->right->data){
        return left_rotate(root);
    }

    //for left right case
    if(bf>1 && key > root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    //for right left case
    if(bf<-1 && key < root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

void inOrderTraversal(avltress *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf(" %d " , root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    avltress *root = NULL;

    root = insertion(root , 1);
    root = insertion(root , 2);
    root = insertion(root , 3);
    root = insertion(root , 4);
    root = insertion(root , 5);
    root = insertion(root , 6);

    inOrderTraversal(root);
    return 0;
}