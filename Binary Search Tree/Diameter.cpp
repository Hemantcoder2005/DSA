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

int getdiameter(Node* root,int &diameter){
    if(root==NULL){
        return 0;
    }
    int left=getdiameter(root->left,diameter);
    int right=getdiameter(root->right,diameter);
    diameter=max(diameter,right+left);
    return 1+max(left,right);
    
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

    Node* ch31=new Node(8);

    root->left=ch1;
    root->right=ch2;

    ch1->left=ch11;
    ch1->right=ch12;

    ch2->left=ch21; 
    ch2->right=ch22;

    ch22->left=ch31;

    int diameter=0;
    getdiameter(root,diameter);
    cout<<diameter;
    return 0;
}