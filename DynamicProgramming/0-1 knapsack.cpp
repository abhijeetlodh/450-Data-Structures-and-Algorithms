/*
4 20
10 2 1 3
10 5 10 10
*/
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
//recursion
// int knapSack(int W, int wt[], int val[], int n, vector<vector<int>> & dp)
// {
// 	if(W== 0 || n == 0) return 0;
// 	if(wt[n-1] > W) return knapSack(W, wt, val, n-1, dp);
// 	else return max(
// 	val[n-1] + knapSack(W-wt[n-1], wt, val, n-1, dp), 
// 	knapSack(W, wt, val, n-1, dp)
// 	);
// }
//memoization
int knapSack(int W, int wt[], int val[], int n, vector<vector<int>> & dp)
{
	if(dp[n][W] != -1) return dp[n][W]; 
	if(W== 0 || n == 0) return 0;
	if(wt[n-1] > W) return dp[n][W] = knapSack(W, wt, val, n-1, dp);
	else return dp[n][W] = max(
	val[n-1] + knapSack(W-wt[n-1], wt, val, n-1, dp), 
	knapSack(W, wt, val, n-1, dp)
	);
}
  

int main() {
	int obj, cap;
	cin >> obj >> cap;
	int profit[obj];
	int wt[obj];
	for(int i = 0 ; i < obj; i++)
	cin >> profit[i];
	for(int i = 0 ; i < obj; i++)
	cin >> wt[i];
	//   cout << knapSack(cap, wt, profit, obj, dp);
	//tabulation
	
 vector<vector<int>> dp(obj, vector<int>(cap + 1));

    for (int i = 0; i < obj; i++) {
      dp[i][0] = 0;
    }
    for (int c = 0; c <= cap; c++) {
      if (wt[0] <= c) {
        dp[0][c] = profit[0];
      }
    }
    for (int i = 1; i < obj; i++) {
      for (int c = 1; c <= cap; c++) {
        int profit1 = 0, profit2 = 0;
        if (wt[i] <= c) {
          profit1 = profit[i] + dp[i - 1][c - wt[i]];
        }
        profit2 = dp[i - 1][c];
        dp[i][c] = max(profit1, profit2);
      }
    }

    cout << dp[obj - 1][cap];
	return 0;
}