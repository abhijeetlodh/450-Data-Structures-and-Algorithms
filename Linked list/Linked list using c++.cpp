/******************************************************************************

Linked list using c++ 
1
4
3
5
5
6
6
7
7



*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node){
    while(node!= NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

class Solution{
    public:
    Node* newNode;
    Node* insertAtBegining(Node *head, int x){
        newNode = new Node(x);
        if(head == NULL)
        return newNode;
        else{
            newNode->next = head;
            return newNode;
        }
    }
    Node* insertAtEnd(Node* head, int x){
          if(head == NULL){
              newNode = new Node(x);
              head = newNode;
              return head;
          }
          Node* temp = head;
          while(temp->next != NULL ){
              temp  = temp->next;
          }
          newNode = new Node(x);
          temp->next = newNode;
          return head;
    }
};

int main()
{
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;
       Node* head  =NULL;
       for(int i = 0 ; i < n; ++i){
           int data, indicator;
           cin >>data>>indicator;
           Solution obj;
           if(indicator)
           head = obj.insertAtEnd(head, data);
           else
           head = obj.insertAtBegining(head, data);
       }
       printList(head);
        }
        return 0;
}
