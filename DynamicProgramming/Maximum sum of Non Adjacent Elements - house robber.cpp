/*
Maximum Sum of Non-Adjacent Elements -  House Robber
dynamic programming

*/
#include <bits/stdc++.h>
using namespace std;
// Recursion
// int solve(int idx, vector<int>& h){
//   if(idx == 0) return h[idx];
//   if(idx < 0) return 0;
//   int pick = solve(idx-2, h) + h[idx];
//   int notPick = solve(idx-1, h);
//   return max(pick, notPick);
// }
// memoization TC: O(N)  and SC: O(N)

/* 
int solve(int idx, vector<int>& h, vector<int>& dp){
  if(dp[idx] != -1) return dp[idx];
  if(idx == 0) return h[idx];
  if(idx < 0) return 0;
  int left = h[idx] + solve(idx-2, h, dp);
  int right = 0 + solve(idx-1, h, dp);
  return dp[idx] = max(left, right);
}

*/

// Tabulation approach TC: O(N)  SC:  O(N)

// int solve(int n, vector<int>& h, vector<int>& dp){
//     dp[0] = h[0];
//     for(int i = 1; i < n; i++){
//         int take = h[i];
//         if(i>1)
//         take += dp[i-2];
//         int notPick = 0+dp[i-1];
//         dp[i] = max(take, notPick);
//     }
//     return dp[n-1];
// }

// space optimation Tabulation approach TC: O(N)  SC:  O(N)

int solve(int n, vector<int>& h){
    int prev  = h[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int pick = h[i];
        if(i>1)
        pick += prev2;
        int nonPick = 0 + prev;
        int curi_i  = max(pick, nonPick);
        prev2 = prev;
        prev = curi_i;
    }
    return prev;
    
}

int main()
{
    // vector<int> h{1, 2, 4};
    vector<int> h{2,1,4,9};
    int n = h.size();
    vector<int> dp(n, -1);
    // cout << solve(n, h, dp);
    cout << solve(n, h);
    return 0;
}
