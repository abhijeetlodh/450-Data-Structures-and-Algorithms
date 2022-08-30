/******************************************************************************
 Remove key Duplicates (easy)
Given an unsorted array of numbers and a target ‘key’, 
remove all instances of ‘key’ 
in-place and return the new length of the array.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int key)
{
  int nextElement = 0; 
    for (int i = 0; i < n; i++) {
      if (arr[i] != key) {
        arr[nextElement] = arr[i];
        nextElement++;
      }
    }

    return nextElement;
}

int main()
{
    // 2 6 10 9
int arr[] = {3, 2, 3, 6, 3, 10, 9, 3};
int n = 8;
cout << solve(arr, n, 3);

    return 0;
}
