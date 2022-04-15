/******************************************************************************


                     Abhijeet Lodh solving Matrix from Love Babbar 450 DSA Sheet
                Question:   Rotate a Matrix by clockwise 90deg.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int col, row, F, X, Y, T;
    cin >> row >> col;
    int arr[row][col];
    int temp[row][col];
    for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
    cin>> arr[i][j];
    }
    }
     for(int i = 0; i < row; i++)
    {
        for(int j = col - 1; j >= 0; j--)
      {
          cout << arr[j][i] << " ";
      }
      cout << endl;
    }

    return 0;
}

//sample input
// 3
// 3
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
