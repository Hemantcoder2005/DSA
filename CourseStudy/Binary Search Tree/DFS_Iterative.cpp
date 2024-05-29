#include <iostream>
#include <stack>
#include <vector>
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


vector<int> PreOrder(Node* root){
    stack<Node*> s;
    vector<int> ans;
    s.push(root);

    while (!s.empty())
    {
        int n=s.size();
        for (int i = 0; i < n; i++)
        {
            Node* temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            if(temp->right!=NULL){
                s.push(temp->right);
            }

            if(temp->left!=NULL){
                s.push(temp->left);
            }

        }
        
}
    return ans;
}


void printVector(vector<int> ans){
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
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

    
    printVector(PreOrder(root));
    
    
    
    return 0;
}