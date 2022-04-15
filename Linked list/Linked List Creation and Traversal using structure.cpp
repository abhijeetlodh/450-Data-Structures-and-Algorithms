/******************************************************************************


                     Abhijeet Lodh Solving Linked List from Lover Babbar 450 DSA
        
                    Question: Linked List Creation and Traversal using structure
*******************************************************************************/

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
        cout << ptr->data << "->";
        ptr= ptr->next;
    }
    cout <<"NULL";
}


int main()
{
  struct Node*  head;
  struct Node*  Second;
  struct Node*  Third;
  struct Node*  Fourth;
head = (struct Node*)malloc(sizeof(struct Node));
Second = (struct Node*)malloc(sizeof(struct Node));
Third = (struct Node*)malloc(sizeof(struct Node));
Fourth = (struct Node*)malloc(sizeof(struct Node));

// Link first and Second nodes
head->data = 7;
head->next = Second;
// Link Second and Third Node
Second->data = 11;
Second->next = Third;
// Link Third and Fourth Node
Third->data = 13;
Third->next = Fourth;
// Terminate the Linked List
Fourth->data = 66;
Fourth->next = NULL;

linkedListTraversal(head);
    return 0;
}
