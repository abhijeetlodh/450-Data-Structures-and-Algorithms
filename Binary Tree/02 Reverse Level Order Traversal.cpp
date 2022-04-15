/******************************************************************************


                     Abhijeet Lodh Solving Binary Tree from Lover Babbar 450 DSA
        
                    Question: Reverse Level Order Traversal
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
            
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        if(currVal != "N") {
                
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}

vector<int> reverseLevelOrder(Node *node)
{

     vector<int> ans;
        if(!node) return ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* t = q.front();
            ans.push_back(t->data);
            if(t->right) q.push(t->right);
            if(t->left) q.push(t->left);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
}