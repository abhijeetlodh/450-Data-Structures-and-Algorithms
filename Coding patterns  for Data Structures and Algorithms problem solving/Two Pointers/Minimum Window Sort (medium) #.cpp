/******************************************************************************

Minimum Window Sort (medium) #
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int sort(vector<int> arr)
{
    int count = 0;
    
    int low  = 0;
    int high = arr.size()-1;
    while(low < arr.size()-1 and arr[low] <= arr[low + 1])
    {
        low++;
    }
    if(low == arr.size() - 1) return 0;
    while(high > 0 and arr[high] >= arr[high - 1]) high--;
    count = INT_MIN;
    int  subarrayMin = INT_MAX;
    for(int k = low; k <= high; k++)
    {
        count = max(count, arr[k]);
        subarrayMin = max(subarrayMin, arr[k]);
    }
    while (low > 0 && arr[low - 1] > subarrayMin) {
      low--;
    }
    
      while (high < arr.size() - 1 && arr[high + 1] < count) {
      high++;
    }

    return high - low + 1;
}

int main()
{
    
     cout << sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << sort(vector<int>{1, 2, 3}) << endl;
  cout << sort(vector<int>{3, 2, 1}) << endl;
  
    return 0;
}