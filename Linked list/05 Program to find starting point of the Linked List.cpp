/******************************************************************************


                     Abhijeet Lodh Solving Linked List from Lover Babbar 450 DSA
        
                    Question: Program to find starting point of the Linked List
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}
Node* detectLoop(Node* head)
{	Node* temp = new Node;
	while (head != NULL) {
if (head->next == NULL) {
			return NULL;
		}
		if (head->next == temp) {
			break;
		}
		Node* nex = head->next;
		head->next = temp;
		head = nex;
	}

	return head;
}

int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	Node* res = detectLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->key;

	return 0;
}
