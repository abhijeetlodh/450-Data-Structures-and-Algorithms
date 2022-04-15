/******************************************************************************


                     Abhijeet Lodh Solving Binary Search Tree from Lover Babbar 450 DSA
        
                    Question: Search and Delete in Binary Search Tree
*******************************************************************************/
#include <iostream>  
#include <stdlib.h>  
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* searchInBst(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key)
    return root;
    if(root->data > key){
        return searchInBst(root->left, key);
    }
    return searchInBst(root->right, key);
}
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
//Delete in Bst
Node* DeleteInBST(Node* root, int key)
{
    if(key < root->data){
        root->left = DeleteInBST(root->left, key);
    }
    else if(key > root->data){
        root->right = DeleteInBST(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
             Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = DeleteInBST(root->right, temp->data);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
    
}
int main()
{

Node *root = new Node(4);
root->left = new Node(2);
root->right = new Node(5);
root->left->left = new Node(1);
root->left->right = new Node(3);
root->right->left = new Node(0);
root->right->right = new Node(7);
if(searchInBst(root, 5) == NULL){
    cout << 0;
}
else cout << 1;
cout<< endl;

inorder(root);
root = DeleteInBST(root, 2);
cout << endl;
inorder(root);
    return 0;
}