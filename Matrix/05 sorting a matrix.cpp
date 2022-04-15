/******************************************************************************


                     Abhijeet Lodh solving Matrix from Love Babbar 450 DSA Sheet
                Question:   Sort a Matrix

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int arr[N][N];
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    cin >> arr[i][j];
 
    int temp[N*N];
    int k = 0;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    temp[k++] = arr[i][j];
    
    sort(temp, temp+k);
    k = 0;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    arr[i][j] = temp[k++];    
            
for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    cout << arr[i][j] << " ";
    cout << endl;
    return 0;
}
// sample input
// 3
// 1
// 5
// 3
// 2
// 8
// 7
// 4
// 6
// 9