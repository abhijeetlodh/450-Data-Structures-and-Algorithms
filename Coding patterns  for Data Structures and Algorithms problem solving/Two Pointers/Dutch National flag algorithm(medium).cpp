/******************************************************************************
Dutch National Flag Problem (medium)

Given an array containing 0s, 1s and 2s, sort the array in-place. 
You should treat numbers of the array as objects, 
hence, we can’t count 0s, 1s, and 2s to recreate the array.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& a, int b, int c)
{
    int temp= a[b];
    a[b] = a[c];
    a[c] = temp;
}

 void solve(vector<int>& a)
{
    vector<int> ans;
    
    int low = 0;
    int high  = a.size()-1;
    
    for(int i = 0 ; i<= high;)
    {
        if(a[i] == 0)
        {
            swap(a, i, low);
            i++;
            low++;
        }
        else if(a[i] == 1)
     {   i++;
         
     }
        else{
            swap(a, i, high);
            high--;
        }
    }
}

int main()
{
    vector<int> v = {1, 0, 2, 1, 0};
    
     solve(v);
    for(auto x: v)
    cout << x << " ";
    
    return 0;
}