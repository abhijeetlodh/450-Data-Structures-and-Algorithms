/******************************************************************************
Subarrays with Product Less than a Target (medium)

Given an array with positive numbers and a target number, 
find all of its contiguous subarrays whose product is less than the target number.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;




vector<vector<int>>  searchTriplets(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
   int product = 1;
   int left = 0;
   for(int right = 0 ; right  < arr.size(); right++)
   {
       product *= arr[right];
       while(product >= target and left < arr.size())
       product /= arr[left++];
       deque<int> tempList;
       for(int i = right ; i >= left; i--)
       {
           tempList.push_front(arr[i]);
           vector<int> resultVec;
           
           move(begin(tempList), end(tempList), back_inserter(resultVec));
           ans.push_back(resultVec);
       }
   }
   
   return ans;
}

int main()
{
    vector<vector<int>> ans;
    ans =  searchTriplets(vector<int>{2, 5, 3, 10}, 30);
    for(auto x: ans){
    for(auto f: x)
    {
        // cout << f << " ";
    
    }
        cout <<endl;
        
    }

    return 0;
}
