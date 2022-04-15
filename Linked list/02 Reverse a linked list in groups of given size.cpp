/******************************************************************************


                     Abhijeet Lodh Solving Linked List from Lover Babbar 450 DSA
        
                    Question: Reverse a Linked List in groups of given size 
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
stack<node*> mystack;
    struct node* current = head;
    struct node* prev = NULL;
  
    while (current != NULL) {
        int count = 0;
        while (current != NULL && count < k) {
            mystack.push(current);
            current = current->next;
            count++;
        }
  
        while (mystack.size() > 0) {
            if (prev == NULL) {
                prev = mystack.top();
                head = prev;
                mystack.pop();
            } else {
                prev->next = mystack.top();
                prev = prev->next;
                mystack.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}
  void push(struct node** head_ref, int new_data)
{
    struct node* new_node = 
          (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
};

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        int k;
        cin>>k;
            Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
    return(0);
}