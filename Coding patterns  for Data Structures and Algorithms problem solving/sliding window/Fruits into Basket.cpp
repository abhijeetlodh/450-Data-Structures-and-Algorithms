/******************************************************************************

 Fruits into Baskets (medium)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(char arr[], int n){
    int solution;
    unordered_map<char, int> M;
    int windowStart = 0;
    int sum = INT_MIN;
    for(int windowEnd = 0 ; windowEnd < n; windowEnd++)
    {
        char rightChar = arr[windowEnd];
        M[rightChar]++;
        while((int)M.size() > 2)
        {
            M[arr[windowStart]]--;
            if(M[arr[windowStart]] == 0) M.erase(arr[windowStart]);
            windowStart++;
        }
        sum = max(sum, windowEnd - windowStart + 1);
    }
    
    return sum;
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'B', 'B', 'C'};
    int n = 6;
    cout << solve(arr, n);
    return 0;
}
