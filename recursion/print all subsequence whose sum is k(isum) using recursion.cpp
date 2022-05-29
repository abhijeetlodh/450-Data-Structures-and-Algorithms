/******************************************************************************

print all subsequence whose sum is k(isum) using recursion
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


void func(int idx, int isum, vector<int> &v, int arr[], int n, int sum ){
    if(idx == n){
        if(isum  == sum){
            for(auto it : v){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    isum +=arr[idx];
    func(idx+1, isum, v, arr, n, sum);
    v.pop_back();
    isum -=arr[idx];
    func(idx+1, isum, v, arr, n, sum);
}

int main()
{
   int arr[] = {1,2,1};
   int n =  3;
   int sum  = 2;
   vector<int> v;
   func(0, 0, v, arr, n, sum);

    return 0;
}
