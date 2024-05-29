#include <iostream>
using namespace std;
struct TreeNode{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int data;
};
int main(){

    // Creating a tree Node
    TreeNode* root= new TreeNode();
    root->data = 3;

    cout<<root->data;
}