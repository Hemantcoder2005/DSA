#include <iostream>
#include <vector>

using namespace std;

// Build Tree
struct Node{
    Node* left=NULL;
    Node* right=NULL;
    Node* parent=NULL;
    int val;
};
class Queue{
    public:
        vector<Node*> q;
    bool empty(){
        return q.size()==0;
    }

    void enqueue(Node* val){
        q.push_back(val);
    }

    Node* dequeue(){
        if(this->empty()){
            return NULL;
        }
        Node* temp=q[0];
        q.erase(q.begin());
        
        return temp;
    }
};



void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    PreOrder(root->left);
    
    cout<<root->val<<" ";
    PreOrder(root->right);

}

void PostOrder(Node* root){
    if(root==NULL){
        return;
    }
    PreOrder(root->left);
    
    cout<<root->val<<" ";
    PreOrder(root->right);

}

Node* RecursiveSearch(Node* root,int key){
    if(root==NULL || root->val==key){
        return root;
    }

    if(root->val>key){
        RecursiveSearch(root->left,key);
    }else{
        RecursiveSearch(root->right,key);
    }
}

Node* IterativeSearch(Node* root,int key){
    while (root!=NULL && root->val==key)
    {
         if(root->val>key){
            root=root->left;
         }else{
            root=root->left;
         }
    }
    return root;
}

void Min(Node* root,int &minVal){
    if(root==NULL){
        return;
    }
    minVal=root->val;
    root=root->left;
    Min(root,minVal);
}

void Max(Node* root,int &maxVal){
    if(root==NULL){
        return;
    }
    maxVal=root->val;
    root=root->right;
    Max(root,maxVal);
}

Node* Succesor(Node* root,Node* x){
    return RecursiveSearch(root,x->val)->right;
}
Node* Predecessor(Node* root,Node* x){
    if(root==x){
        return NULL;
    }
    return RecursiveSearch(root,x->val)->left;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->val = key;
        temp->parent = root; // Set the parent pointer of the new node
        return temp;
    }

    if (root->val > key) {
        root->left = insert(root->left, key); // Pass root as parent
    } else if (root->val < key) {
        root->right = insert(root->right, key); // Pass root as parent
    }
    return root; // Return root in all cases
}

void levelOrder(Node* root){
    if(root==NULL){
        cout<<"BST is Empty";
        return;
    }
    Queue* q=new Queue();
    q->enqueue(root);

    while (!q->empty())
    {
        Node* frontNode=q->dequeue();
        cout<<frontNode->val<<" ";
        
        if(frontNode->left!=NULL){
            q->enqueue(frontNode->left);
        }
        if(frontNode->right!=NULL){
            q->enqueue(frontNode->right);
        }
    }
    
}

int main() {
    Node* root=NULL;
    vector<int> arrBST={4,2,6,1,5,7};
    

    for (auto node:arrBST)
    {
        root=insert(root,node);
    }

    cout<<"PreOrder = ";
    PreOrder(root);

    cout<<"\nPostorder = ";
    PostOrder(root);

    cout<<"\nInorder = ";
    InOrder(root);

    cout<<"\nSuccessor of root = "<<Succesor(root,root)->val;
    cout<<"\nPredecossr of root = "<<Predecessor(root,root);

    int Max_Val,Min_Val;
    Min(root,Min_Val);Max(root,Max_Val);
    cout<<"\nMin = "<<Min_Val;
    cout<<"\nMax = "<<Max_Val;
    
    cout<<"\nLevel Order = ";
    levelOrder(root);
    return 0;
}