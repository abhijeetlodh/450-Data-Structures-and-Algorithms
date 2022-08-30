/******************************************************************************

Palindrome LinkedList (medium) #

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
  int data;
  node* next;
};

 node *reverse(node *head) {
    node *prev = nullptr;
    while (head != nullptr) {
      node *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }

void insert(node** root, int item)
{
    node* temp = new node;
    temp->data  = item;
    temp->next = *root;
    *root = temp;
}

node* buildList(vector<int> arr, int n)
{
    node* root = nullptr;
    
    for(int i = n-1; i >= 0; i--)
    {
        insert(&root, arr[i]);
    }
    
    return root;
}

bool Palindrome(node* root){
    if(!root) return false;
    node* slow = root;
    node* fast = root;
    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    node* cmp = reverse(slow);
    node* cmpCopy = cmp;
    while(root and cmp)
    {
        if(root->data != cmp->data) return false;
        cmp = cmp->next;
        root = root->next;
        
    }
reverse(cmpCopy);
if(!root || !cmp )
    return true;
    
    return false;
}

int main()
{
    vector<int> arr = {2,4,6,4,2};
    node* root = buildList(arr, arr.size());
   cout << Palindrome(root);
   
    return 0;
}
