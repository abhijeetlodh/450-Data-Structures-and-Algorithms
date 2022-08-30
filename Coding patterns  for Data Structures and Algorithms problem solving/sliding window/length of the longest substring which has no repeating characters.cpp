/******************************************************************************

No-repeat Substring (hard)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(string str){
 
 int sum = 0;
    int windowstart = 0;
    unordered_map<char, int> map;
    for(int windowEnd = 0 ; windowEnd < str.size(); windowEnd++)
    {
    //   map[str[windowEnd]]++;
       if(map.find(str[windowEnd]) != map.end())
       {
       windowstart = max(windowstart, map[str[windowEnd]] + 1);
       }
       map[str[windowEnd]] = windowEnd;
       sum = max(sum, windowEnd - windowstart + 1);
    }
    return sum;
}

int main()
{
  
    cout << "aabccbb " << solve("aabccbb") << endl;
    cout << "abccde " << solve("abccde") << endl;
    cout << "abbbb " << solve("abbbb") << endl;
    return 0;
}
