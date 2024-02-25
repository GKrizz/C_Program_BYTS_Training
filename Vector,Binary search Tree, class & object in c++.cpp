07-02-2024

// #include <iostream>
// #include<queue>
// #include<stdlib.h>
// #include<vector>
// using namespace std;
// typedef struct Node {
//     struct Node * left;
//      int data;
//      struct Node * right;
// }NODE ;
// NODE * root;
// NODE * createNewNode( int gd)
// {
//     NODE * newNode;
//     newNode =(NODE *)malloc(sizeof(NODE));
//     newNode -> data = gd;
//     newNode -> left = newNode -> right = NULL;
//     return newNode;
// }
// int main()
// {
//     NODE * temp;
//   root = createNewNode(10);
//   root -> left = createNewNode(20);
//   root -> right = createNewNode(40);
//   root -> left -> left = createNewNode(30);
//   root -> right -> left = createNewNode(50);



vector<vector<int>>levelOrder(TreeNode* root){
    vector<vector<int>>res;
vector<int>v;
    NODE*temp;
    queue<NODE *> q;
    q.push(root); //100
    
 while(1)
 {
    int size=q.size(); //1 0| -1 2 |1 0 |-1
    while(size--)//
    {
        temp = q.front(); //100 |200|300|400|500|600|700
        if(temp == NULL) break;
            q.pop();
        if(temp)
        {
         v.push_back(temp ->data);//data: 10
         if(temp->left != NULL)
            q.push(temp->left);//200  
         if(temp ->right !=NULL)
            q.push(temp->right);//300
        }
    }
    if(!v.empty())
        res.push_back(v);// 10,20,30,40,50,60,70.
    v.clear();//[10] | [20,30] |  [40,50,60,70]
}    
    return res;
}
}
--------------------------------------------------------------------------------------

Binary search Tree 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node * right;
    int data;
    struct Node * left;
}NODE;

NODE * root;

NODE * createNewNode(int gd)
{
    NODE * newNode;
    newNode =(NODE*)malloc(sizeof(NODE));
    newNode->data=gd;
    newNode->left=newNode->right=NULL;
    return newNode;
}

void createBST( int gd)
{
    NODE * newNode,*curr,*parent;
    newNode=createNewNode(gd);
    if(root==NULL)
       root=newNode;
    else
    {
        for(curr=root;curr;parent=curr,curr=curr->data<gd?curr->right:curr->left);
        if(parent->data<gd)
          parent->right=newNode;
        else parent->left=newNode;
    }
}

void inorder(NODE * curr)
{
    if(curr==NULL) return;
    inorder(curr->left);
    printf("%d ",curr->data);
    inorder(curr->right);
    
}

void main()
{
    createBST(40);
    createBST(20);
    createBST(60);
    createBST(100);
    createBST(10);
    createBST(15);
    createBST(50);
    inorder(root);
}

-----------------------------------------------------
Class in c ++:

#include<stdio.h>
#include<iostream>
using namespace std;
class emp{
    int id;
    int sal;
    string name;
    public:
        void getDetails()
        {
            cin>>name;
            cin>>id;
            cin>>sal;
        }
        void putDetails()
        {
            cout<<name<<" "<<id<<" "<<sal;
        }
};
int main()
{
    emp e;
    e.getDetails();
    e.putDetails();
    return 0;
}



-----*------

object with class in c++:

#include <iostream>
using namespace std;
class Account
{
    int accNo;
    string name;
    int balance;
    public:
    Account(int accNo,string name,int balance)
    {
        this->accNo=accNo;
        this->name=name;
        this->balance=balance;
    }
    void withdraw()
    {
        int amount;
        cout<<"Enter the amount to be withdrawn: ";
        cin>>amount;
        if(amount>balance)
            cout<<"Insufficient";
        else
        {
            balance-=amount;
            cout<<"Available balance\n"<<balance;
        }
    }
};

int main()
{
    Account p1(1010,"gobal",50000);
    p1.withdraw();

    return 0;
}
-----------------------------------------------------