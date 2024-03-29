#include <iostream>

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

void printPreOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
    
}

void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
    
}

void printpostOrder(Node* root){
    if(root==NULL){
        return;
    }
    printpostOrder(root->left);
    printpostOrder(root->right);
    cout<<root->data<<" ";
    
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

    root->left=ch1;
    root->right=ch2;

    ch1->left=ch11;
    ch1->right=ch12;

    ch2->left=ch21;
    ch2->right=ch22;

    cout<<"Preorder = ";
    printPreOrder(root);
    
    cout<<"\n";

    cout<<"Inorder = ";
    printInOrder(root);
    
    cout<<"\n";

    cout<<"Postorder = ";
    printpostOrder(root);
    return 0;
}