/******************************************************************************

Longest Subarray with Ones after Replacement (hard)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k){
    int windowStart = 0, maxLength = 0, maxOnesCount = 0;
    
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      if (arr[windowEnd] == 1) {
        maxOnesCount++;
      }

if (windowEnd - windowStart + 1 - maxOnesCount > k) {
        if (arr[windowStart] == 1) {
          maxOnesCount--;
        }
        windowStart++;
      }

      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

int main()
{
    cout << solve(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
    return 0;
}
