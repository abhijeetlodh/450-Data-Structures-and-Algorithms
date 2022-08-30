/******************************************************************************
Triplets with Smaller Sum (medium)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int searchTripletsSolution(vector<int> arr, int target, int first)
{
    int count  = 0;
    int right = arr.size()-1;
    int left = first + 1;
    while(left < right)
    {
        if(arr[left] + arr[right] < target)
        {
            count += right - left;
            left++;
        }
        else right--;
    }
    return count;
}

int searchTriplets(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int count = 0 ;
    for(int i = 0 ; i < arr.size()-2; i++)
    {
        count += searchTripletsSolution(arr, target - arr[i], i);
    }
    return count;
}

int main()
{
    cout << searchTriplets(vector<int>{-1, 0, 2, 3}, 3);

    return 0;
}
