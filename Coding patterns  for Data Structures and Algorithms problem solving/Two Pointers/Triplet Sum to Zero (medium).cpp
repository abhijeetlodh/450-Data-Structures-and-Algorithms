/******************************************************************************

    Triplet Sum to Zero (medium)
    Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


void solveVect(vector<int> a, int targetSum, int left, vector<vector<int>>& ans)
{
    int right = a.size()-1;
    while(left <= right){
        int csum = a[left] + a[right];
        if(csum == targetSum)
        {
            ans.push_back({-targetSum, a[left], a[right]});
            left++;
            right--;
        }
        else if(targetSum > csum)
        {
            left++;
        }
        else{
            right--;
        }
    }
}

vector<vector<int>> ans(vector<int> a)
{
    sort(a.begin(), a.end());
    
    vector<vector<int>> ans;
    for(int i = 0; i < a.size()-1; i++)
    {
        if(i > 0 and a[i] == a[i+1])
        {
            continue;
        }
        solveVect(a, -a[i], i+1, ans);
    }
    
    return ans;
}


int main()
{
    vector<vector<int>> res = ans(vector<int>{-3, 0, 1, 2, -1, 1, -2});
    for(auto f: res)
   { for(auto x: f)
    cout << x << " ";
       cout << endl;
   }
    
    return 0;
}
