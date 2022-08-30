/******************************************************************************
 Given an array of sorted numbers and a target sum, find a pair in the array whose 
 sum is equal to the given target.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(int arr[], int n, int target)
{
    int windowStart = 0;
   int windowEnd = n-1;
   while(windowStart < windowEnd)
   {
        if(arr[windowStart] + arr[windowEnd] == target)
        {
           return make_pair(windowStart, windowEnd);
        }
        else if(arr[windowStart] + arr[windowEnd] > target)
      {  windowEnd--;}
        else{ windowStart++;
        }
}

}

int main()
{
int arr[] = {1,2,3,4,5,6};
int n = 6;
pair<int, int> p = solve(arr, n, 6);

cout << p.first << " " << p.second;

    return 0;
}
