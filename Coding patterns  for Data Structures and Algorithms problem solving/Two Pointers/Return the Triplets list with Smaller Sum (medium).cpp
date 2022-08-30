/******************************************************************************
Return the Triplets list with Smaller Sum (medium)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int searchTripletsSolution(vector<int> arr, int target, int first, vector<vector<int>>& ans)
{
    int count  = 0;
    int right = arr.size()-1;
    int left = first + 1;
    while(left < right)
    {
        if(arr[left] + arr[right] < target)
        {
            for(int i = right; i > left; i--)
           ans.push_back({arr[left],  arr[first], arr[i]});
            left++;
        }
        else right--;
    }
    return count;
}

vector<vector<int>>  searchTriplets(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int count = 0 ;
    for(int i = 0 ; i < arr.size()-2; i++)
    {
        count += searchTripletsSolution(arr, target - arr[i], i, ans);
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans;
    ans =  searchTriplets(vector<int>{-1, 0, 2, 3}, 3);
    for(auto x: ans){
    for(auto f: x)
    {
        cout << f << " ";
    
    }
        cout <<endl;
        
    }

    return 0;
}
