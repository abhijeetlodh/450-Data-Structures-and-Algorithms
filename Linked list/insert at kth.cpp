#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next = NULL;
    Node(int a){
        data = a;
        next = NULL;
    }
};

void print(Node* root){
    while(root){
        cout << "->" << root->data;
        root = root->next;
    }
    cout << endl;
}
 Node* insertAtKth(Node* root, int k, Node* nVar){
    Node* temp = nVar;
    int idx = 0;
    Node* temp2 = root;
    if(k == 1){
        temp->next = temp2;
        temp2 = temp;
        return temp2;
    }
    while(temp2){
        idx++;
        if(idx == k-1)
        break;
        temp2= temp2->next;
    }
    nVar->next = temp2->next;
    temp2->next = nVar;
    return root;
}

void insert(Node** root, int a){
    Node* temp  = new Node(a);
    temp->next = *root;
    *root = temp;
}

Node* buildLL(int arr[], int a){
    Node* root = NULL;
    for(int i  = a-1; i >= 0; i--)
    insert(&root, arr[i]);
    return root;
}

int main()
{
    int arr[] = {1,2,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root  = buildLL(arr, n);
    print(root);
    Node* nVar = new Node(3);
    Node* sol = insertAtKth(root, 1, nVar);
    print(sol);
    Node* nVar2 = new Node(13);
    Node* sol2 = insertAtKth(root, 3, nVar2);
    print(sol2);
    return 0;
}