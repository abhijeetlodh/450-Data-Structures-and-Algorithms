/******************************************************************************

Longest Substring with K Distinct Characters (medium)
      
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int solve(string str, int k)
{
 int LongestSubStringWithKDistinctCharacters = INT_MIN;
 int dist = 0;
 int windowStart = 0;
 
 unordered_map<char, int> M;
 
 for(int windowEnd = 0; windowEnd < str.size(); windowEnd++)
 {
    char rightChar = str[windowEnd];
    M[rightChar]++;
    while((int)M.size() > k)
    {
        char leftChar = str[windowStart];
        M[leftChar]--;
        if(M[leftChar] == 0) M.erase(leftChar);
        windowStart++;
    }
    
    LongestSubStringWithKDistinctCharacters = max(LongestSubStringWithKDistinctCharacters, windowEnd - windowStart + 1);
 }
 
 
    return LongestSubStringWithKDistinctCharacters;
}

int main()
{
    int k = 2;
   string str = "araaci";
    cout <<  solve(str, k);
    
    return 0;
}
