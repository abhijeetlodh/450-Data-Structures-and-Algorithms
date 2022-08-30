/******************************************************************************

Longest Substring with Same Letters after Replacement (hard)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(string str, int k){
    int len  = 0;
    int maxRepeatLetterCount = 0;
    int windowStart = 0;
    unordered_map<char, int> letterFrequencyMap;
    // cout << "\n";
    for(int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightchar = str[windowEnd];
    // cout << "\n rightchar " << str[windowEnd] <<  "\n";
        
        letterFrequencyMap[rightchar]++;
    // cout << "\n letterFrequencyMap[rightchar] " << letterFrequencyMap[rightchar] << "  \n";
        maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightchar]);
    // cout << "\n maxRepeatLetterCount = max [ " << "  " << maxRepeatLetterCount << " letterFrequencyMap[rightchar] = " << letterFrequencyMap[rightchar] << "]  \n";
        if(windowEnd - windowStart + 1 - maxRepeatLetterCount > k)
        {
        //   cout << "\n windowEnd " << windowEnd << " windowStart " << windowStart << " + 1" << " - maxRepeatLetterCount " << maxRepeatLetterCount << " isgreater? k" << k << "\n";
            // cout << "\n before letterFrequencyMap[str[windowStart]] " << letterFrequencyMap[str[windowStart]] << endl;
            letterFrequencyMap[str[windowStart]]--;
            // cout << "\n after letterFrequencyMap[str[windowStart]] " << letterFrequencyMap[str[windowStart]] << endl;
            windowStart++;
            // cout << " \n windowStart++ = " << windowStart << "\n";
        }
        len = max(len, windowEnd - windowStart + 1);
        // cout << "\n length " << len << endl;
    }
    return len;
}

int main()
{
  
    cout << "aabccbb " << solve("aabccbb", 2) << endl;
    cout << "abbcb " << solve("abbcb", 1) << endl;
    cout << "abccde " << solve("abccde", 1) << endl;
    return 0;
}
