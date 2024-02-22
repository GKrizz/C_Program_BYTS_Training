Linked List

#include <stdio.h>
#include <stdlib.h>  

struct Node {
    int data;
    struct Node* next;
};

struct Node* start;
struct Node* end;

//1.Add node at last
void addNodeAtLast(int gd) {
    struct Node* curr;
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = gd;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        for (curr = start; curr->next != NULL; curr = curr->next);
        curr->next = newNode;
        end = newNode;
    }
}
//1.Add node at last(efficient way)
void addLast(int gd) {
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = gd;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
        end = newNode;
    } else {
        end->next = newNode;
        end = newNode;
    }
}
//2.Add node at First
void addNodeAtFirst(int gd) {
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = gd;
    newNode->next = NULL;

    if (start == NULL) {
        start = end = newNode;
    } else {
        newNode->next = start;
        start = newNode;
    }
}
//3.Insert Node

void insertNode(int gd,int pos){
    struct Node *curr,*prev;
    int count;
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = gd;
    newNode->next = NULL;
    if(start==NULL){
        start=end=newNode;
    }
    else{
        for(curr=start,prev=NULL,count=1;count!=pos && curr!=NULL;){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(prev==NULL){
            newNode->next=start;
            start=newNode;
        }
        else if(curr==NULL){
            prev->next=newNode;
            end=newNode;
        }
        else{
            newNode->next=curr;
            prev->next=newNode;
        }
    }
    
}

//4.Delete Node

void deleteNode(int gd){
    struct Node*curr,*prev;
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = gd;
    newNode->next = NULL;
    
    for(curr=start,prev=NULL;curr!=NULL && curr -> data!=gd;){
        prev = curr;
        curr = curr -> next;
    }
    if(curr==NULL){
        printf("Element is not there in the list");
        return;
    }
    if(prev==NULL || curr==start){
        start = curr -> next;
        free(curr);
    }else if(curr == end || curr -> next==NULL){
        prev -> next = NULL;
        free(curr);
    }else{
       prev -> next = curr -> next; 
       free(curr);
    }
    
}



void display() {
    struct Node* curr;
    for (curr = start; curr != NULL; curr = curr->next)
        printf("%d ", curr->data);
    printf("\n");
}
int main() {
    insertNode(10,2);
    insertNode(20,1);
    insertNode(30,3);
    insertNode(40,4);
    insertNode(50,3);

    display();
    // printf("\n");
    deleteNode(10);
    display();
    // printf("\n");
    deleteNode(50);
    display();
    // printf("\n");
    deleteNode(30);
    display();
    
    return 0; 

}
