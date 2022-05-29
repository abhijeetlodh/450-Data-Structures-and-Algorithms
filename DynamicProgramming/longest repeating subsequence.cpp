/******************************************************************************

Longest Repeating Subsequence

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

string sol(string s)
{
    int n = s.length();
    string s2 = s;
vector<vector<string>>dp(n+1, vector<string>(n+1));
for(int i = 0; i <= n; i++)
for(int j = 0; j<= n; j++)
{
    if(i == 0 || j == 0)
    dp[i][j] = "";
    else if(s[i-1] == s[j-1] and i-1 != j-1)
    dp[i][j] = dp[i-1][j-1] + s[i-1];
    else dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j]:dp[i][j-1];
}
return dp[n][n];
}

int main()
{
  string s1 = "AABB";
  cout << sol(s1);

    return 0;
}
