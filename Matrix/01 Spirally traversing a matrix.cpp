/******************************************************************************


Abhijeet Lodh solving Matrix from Love Babbar 450 DSA Sheet
Question: Spirally traversing a matrix 

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int n,m; // n will have rows have m will be number of colums
    cin >> n >> m; // input row and colums
    int a[n][m]; // Matrix of n rows and m colums
    for(int i =0; i < n; i++){ // this for loop will work with every ith row
        for(int j = 0; j < m; j++) // this loop will work with ever jth colum of ith row
        {
            cin>> a[i][j];  // Taking input values of ith row and jth colum in the Array[Matrix]
        }
    }
 
 // Spiral Order print
 
int row_start = 0; // row will be begin from here
int row_end = n - 1; // we are initializing row with 0th hence we have to explicit final value
int column_start = 0; // column will begin from here 
int column_end = m - 1; // column will end on the last - 1 value as it was initialized from 0
while(row_start <= row_end and column_start <= column_end) // we have to work over this process till row and column start and end are equal
{
    //for row_start
    for(int col = column_start; col <= column_end; col++) // here I am looping the columns 
    cout<< a[row_start][col] << " "; // this will print first row and all columns
    
    row_start++; // next row
    
    //for column end
    for(int row = row_start; row <= row_end; row++)  // looping the rows
    cout << a[row][column_end] << " "; // this will print last column with different rows
    
    column_end--; // decrement the last column
    //for row end
    for(int col  = column_end; col >= column_start; col--) // bring the column_end to column_start
    cout << a[row_end][col] << " "; // printing last row with columns from end to start
    row_end--; // decrement last row
    
    //for column_start
    for(int row = row_end; row >= row_start; row--) // pointing from the last row to the first one 
    cout << a[row][column_start] << " "; // this will print the varying row values with the starting column
    column_start++; // next column
    
}
 
    return 0;
}

// Below is sample input for the above Spiral Order Matrix just select all lines and press CTRL + /
// 4
// 4
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8 
// 9
// 10
// 11
// 12 
// 13
// 14
// 15
// 16 