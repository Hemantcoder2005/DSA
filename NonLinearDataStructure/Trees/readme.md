# Trees
- Let's Imagine a Tree What does it have?
- - Root
- - leafs
- - Branches

- Similarily, In computer science we have Tree (see above)
- <image height="400px" style = "position :relative" src = "src\1.png"></image>

- So tree have root and each node connecting to each other
- let's take an real example of tree : 
- <image height="400px" style = "position :relative" src = "src\2.png"></image> 
- Fun Activity (if you are on windows open up your cmd prompt and run below command) : 
```bat
tree
```
- - Cmd will List a tree data structure of windows file
- - Cancel it by ```cntrl + c```  because there are millions of files 😂😂 
# Binary Tree
- A binary tree where each node have atmost 2 children
- <image height="400px" style = "position :relative" src = "src\3.png"></image> 
## Binary Search Tree (BST)
- BST is a kind of binary tree in which all the data which is smaller should be at left side and bigger should be at right side.
- <image height="400px" style = "position :relative" src = "https://th.bing.com/th/id/OIP.rTKXBurTgrkBgk9C0AK-eQAAAA?rs=1&pid=ImgDetMain"></image> 
- Let's build a tree class
- C++ Implementation [Code](#https://github.com/Hemantcoder2005/DSA/tree/main/NonLinearDataStructure/Trees/build.cpp)
```c++
struct TreeNode{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int data;
};
```
