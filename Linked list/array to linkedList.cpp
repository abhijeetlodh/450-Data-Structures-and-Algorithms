#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
void printLinkedList(node* h){
    while(h != NULL){
        cout << "->" << h->data;
h = h->next;
    }
}

void insertLinkedList(node** root, int a){
    node* temp = new node;
    temp->data = a;
    temp->next = *root;
    *root = temp;
}
void buildLInkedList(int arr[], int n){
    node* root = NULL;
    for(int i = n-1; i >= 0 ; i--)
    insertLinkedList(&root, arr[i]);
    printLinkedList(root);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n =  7;
    buildLInkedList(arr, n);
    return 0;
}