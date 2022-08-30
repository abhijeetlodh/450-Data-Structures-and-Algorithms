/******************************************************************************
LinkedList from Array (easy)
*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node* next;
};

void insert(node** root, int item){
    node* temp = new node;
    temp->data = item;
    temp->next = *root;
    *root = temp;
}

void display(node* root)
{
    while(root){
    cout << root->data << " -> ";
    root  = root->next;
    }
}

node* arrToList(vector<int> arr, int n)
{
    node* root = NULL;
    for(int i = n-1; i >= 0; i--)
    {
        insert(&root, arr[i]);
    }
    return root;
}

int main()
{

vector<int> arr = {1, 2, 3, 4, 5};
node* k = arrToList(arr, arr.size());
display(k);

    return 0;
}
