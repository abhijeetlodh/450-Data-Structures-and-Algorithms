/******************************************************************************
Words Concatenation (hard) #

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> findWordConcatenation(string str, vector<string> V)
{
    vector<int> ans;
    
    unordered_map<string, int> map;
    for(auto i: V)
    map[i]++;
    int wordscount = V.size();
   int wordlength = V[0].size();
    
    for(int i = 0 ; i <= str.length() - wordscount * wordlength; i++)
    {
        unordered_map<string, int> wordseen;
        for(int j = 0 ; j < wordscount; j++)
        {
            int nextword = i + j * wordlength;
            string word = str.substr(nextword, wordlength);
            if(map.find(word) == map.end())
            {
                break;
            }
            wordseen[word]++;
            if(wordseen[word] > map[word])
            {
                break;
            }
            if(j + 1 == wordscount){
                ans.push_back(i);
            }
        }
    }
    
    return ans;
}

int main()
{
  vector<int> result =
      findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

    return 0;
}
