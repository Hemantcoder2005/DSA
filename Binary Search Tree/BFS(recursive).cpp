#include <iostream>
#include <vector>
#include <queue>
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


vector<vector<int>> BFS(Node* root){
    vector<vector<int>> ans;
  if(root==NULL){
        return {{}};
    }
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {   
        int size= q.size();
        vector<int> level;
        for (int  i = 0; i <size; i++)
        {   
            Node* front=q.front();
            q.pop();
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }

            level.push_back(front->data);
        }
        
        ans.push_back(level);
    }
    return ans;
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


    //Breadth for Search
    vector<vector<int>> ans=BFS(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int  j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
  
    

    return 0;
}