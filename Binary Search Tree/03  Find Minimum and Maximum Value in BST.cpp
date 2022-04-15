/******************************************************************************


                     Abhijeet Lodh Solving Binary Search Tree from Lover Babbar 450 DSA
        
                    Question: Find Minimum and Maximum Value in BST
*******************************************************************************/
#include <bits/stdc++.h> 
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


int minValue(struct Node* node) 
{ 
struct Node* current = node; 
  while (current->left != NULL) 
{ 
    current = current->left; 
} 
return(current->data); 
} 

int maxValue(struct Node* node) 
{ 
struct Node* current = node; 
  while (current->right != NULL) 
{ 
    current = current->right; 
} 
return(current->data); 
} 

int main()
{

Node *root = new Node(5);
root->left = new Node(2);
root->right = new Node(7);
root->left->left = new Node(1);
root->left->right = new Node(3);
root->right->left = new Node(6);
root->right->right = new Node(8);
cout << "\n Minimum value in BST is " << minValue(root); 
cout << "\n Minimum value in BST is " << maxValue(root); 

    return 0;
}