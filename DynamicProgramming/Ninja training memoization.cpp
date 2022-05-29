/******************************************************************************

Dynamic Programming 
Ninja Training
Memoization
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define loop(j) for(int i = 0; i <= j; i++)
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last] != -1) return dp[day][last];
    if(day == 0){
        int maxi = 0;
        loop(2){
            if( i != last)
            maxi = max(maxi, points[0][i]);
        }
        return dp[day][last]  = maxi;
    }
    
    int maxi = 0 ;
    loop(2){
        if(i != last){
            int act = points[day][i] + f(day-1, i, points, dp);
            maxi = max(maxi, act);
        }
    }
    return dp[day][last] = maxi;
}

int NinjaTrain(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}

int main(){
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int n = points.size();
    cout << NinjaTrain(n, points);
}