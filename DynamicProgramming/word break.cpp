/******************************************************************************
INPUT:
1
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
*******************************************************************************/
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &W) {
          int n = s.size();
        bool dp[n+1][n+1];
        unordered_set<string> myset;
        for(auto word: W)
            myset.insert(word);
        for(int len = 1; len <= n; ++len)
        {
            int start = 1;
            int end = len;
            while(end <= n)
            {
                string temp = s.substr(start-1, len);
                if(myset.find(temp) != myset.end())
                    dp[start][end] = true;
                else{
                    bool flag = false;
                    for(int i = start; i < end; ++i)
                        if(dp[start][i] and dp[i+1][end])
                        {
                            flag = true;
                            break;
                        }
                        dp[start][end] = flag;
                    
                }
                start += 1;
                    end += 1;
            }
        }
         return dp[1][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends