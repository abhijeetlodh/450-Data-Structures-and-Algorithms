/******************************************************************************
 Remove Duplicates (easy)
Given an array of sorted numbers, remove all duplicates from it. 
You should not use any extra space; after removing the duplicates in-place 
return the new length of the array.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
   int nextNonDuplicate = 1; 
    for (int i = 1; i < n; i++) {
      if (arr[nextNonDuplicate - 1] != arr[i]) {
        arr[nextNonDuplicate] = arr[i];
        nextNonDuplicate++;
      }
    }

    return nextNonDuplicate;
}

int main()
{
int arr[] = {2, 3, 3, 3, 6, 9, 9};
int n = 6;
cout << solve(arr, n);

    return 0;
}
