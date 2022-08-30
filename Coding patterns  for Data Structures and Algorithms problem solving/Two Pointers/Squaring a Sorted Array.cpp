/******************************************************************************

               Squaring a Sorted Array (easy)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int n)
{
    
    vector<int> squares(n);
    int highestSquareIdx = n - 1;
    int left = 0, right = n - 1;
    while (left <= right) {
      int leftSquare = arr[left] * arr[left];
      int rightSquare = arr[right] * arr[right];
      if (leftSquare > rightSquare) {
        squares[highestSquareIdx--] = leftSquare;
        left++;
      } else {
        squares[highestSquareIdx--] = rightSquare;
        right--;
      }
    }
    return squares;
}

int main()
{
  
  
  int arr[]  = {-2, -1, 0, 2, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> result;
  result = solve(arr, n);
  for(auto x: result)
  {
      cout  << x << " ";
  }
  
//   arr[]  = {-3, -1, 0, 1, 2};
//   n = sizeof(arr)/sizeof(arr[0]);
//   result = solve(arr, n);
//   for(auto x: result)
//   {
//       cout  << x << " ";
//   }

    return 0;
}
