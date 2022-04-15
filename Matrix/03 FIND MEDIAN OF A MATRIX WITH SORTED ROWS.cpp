/******************************************************************************


Abhijeet Lodh solving Matrix from Love Babbar 450 DSA Sheet
Question: FIND MEDIAN OF A MATRIX WITH SORTED ROWS
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

 
   int median(vector<vector<int> > &A) {
    int min = A[0][0], max = A[0][0];
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][m-1] > max) max = A[i][m-1];
    }

    int element = (n * m + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0];
        if (cnt < element)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> A[i][j];
        }
    }
cout <<    median(A);
    
    return 0;
}


// sample input
// 3
// 3
// 1
// 3
// 5
// 2
// 6
// 9
// 3
// 6
// 9

