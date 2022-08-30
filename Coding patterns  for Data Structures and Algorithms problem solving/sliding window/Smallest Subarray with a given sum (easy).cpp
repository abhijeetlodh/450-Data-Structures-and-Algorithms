/******************************************************************************

Smallest Subarray with a given sum (easy)
      
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> v, int k)
{
  int smallestSubarray = 200;
  int sumSoFar = 0;
  int windowStart = 0;
  for(int windowEnd = 0; windowEnd < v.size(); windowEnd++)
  {
      sumSoFar += v[windowEnd];
      
      while(sumSoFar >= k)
      {
      smallestSubarray = min(smallestSubarray, windowEnd - windowStart + 1);
    
          sumSoFar -= v[windowStart];
          windowStart++;
      }
  }
  

    return smallestSubarray;
}

int main()
{
    int k = 7;
    vector<int> v  = {2, 1, 5, 2, 3, 2};
    cout <<  solve(v, k);
    
    return 0;
}
