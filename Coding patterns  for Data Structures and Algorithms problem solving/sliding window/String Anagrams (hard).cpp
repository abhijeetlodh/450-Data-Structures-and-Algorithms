// String Anagrams (hard) #
// Given a string and a pattern, find all anagrams of the pattern in the given string.
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string st1, string st2){
    vector<int> ans;
    unordered_map<char, int> M;
    int windowstart, windowend, matched;
    windowend  = windowstart = matched = 0;
    for(auto i: st2) M[i]++;
    for(; windowend < st1.size(); windowend++)
    {
        if(M.find(st1[windowend]) != M.end())
        {
            M[st1[windowend]]--;
            if(M[st1[windowend]] == 0) 
            matched++;
        }
        if(matched == (int)M.size()) ans.push_back(windowstart);
        if(windowend >= st2.size()-1){
            char left = st1[windowstart++];
            if(M.find(left) != M.end())
            {
               
                if(M[left] == 0) matched--;
                M[left]++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> ans = solve("abbcabc", "abc");
    vector<int> ans1 = solve("ppqp", "pq");
    for(auto f: ans)
    cout << f << " -> ";
    cout << endl;
    for(auto f1: ans1)
    cout << f1 << " -> ";

    return 0;
}
