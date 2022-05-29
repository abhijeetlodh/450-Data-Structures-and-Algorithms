/*
 Dynamic Programming: circular House Robber 2 

*/
#include <bits/stdc++.h>
using namespace std;
long long int solve(int n, vector<int>&temp){
	int prev = temp[0];
	int prev2 = 0;
	for(int i = 1; i < n; i++){
		int first = temp[i];
		if(i > 1)
			first += prev2;
			int cur = 0+prev;
		int sol = max(first, prev);
		prev2  = prev;
		prev = sol;
	}
	long long int a = prev;
	return a;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1, temp2;
	int n = valueInHouse.size();
	for(int i = 0 ; i < n; i++){
		if(i != 0) temp1.push_back(valueInHouse[i]);
		if(i != n-1) temp2.push_back(valueInHouse[i]);
	}
	return max(solve(n, temp1), solve(n, temp2));
}


int main()
{
    // vector<int> h{1, 2, 4};
    // vector<int> h{1,3,2,1};
    vector<int> h{2,3,2};
    int n = h.size();
    vector<int> dp(n, -1);
    // cout << solve(n, h, dp);
    cout << houseRobber(h);
    return 0;
}
