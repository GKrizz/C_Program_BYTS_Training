TREE TRAVERSAL

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node * left;
    int data;
    struct Node * right;
}NODE;
NODE * root;

NODE * createNewNode(int gd){
    NODE * newNode;
    newNode=malloc(sizeof(NODE));
    newNode -> data = gd;
    newNode -> left = newNode -> right =NULL;
    return newNode;
}
void inorderDisplay(NODE * curr)
{
    if(curr==NULL) return;
    inorderDisplay(curr->left);
    printf("%d ",curr->data);
    inorderDisplay(curr->right);
}
void preorderDisplay(NODE * curr)
{
    if(curr==NULL) return;
    printf("%d ",curr->data);
    inorderDisplay(curr->left);
    inorderDisplay(curr->right);

}
void postorderDisplay(NODE * curr)
{
    if(curr==NULL) return;
    inorderDisplay(curr->left);
    inorderDisplay(curr->right);
    printf("%d ",curr->data);
}

// write a function to count the number of nodes in the given binary tree
int number_of_nodes(NODE* curr) {
    if (curr == NULL) return 0;
    int lc=number_of_nodes(curr->left);
    int rc=number_of_nodes(curr->right);
    return lc+rc+1;
}

// write a function to count number of leaf nodes 
int number_of_leaf_nodes(NODE* curr) {
    if (curr == NULL) return 0;
    if(curr->left==NULL && curr->right==NULL) return 1;
    int lc=number_of_leaf_nodes(curr->left);
    int rc=number_of_leaf_nodes(curr->right);
    return lc+rc;
}
// write a function to count number of parent nodes 
int number_of_parent_nodes(NODE* curr) {
    if (curr == NULL) return 0;
    if(curr->left==NULL && curr->right==NULL) return 0;
    int lc=number_of_parent_nodes(curr->left);
    int rc=number_of_parent_nodes(curr->right);
    return lc+rc+1;
}
// write a function to count height of nodes 
int height(NODE* curr,int *diameter) {
    if (curr == NULL) return 0;
    int lh=height(curr->left,diameter);
    int rh=height(curr->right,diameter);
    if(*diameter<lh+rh)
        *diameter=lh+rh;
    return lh>rh? lh+1 :rh+1;
}
// Diameter of a tree (longest distance between any 2 nodes)
int diameter(NODE* curr) {
    int diameter=0;
    height(curr,&diameter);
    return diameter;
}
int main(){
    root=createNewNode(10);
    root->left=createNewNode(20);
    root->right=createNewNode(30);
    root->left->left=createNewNode(40);
    root->right->left=createNewNode(50);
    printf("\nInorder :");
    inorderDisplay(root);
    printf("\nPreorder :");
    preorderDisplay(root);
    printf("\nPostorder :");
    postorderDisplay(root);
    printf("\nNumner of Nodes: %d",number_of_nodes(root));
    printf("\nNumner of Leaf Nodes: %d",number_of_leaf_nodes(root));
    printf("\nNumner of parent Nodes: %d",number_of_parent_nodes(root));
    printf("\nDiameter of the Nodes: %d",diameter(root));
}


---------------------------------------------------------------

#include <iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
typedef struct Node {
    struct Node * left;
     int data;
     struct Node * right;
}NODE ;
NODE * root;
NODE * createNewNode( int gd)
{
    NODE * newNode;
    newNode =(NODE *)malloc(sizeof(NODE));
    newNode -> data = gd;
    newNode -> left = newNode -> right = NULL;
    return newNode;

}
int main()
{
    NODE * temp;
   root = createNewNode(10);
   root -> left = createNewNode(20);
   root -> right = createNewNode(40);
   root -> left -> left = createNewNode(30);
   root -> right -> left = createNewNode(50);

    queue<NODE *> q;
    q.push(root);
    
 while(1)
 {
    temp = q.front();
    if(temp == NULL) break;
    q.pop();
    if(temp){
     printf("%d ", temp ->data);
     if(temp->left != NULL)
        q.push(temp->left);
     if(temp ->right !=NULL)
        q.push(temp->right);
    }
}    
    return 0;
}