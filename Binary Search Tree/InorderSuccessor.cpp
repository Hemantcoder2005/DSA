#include<iostream>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;

    Tree(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Tree* InorderSuccessor(Tree* root, int k) {
    Tree* successor = NULL;
    while (root != NULL) {
        if (root->data <= k) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main(){
    Tree* root = new Tree(5);

Tree* l = new Tree(3);
Tree* r = new Tree(7);

Tree* ll = new Tree(2);
Tree* lr = new Tree(4);

Tree* lll = new Tree(1);

Tree* rl = new Tree(6);
Tree* rr = new Tree(9);

Tree* rrl = new Tree(8);
Tree* rrr = new Tree(10);

    root->left = l;
    root->right = r;

    l->left = ll;
    l->right = lr;

    ll->left = lll;

    r->left = rl;
    r->right = rr;

    rr->left = rrl;
    rr->right = rrr;


    cout<<InorderSuccessor(root,1)->data;

}