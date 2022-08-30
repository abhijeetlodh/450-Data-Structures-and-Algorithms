/******************************************************************************

Maximum Sum Subarray of Size K (easy)
      
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Brute Force (N*K)
// int solve(vector<int> v, int k)
// {
//     int maxSum = 0;
//     for(int i = 0; i <= v.size() - k; i++)
//     {
//         int temp = 0;
//         for(int j = i ; j < i + k; j++)
//         {
//             temp += v[j];
//         }
//         maxSum = max(maxSum, temp);
//     }
//     return maxSum;
// }
int solve(vector<int> v, int k)
{
    int maxSum = 0;
    int windowSum = 0;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < v.size(); windowEnd++)
    {
        windowSum += v[windowEnd];
        if(windowEnd >= k-1)
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= v[windowStart];
            windowStart++;
        }
    }
    return maxSum;
}

int main()
{
    int k = 3;
    vector<int> v  = {2, 1, 5, 1, 3, 2};
    cout <<  solve(v, k);
    
    return 0;
}
