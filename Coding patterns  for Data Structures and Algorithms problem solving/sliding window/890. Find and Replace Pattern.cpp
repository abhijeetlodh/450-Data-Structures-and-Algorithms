/******************************************************************************

          890. Find and Replace Pattern
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<string> solve(vector<string>& words, string pattern, int n )
{
             vector<string> ans;
    unordered_map<char,char> m;
    
    for(int k=0; k<pattern.length(); k++)
    {
        m[pattern[k]]++;
    }
    
    int lengthPattern = m.size();
    
    for(int i=0; i<words.size(); i++)
    {
        m.clear();
        string temp="";
      
        for( int j=0; j<words[i].length(); j++)
        {
            if(m.find(words[i][j])==m.end())
            {
                m[words[i][j]]=pattern[j];
            }
            temp+=m[words[i][j]];
        }
		int lengthString = m.size();
        if(temp == pattern && lengthString == lengthPattern) ans.push_back(words[i]);
    }
    return ans; 
}

int main()
{
   vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
   vector<string> ans = solve(words, "abb", 6);
   for(auto i: ans)
   cout <<"\n answer: " << i << " ";
   
    return 0;
}
