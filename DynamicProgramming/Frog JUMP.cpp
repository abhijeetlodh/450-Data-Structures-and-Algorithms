/*
Memoisation
#include<bits/stdc++.h>
int f(int i, vector<int>& heights, vector<int> &dp){
if(i == 0)
	return 0;
	if(dp[i] != -1) return dp[i];
	int left = f(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
	int right = INT_MAX;
	if(i > 1)
	right = f(i-2, heights, dp) + abs(heights[i] - heights[i-2]);
	return dp[i] = min(left, right);
	}
int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
cout << frogJump(n, height);
return 0;
}

*/

/******************************************************************************

            Frog JUMP 
            Dynamic Programming 
            Tabulation

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &h)
{
	int prev  = 0;
	int prev2 = 0;
	for(int i = 1 ; i < n; i++){
		int curi;
		int left = prev + abs(h[i] - h[i-1]);
		int right = INT_MAX;
		if(i > 1)
			right = prev2 + abs(h[i] - h[i-2]);
		curi = min(left, right);
		prev2 = prev;
		prev = curi;
	}
	return prev;
}


int main() {

//   vector<int> height{10,20,30,40};
  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
cout << frogJump(n, height);
return 0;
}
