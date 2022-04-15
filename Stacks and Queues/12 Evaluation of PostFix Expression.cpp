/******************************************************************************


Abhijeet Lodh solving Stacks and Queues from Love Babbar 450 DSA Sheet
Question:  Evaluation of PostFix Expression

*******************************************************************************/
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int PostFixEvaluation(string s){
    stack<int> st;
    for(int i = 0; i  < s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2 =st.top();
            st.pop();
            int op1  =st.top();
            st.pop();
            
            switch(s[i])
            {
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
        
    }
    return st.top();
}

int main()
{
    cout << PostFixEvaluation("46+2/5*7+")<<endl;
    return 0;
}
