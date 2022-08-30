/******************************************************************************

Permutation in a String (hard) #

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


bool findPermutation(string str, string pattern)
{
 int windowStart = 0, matched = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    
    
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
        
        charFrequencyMap[rightChar]--;
        if (charFrequencyMap[rightChar] == 0) {  
          matched++;
        }
      }

      if (matched == (int)charFrequencyMap.size()) {
        return true;
      }

      if (windowEnd >= pattern.length() - 1) {  
        char leftChar = str[windowStart++];
        if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
          if (charFrequencyMap[leftChar] == 0) {
            matched--;  
          }
          
          charFrequencyMap[leftChar]++;
        }
      }
    }

    return false;
}

int main()
{
   cout << findPermutation("oidbcaf", "abc") << endl;

    return 0;
}
