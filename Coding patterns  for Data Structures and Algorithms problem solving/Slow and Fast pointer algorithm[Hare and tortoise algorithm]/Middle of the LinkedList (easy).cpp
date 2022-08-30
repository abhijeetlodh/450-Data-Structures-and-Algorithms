/******************************************************************************
Middle of the LinkedList (easy)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

int Middle(node* root)
{
    node* slow = root;
    node* fast = root;
    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void insert(node** root, int item)
{
    node* temp = new node;
    temp->data = item;
    temp->next = *root;
    *root = temp;
}

node* buildList(int arr[], int n){
    node* root = NULL;
    for(int i = n-1; i >= 0 ; i--)
    {
        insert(&root, arr[i]);
    }
    return root;
}

int main()
{
   int arr[] = {1,2,3,4,5};
   int n = 5;
   node* root = buildList(arr, n);
   cout << Middle(root);
   
    

    return 0;
}
