/*
Frog with K JUMPS
dynamic programming

*/
#include <bits/stdc++.h>
using namespace std;

// memoization TC: O(N*k) and SC: O(N)
/*
int solve(int idx, vector<int>& h, vector<int>& dp, int k){
    if(idx == 0) return 0;
    if(dp[idx] != -1 ) return dp[idx];
    int minSTEP = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(idx - i >= 0)
        {
            int sol = solve(idx-i, h, dp, k) + abs(h[idx] - h[idx-i]);
            minSTEP = min(minSTEP, sol);
        }
    }
    return dp[idx] = minSTEP;
}
*/

// Tabulation approach TC: O(N*K)  SC: O(N)

int solve(int n, vector<int>& h, vector<int>& dp, int k){
   dp[0] = 0;
   for(int i = 1; i < n; i++){
       int minSTEP = INT_MAX;
       for(int j = 1; j <= k; j++){
           int sol = dp[i-j] + abs(h[i] - h[i-j]);
           minSTEP = min(minSTEP, sol);
       }
       dp[i] = minSTEP;
   }
   return dp[n-1];
}


int main()
{
    vector<int> h{30,10,60 , 10 , 60 , 50};
    int n = h.size();
    vector<int> dp(n, -1);
    cout << solve(n, h, dp, 2);
    return 0;
}
