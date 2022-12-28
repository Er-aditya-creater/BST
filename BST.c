#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*ROOT = NULL;

struct node *new_node(int key){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Insufficient Storage.\n");
    }
    else{
        p->data = key;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}
struct node *insert(struct node *ptr,int key){
    if(ptr == NULL){
        ptr = new_node(key);
    }
    else{
        if(key < ptr->data){
            ptr->left = insert(ptr->left,key);
        }
        else if(key > ptr->data){
            ptr->right = insert(ptr->right,key);
        }
    }
    return ptr;
}


void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d\t",root->data);
        inorder(root->left);
        inorder(root->right);
    } 
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }  
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d\t",root->data);
        postorder(root->left);
        postorder(root->right);
    } 
}

int main()
{
    int choice,val;
    while (1)
    {
        printf("Various Operations on Binary Search Tree :\n");
        printf("Enter 1 to insert an element in BST\n");
        printf("Enter 2 to Traverse the tree in Preorder \n");
        printf("Enter 3 to Traverse the tree in Postorder\n");
        printf("Enter 4 to Traverse the tree in Inorder\n");
        printf("Enter 5 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to insert in BST ");
            scanf("%d",&val);
            ROOT = insert(ROOT,val);
            break;
        case 2:
            if(ROOT == NULL){
                printf("Binary Tree is Empty.\n");
            }
            else{
                printf("Preorder Traversal of the tree is : ");
                preorder(ROOT);
                printf("\n");
            }
            break;
        case 3:
            if(ROOT == NULL){
                printf("Binary Tree is Empty.\n");
            }
            else{
                printf("Postorder Traversal of the tree is : ");
                postorder(ROOT);
                printf("\n");
            }
            break;
        case 4:
            if(ROOT == NULL){
                printf("Binary Tree is Empty.\n");
            }
            else{
                printf("Inorder Traversal of the tree is : ");
                inorder(ROOT);
                printf("\n");
            }
            break;
        case 5:
            printf("Thank You!\n");
            exit(0);
            break;
        default:
            printf("Please enter a valid number\n");
        }
    }
    return 0;
}