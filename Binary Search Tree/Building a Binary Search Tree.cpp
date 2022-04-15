/******************************************************************************


                     Abhijeet Lodh Solving Binary Search Tree from Lover Babbar 450 DSA
        
                    Question: Building a Binary Search Tree
*******************************************************************************/
#include <iostream>  
#include <stdlib.h>  
using namespace std;  
struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  
Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  
  
void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
  
    inorder(root->left);  
    cout<< root->data << "   ";  
    inorder(root->right);  
}  

Node* insertBST(Node* root, int item)  
{  
    if (root == NULL)  
        return create(item);  
    if (item < root->data)  
        root->left = insertBST(root->left, item);  
    else  
        root->right = insertBST(root->right, item);  
  
    return root;  
}  
int main()
{

Node *root = NULL;
root = insertBST(root, 5);
insertBST(root, 1);
insertBST(root, 3);
insertBST(root, 4);
insertBST(root, 2);
insertBST(root, 7);

inorder(root);
cout<< endl;
    return 0;
}
  
