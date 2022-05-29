/******************************************************************************

print all subsequence using recursion
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


void func(int idx,vector<int> &v, int arr[], int n){
            // cout << "Test" << endl;
    if(idx == n){
        for(auto it: v){
            cout << it << " ";
        }
        if(v.size() == 0){
            cout << "{}" << " ";
        }
        cout << endl;
        return;
    }
// I don't pick one number 
func(idx+1, v, arr, n);
v.push_back(arr[idx]);
func(idx+1, v, arr, n);
v.pop_back();
}

int main()
{
   int arr[] = {3,1,2};
   int n =  3;
   vector<int> v;
   func(0, v, arr, n);

    return 0;
}
