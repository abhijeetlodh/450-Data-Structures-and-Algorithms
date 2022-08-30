/******************************************************************************
Smallest Window containing Substring (hard) #
14:28 - 15:40
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string solve(const string &str, const string &pattern) {
    int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
cout << " windowStart " << windowStart << endl;
cout << " matched " << matched << endl;
cout << " minLength " << minLength << endl;
cout << " subStrStart " << subStrStart << endl;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
cout << " rightChar " << rightChar << endl;
      if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
          
        charFrequencyMap[rightChar]--;
cout << " charFrequencyMap[rightChar " << charFrequencyMap[rightChar] << endl;
        if (charFrequencyMap[rightChar] >= 0) {
cout << " charFrequencyMap[rightChar > = 0 True"   << endl;
          matched++;
          cout << "  matched  " << matched << endl;
        }
      }

       while (matched == pattern.length()) {
          cout << " matched == pattern.length() = True " << endl;
        if (minLength > windowEnd - windowStart + 1) {
          cout << "  minLength > windowEnd - windowStart + 1 " << endl;
          minLength = windowEnd - windowStart + 1;
          cout << "  minLength  " << minLength << " windowEnd - windowStart + 1 " << windowEnd - windowStart + 1 << endl;
          subStrStart = windowStart;
          cout << "  subStrStart = " << subStrStart << endl;
        }

        char leftChar = str[windowStart++];
          cout << "  leftChar  " << leftChar << endl;
        if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
          cout << " charFrequencyMap.find(leftChar) != charFrequencyMap.end() True " << endl;
         
          if (charFrequencyMap[leftChar] == 0) {
              cout << " charFrequencyMap[leftChar] == 0 True " << endl; 
            matched--;
              cout << "  matched " <<  matched << endl; 
          }
          charFrequencyMap[leftChar]++;
              cout << "  charFrequencyMap[leftChar] " <<  charFrequencyMap[leftChar] << endl; 
        }
      }
    }
              cout << "  minLength " <<  minLength << endl; 
              cout << " str.length()  " <<  str.length() << endl; 
              cout << "  str.substr(subStrStart, minLength) " <<  str.substr(subStrStart, minLength) << endl; 

    return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
  }

int main()
{

string str1 = solve("aabdec", "abc"); // abdec
// string str2 = solve("abdabca", "abc"); //abc
// string str3 = solve("adcad", "abc"); //
// cout << str1 << " " << str2 << " " << str3 << " ";
cout << str1 ;

    return 0;
}
