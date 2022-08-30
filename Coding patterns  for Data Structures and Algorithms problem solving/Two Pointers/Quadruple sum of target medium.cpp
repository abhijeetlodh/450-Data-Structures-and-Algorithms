/******************************************************************************

Quadruple Sum to Target (medium) #

Given an array of unsorted numbers and a target number, 
find all unique quadruplets in it, whose sum is equal to the target number.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void searchPairs(vector<int> arr, int first, int second, int target, vector<vector<int>>& ans)
{
    int left = first + 1;
    int right = arr.size()-1;
    while(left < right)
    {
        int sum = arr[left] + arr[right] + arr[first] + arr[second];
        if(sum  == target)
        {
            ans.push_back({arr[left], arr[right], arr[first], arr[second]});
            left++;
            right--;
            while(left < right and arr[left] == arr[left-1]) left++;
            while(left < right and arr[right] == arr[right+1]) right++;
        }
        else if(sum < target)
        right--;
        else left++;
    }
}

vector<vector<int>> searchQuadruplets(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0 ; i < arr.size()-3; i++)
    {
        if(i > 0 and arr[i] == arr[i-1] ) continue;
        for(int j = i+1; j < arr.size()-2; j++)
        {
            if(j > i+1 and arr[j] == arr[j+1] ) continue;
            searchPairs(arr, i, j, target, ans);
        }
    }
    return ans;
}


int main()
{
    
      vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = searchQuadruplets(vec, 1);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout <<"\n second INput " << endl;

  vec = {2, 0, -1, 1, -2, 2};
  result = searchQuadruplets(vec, 2);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }

    return 0;
}
