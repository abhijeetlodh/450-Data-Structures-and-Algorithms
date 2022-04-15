/******************************************************************************


                     Abhijeet Lodh Solving Linked List from Lover Babbar 450 DSA
        
                    Question: Linked List Basics
*******************************************************************************/
#include <iostream> //headers
using namespace std; // standard attributions
class node{  // node is not built int Hence I am building
  public:   
  int data;   // Data in the node 
  node* next; // address of the next node(pointer)
  node(int val){  // constructor
      data = val; 
      next = NULL;
  }
};          // class complete

// Adding a Node at head(beginning)
void insertAtHead(node* &head, int val){  // function to add at head
    node* n  =new node(val);
    n->next = head;
    head = n;
}
void insertAtTail(node* &head, int val) // function to add at Tail of the Linked List
{
    node* n = new node(val);
    if(head == NULL)  // checking list is Empty?
    {
        head = n; // Empty ? return the the node n
        return;
    }
    node* temp = head;    //pointing to the first node
    while(temp->next!=NULL){ // until the next receives the value Null run the loop
        temp=temp->next;  // assign the value held by the next to temp 
    }
    temp->next=n;   
}

void display(node* head){   // Time to Print Linked list
    cout << "Linked list is " << endl; // output statements
    node* temp= head; // temp pointing to the head
    while(temp!=NULL){  // run the loop till the end of Linked List
        cout<<temp->data<<"->";  // Print the Data 
        temp=temp->next;  // increament the temp 
    }
    cout<<"NULL"<<endl; // end of Linked list
}

//searching

bool search(node* head, int key){ // True or False to find the key is present in the Linkedlist or not
    node* temp= head; // temp pointing to the beginning 
    while(temp!=NULL){ // till the end of Linkedlist
        if(temp->data==key){ // data assigned to temp matched with key hence it is found 
            return true; // willl return binary true i.e. 1
        }
        temp = temp-> next; // increament temp 
    }
    return false; // willl return binary false i.e. 0
}

void deletion(node* &head, int val){   // Function to delete  a specific element in Linked list

    node* temp = head;
    while(temp->next->data!=val){
                temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
int main()
{

node* head = NULL; // initialized
insertAtTail(head,1); // insert 1
insertAtTail(head,2); // insert 2
insertAtTail(head,3); // insert 3
display(head); // Print function
insertAtHead(head,4); // insert at the beginning
display(head); // Print function
cout<< search(head,4) << endl; // Print element is present or not
deletion(head,3); // deleting the element
display(head);

    return 0;
}