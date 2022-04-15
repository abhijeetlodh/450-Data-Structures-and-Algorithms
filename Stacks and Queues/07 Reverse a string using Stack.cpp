/******************************************************************************


Abhijeet Lodh solving Stacks and Queues from Love Babbar 450 DSA Sheet
Question: Reverse a string using Stack 

*******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;


void ReverseSentence(string s)
{
    stack<string> st;
    for(int i =0; i < s.length(); i++)
    {
        string word = " ";
        while(s[i]!=' ' && i < s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty())
    {
        cout << st.top()<<" ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Hey, How do you doing?";
    ReverseSentence(s);
    return 0;
}




/* GeeksforGeeks 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
char* reverse(char *S, int n)
{
    //code here
    int i;
     for (i = 0; i < n/2; i++)
        swap(&S[i], &S[n-i-1]);
        
        return S;
}
 


*/