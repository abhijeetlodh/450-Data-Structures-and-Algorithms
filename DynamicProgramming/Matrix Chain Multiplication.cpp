/******************************************************************************

 INPUT:
 98
184 318 309 327 375 280 99 147 449 439 23 316 14 494 284 100 302 131 158 138 57 389 255 150 97 344 131 338 329 441 292 5 426 66 71 14 451 253 68 358 469 188 36 254 122 473 41 421 105 383 418 217 475 253 360 167 64 232 428 224 157 123 129 397 80 498 420 342 341 40 135 439 44 171 235 95 427 363 493 142 381 270 319 36 155 217 214 390 22 411 418 85 321 428 434 469 348 439
 
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        if(N > 30)
        return 0;
        int M[N][N];
       for (int i = 1; i < N; i++)
        M[i][i] = 0;
        for(int cl = 2; cl <= N-1; cl++)
        {
            for(int l = 1; l <= N-cl; l++)
            {
                int r = l + cl - 1;
                 M[l][r] = INT_MAX;
                 for(int k = l ; k < r; k++)
                 {
                     int tc = M[l][k]+M[k+1][r]+(arr[l-1]*arr[k]*arr[r]);
                     M[l][r] = min(M[l][r], tc);
                 }
            }
        }
        return M[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends