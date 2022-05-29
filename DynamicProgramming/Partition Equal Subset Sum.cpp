#include <bits/stdc++.h>
using namespace std;


bool subsetPartition(vector<int> nums){
      int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            total += nums[i];
        if(total%2 != 0) return false;
        int k = total/2;
        vector<bool> prev(k+1, false);
        prev[0] = true;
        if(nums[0] <= k ) prev[nums[0]] = true;
        for(int i = 1; i < n; i++){
           vector<bool>  cur(k+1, false);
            cur[0] = true;
            for(int j = 1; j <= k; j++)
            {
                bool ntake = prev[j];
                bool take = false;
                if(nums[i] <= j)
                    take = prev[j - nums[i]];
                cur[j] = ntake || take;
            }
            prev = cur;
        }
        return prev[k];
}
int main(){
    vector<int> arr {1,5,11,5};
    int n = 4;
    cout << subsetPartition(arr, n);
    return 0;
}