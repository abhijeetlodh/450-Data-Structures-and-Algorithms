/******************************************************************************


                     Abhijeet Lodh Solving Search-Sort from Lover Babbar 450 DSA
        
                    Question: Middle of Three
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int middle(int A, int B, int C){
         if ((A < B && B < C) || (C < B && B < A))
       return B;
 
    else if ((B < A && A < C) || (C < A && A < B))
       return A;
 
    else
       return C;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  


// Sample input
// 1
// 978
// 518
// 300
