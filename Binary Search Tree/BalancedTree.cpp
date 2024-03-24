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

int MaximumHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftLen=MaximumHeight(root->left);

     if(leftLen==-1){
        return -1;
    }
    int rightLen=MaximumHeight(root->right);
    
    if( rightLen==-1){
            return -1;
        }
   
    if(abs(leftLen-rightLen)<2){
        return 1+max(MaximumHeight(root->left),MaximumHeight(root->right));
    }
    return -1;
    
    
}
int main() {
    // Your code here
    Node* root = new Node(1);
    Node* ch1 = new Node(2);
    Node* ch2 = new Node(3);
    Node* ch11 = new Node(4);
    Node* ch12 = new Node(5);
    Node* ch21 = new Node(6);
    Node* ch22 = new Node(7);
    Node* ch31 = new Node(8);

    // Create an unbalanced binary tree
    root->left = ch1;
    root->right = ch2;
    ch1->left = ch11;
    ch1->right = ch12;
    ch2->left = ch21;
    ch2->right = ch22;
    ch22->left = ch31;
    cout<<MaximumHeight(root);
    return 0;
}