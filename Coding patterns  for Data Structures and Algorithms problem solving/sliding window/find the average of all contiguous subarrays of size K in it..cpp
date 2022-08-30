/******************************************************************************

      find the average of all contiguous subarrays of size ‘K’ in it.
      
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<double> solve(vector<int> v, double k)
{
    vector<double> ans(v.size() - k);

    double windowSum = 0;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < v.size(); windowEnd++)
    {
        windowSum += v[windowEnd];
        
        if(windowEnd >=  k - 1)
        {
            ans[windowStart] = windowSum/k;
            windowSum -= v[windowStart];
            windowStart++;
        }
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double k = 5;
    vector<int> v  = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    vector<double> ans = solve(v, k);
    
    for(auto f: ans)
    cout << f << "  ";
   

    return 0;
}
