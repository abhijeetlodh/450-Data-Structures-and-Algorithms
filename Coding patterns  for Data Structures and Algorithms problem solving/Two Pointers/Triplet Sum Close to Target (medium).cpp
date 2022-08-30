/******************************************************************************
Triplet Sum Close to Target (medium)
Given an array of unsorted numbers and a target number, 
find a triplet in the array whose sum is as close to the target number as possible, 
return the sum of the triplet. If there are more than one such triplet, 
return the sum of the triplet with the smallest sum.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;



int solve(vector<int> arr, int target)
{
    vector<vector<int>>  ans;
    sort(arr.begin(), arr.end());
    int M = INT_MAX;
    for(int i = 0 ; i  < arr.size()-2; i++)
    {
        int left = i+1;
        int right = arr.size()-1;
        while(left < right)
        {
                    int targetDiff = target - arr[i] - arr[left] - arr[right];
                      if (targetDiff == 0) {            //  we've found a triplet with an exact sum
          return target - targetDiff;  // return sum of all the numbers
        }
 if (abs(targetDiff) < abs(M)) {
          M = targetDiff;  // save the closest difference
        }
   if (targetDiff > 0) {
          left++;  // we need a triplet with a bigger sum
        } else {
          right--;  // we need a triplet with a smaller sum
        }
        }
        
    }
    return target - M;
}

int main()
{
    vector<int> arr = {-3, -1, 1, 2};
    int target = 1;
    cout << solve(arr, target) << endl;
    
    return 0;
}
