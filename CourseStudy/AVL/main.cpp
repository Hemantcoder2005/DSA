#include <iostream>
#include <queue>

using namespace std;

struct AVLNode {
    int key;
    AVLNode* left = NULL;
    AVLNode* right = NULL;
    int height = 1;
};

int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

AVLNode* createNode(int key) {
    AVLNode* Node = new AVLNode();
    Node->key = key;
    return Node;
}

int getBalanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* leftRotate(AVLNode* &y) {
    AVLNode* x = y->right;
    AVLNode* T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* rightRotate(AVLNode* &x) {
    AVLNode* y = x->left;
    AVLNode* T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
AVLNode* PerformRotations(AVLNode* node,int key){
     if (node == NULL) return node; 
    // Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotations needed, return the unchanged node pointer
    return node;
}
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node=PerformRotations(node,key);
}
AVLNode * minValueAVLNode(AVLNode* node) 
{ 
    AVLNode* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
 
    return current; 
} 
AVLNode* deleteNode(AVLNode* root, int key) 
{ 
    if (root == NULL) 
        return root; 
 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
 
    else
    { 
       
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            AVLNode *temp = root->left ? root->left : root->right; 
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
            *root = *temp;  
            delete temp; 
        } 
        else
        { 
            AVLNode* temp = minValueAVLNode(root->right); 
            root->key = temp->key; 
 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
 
    if (root == NULL) return root; 
 
    root->height = max(getHeight(root->left), getHeight(root->right))+1; 
 
    int balance = getBalanceFactor(root); 
 
    // Left Left Case 
    if (balance > 1 && 
        getBalanceFactor(root->left) >= 0) 
        return rightRotate(root); 
 
    // Left Right Case 
    if (balance > 1 && 
        getBalanceFactor(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && 
        getBalanceFactor(root->right) <= 0) 
        return leftRotate(root); 
 
    // Right Left Case 
    if (balance < -1 && 
        getBalanceFactor(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
 
    return root; 
} 
void levelOrder(AVLNode* root) {
    if (root == NULL) {
        return;
    }

    queue<AVLNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            AVLNode* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << endl; // Print newline after printing nodes at the current level
    }
}

int main() {
    AVLNode* root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6,7};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        root = insert(root, arr[i]);
         levelOrder(root);
         cout<<"\n";
    }
   
    return 0;
}
