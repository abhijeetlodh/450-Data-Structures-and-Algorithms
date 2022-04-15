/******************************************************************************


                     Abhijeet Lodh Solving Search-Sort from Lover Babbar 450 DSA
        
Question: Find first and last positions of an element in a sorted array

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
    
int solve1(int arr[], int n , int x, int tog )
{
      int low = 0;
      int high = n-1;
      int ans = -1;
      while(low<=high)
      {
          int mid = (low + high ) / 2;
          if(arr[mid] < x){
              low = mid + 1;
          }
          else if(arr[mid] > x)
          {
              high  = mid - 1;
          }
          else{
              ans = mid;
              if(tog == -1)
              high = mid + tog;
              else low = mid + tog;
          }
      }
    return ans;
}
int main()
{
    
    
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
       int idx1 = solve1(arr, n, x, -1) ;
        int idx2 = solve1(arr,  n, x, 1) ;
        if(idx1 == -1 )  
        idx2 = -1;
        cout<<idx1<<" "<<idx2<<endl;
    return 0;
}