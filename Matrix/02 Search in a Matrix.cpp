/******************************************************************************


                     Abhijeet Lodh solving Matrix from Love Babbar 450 DSA Sheet
                Question:   Search in a Matrix

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == target)
            {
                flag = true;
}
        }
    }
        return flag;
    }
int main()
{
   int n,m; cin >> n >> m;
   vector <vector<int>> arr(n, vector<int> (m));
   for(int i = 0; i <n; i++)
   {
       for(int j = 0; j < m; j++)
       cin >> arr[i][j];
   }
   int x; cin >> x;
   cout << searchMatrix(arr, x) << endl;

    return 0;
}

// 4
// 4
// 1
// 3
// 5
// 7
// 10
// 11
// 16
// 20
// 23
// 30
// 34
// 60
// 3
