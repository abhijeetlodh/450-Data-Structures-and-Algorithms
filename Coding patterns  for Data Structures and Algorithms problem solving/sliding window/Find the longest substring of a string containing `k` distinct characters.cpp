/******************************************************************************

Find the longest substring of a string containing `k` distinct characters
Given a string and a positive number k, find the longest substring of the string 
containing k distinct characters. If k is more than the total number of distinct characters
in the string, return the whole string

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string sovle(string str, int k)
{
    string ans = "";
    int mstart = 0;
    int mend = 0;
    int len = 0;
    unordered_map<char, int> M;
    int windowStart = 0;
    int windowEnd = 0;
    for(; windowEnd < str.size(); windowEnd++)
    {
        M[str[windowEnd]]++;
        if((int)M.size() > k)
        {
            M[str[windowStart]]--;
            if( M[str[windowStart]] == 0) M.erase(str[windowStart]);
            windowStart++;
        }
        if(windowEnd - windowStart + 1 > len)
        {
            mstart = windowStart;
            mend = windowEnd;
            len = windowEnd - windowStart + 1;
        }
    }
    
    return str.substr(mstart, windowEnd - windowStart );
}

int main()
{
    
  cout << sovle("abcbdbdbbdcdabd",2) << endl;
  cout << sovle("abcbdbdbbdcdabd",3) << endl;
  cout << sovle("abcbdbdbbdcdabd",5) << endl;


    return 0;
}
