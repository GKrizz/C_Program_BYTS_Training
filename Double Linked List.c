DOUBLE LINKED LIST:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}NODE;

NODE *start, *end;

NODE *createNewNode(int gd){

    NODE *newNode;
    newNode = malloc(sizeof(NODE));
    newNode -> data = gd;
    newNode -> prev = newNode -> next = NULL;
    return newNode;
}

void addLast(int gd){
    NODE *newNode;
    newNode=createNewNode(gd);
    if(start == NULL){
        start = end = newNode;
    }else{
        newNode -> prev = end;
        end -> next = newNode;
        end = newNode;
    }
}

void addFirst(int gd){
    NODE *newNode;
    newNode = createNewNode(gd);
    if(start == NULL){
        start = end = newNode;
    }else{
        newNode->next=start;
        start->prev=newNode;
        start=newNode;
    }
}
void insertNode(int gd){
    NODE *newNode,*curr;
    newNode = createNewNode(gd);
    if(start == NULL){
        start = end = newNode;
    }else{
        for(curr=start;curr!=NULL && curr->data < gd;curr=curr->next);
        if(curr==start)
            addFirst(gd);
        else if (curr==NULL)
            addLast(gd);
        else
        {
            newNode=createNewNode(gd);
            newNode->prev=curr->prev;
            newNode->next=curr;
            curr->prev->next=newNode;
            curr->prev=newNode;
        }
    }
}

void forwardDisplay(){
    NODE *curr;
    for(curr = start;curr!=NULL;curr=curr->next){
        printf("%d ",curr->data);
    }
    printf("\n\n");
}

void backwardDisplay(){
    NODE *curr;
    for(curr = end;curr!=NULL;curr=curr->prev){
        printf("%d ",curr->data);
    }
    printf("\n\n");
}

void main(){
    insertNode(10);
    insertNode(20);
    insertNode(60);
    insertNode(40);
    insertNode(50);
    // addFirst(10);
    // addFirst(20);
    // addFirst(30);
    // addFirst(40);
    // addFirst(50);
    // addLast(10);
    // addLast(20);
    // addLast(30);
    // addLast(40);
    // addLast(50);
    forwardDisplay();
    backwardDisplay();
}



----------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}NODE;

NODE *top;
int count=0;

NODE *createNode(int gd){
    NODE *newNode;
    newNode = malloc(sizeof(NODE));
    newNode -> data = gd;
    newNode -> next = NULL;
    return newNode;
}
void push(int gd){
    NODE *newNode;
    newNode = createNode(gd);
    if(top==NULL){
        top = newNode;
    }else{
        newNode -> next = top;
        top = newNode;
    }
    count++;
}

int pop(){
    int temp;
    NODE *curr;
    if(top)
    {
        temp= top->data;
        curr=top;
        top = top->next;
        free(curr);
        count--;
        return temp;
    }
    
    return -1;
}

int peek()
{
    if(top) return top->data;
    return -1;
}
int size()
{
    return count;
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",peek());
    printf("%d\n",size());
}
----------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}NODE;

NODE *front,*rear;

NODE * createNewNode(int gd)
{
    NODE * newNode;
    newNode= malloc(sizeof(NODE));
    newNode->data=gd;
    newNode->next=NULL;
    return newNode;
}

void enque(int gd)
{
    NODE *newNode;
    newNode=createNewNode(gd);
    if(front==NULL)
        front=rear=newNode;
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
int deque()
{
    NODE * curr=front;
    int temp=front->data;
    if(front)
        front=front->next;
    free(curr);
    return temp;
}

// write a functin called count_no_of_nodes which will return the number of node at the list
int count_no_of_nodes() {
    int count = 0;
    NODE *curr = front;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}
//Find the middle node 
NODE *middle_node()
{
    NODE *curr = front;
    int pos;
    int count=count_no_of_nodes(front);
    count=count/2;
    
    for(curr=front,pos=0;pos!=count;pos++,curr=curr->next);
    return curr;
}

//write a function to print the given function in the reverse order
void reverseDisplay(NODE * curr) {
    if (curr == NULL) {
        return;
    }
    reverseDisplay(curr->next);
    printf("%d ", curr->data);
}

int main(){
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    // printf("%d",deque());
    printf("\n");

    printf("%d",count_no_of_nodes());
    printf("\n");
    reverseDisplay(front);
    printf("\n");
    printf("%d",middle_node()->data);
    
}

