/******************************************************************************


                     Abhijeet Lodh Solving Search-Sort from Lover Babbar 450 DSA
        
Question: Search in  a rotated sorted arrray

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;


        int search(int nums[], int n, int target) {
        int v = -1;
        for(int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                v = i;
                }
            // target = -1;
        }
        return v;
    }
int main()
{
   int n, i, T;
        cin >> n>> T;
        int nums[n];
        for (i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << search(nums, n, T);
        // cout << "\n"
    return 0;
}

// Sample input
// 5
// 0
// 4
// 5
// 6
// 7
// 0
// 1
// 2
