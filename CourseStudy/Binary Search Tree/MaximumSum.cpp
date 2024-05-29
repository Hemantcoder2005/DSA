#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
        int data;
        struct Node* left;
        struct Node* right;

        Node(int val){
            data=val;
            left=right=NULL;
        }
};

int  MaxSum(Node* root,int &sum){
    if(root == NULL){
        return 0;
    }
    int Maxleft=MaxSum(root->left,sum);;
    int MaxRight=MaxSum(root->right,sum);;
    
    
    sum=max(sum,root->data+Maxleft+MaxRight);
    cout<<sum<<endl;
    return root->data+max(Maxleft,MaxRight);
    
}

int main() {
    // Your code here
    Node* root=new Node(1);
    
    Node* ch1=new Node(2);
    Node* ch2=new Node(3);

    Node* ch11=new Node(4);
    Node* ch12=new Node(5);

    Node* ch21=new Node(6);
    Node* ch22=new Node(7);

    // Node* ch31=new Node(8);

    root->left=ch1;
    root->right=ch2;

    ch1->left=ch11;
    ch1->right=ch12;

    ch2->left=ch21; 
    ch2->right=ch22;

    // ch22->left=ch31;
    
    int sum=0;
    MaxSum(root,sum);
    cout<<sum;
    
    
    return 0;
}