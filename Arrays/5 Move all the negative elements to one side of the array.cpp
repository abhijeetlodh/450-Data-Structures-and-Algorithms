/******************************************************************************

                    Abhijeet Lodh solving Arrays from Love Babbar 450 DSA Sheet

                    Question:Move all the negative elements to one side of the array 

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
 
void EndOfArray(int arr[], int n)
{
    int temp[n];
 
    int j = 0; 
    for (int i = 0; i < n ; i++)
        if (arr[i] >= 0 )
            temp[j++] = arr[i];
 
    if (j == n || j == 0)
        return;
 
    for (int i = 0 ; i < n ; i++)
        if (arr[i] < 0)
            temp[j++] = arr[i];
 

    memcpy(arr, temp, sizeof(temp));
}
 
int main()
{
    int arr[] = {-12, -13, -5, -7, -3, -6, 11, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    EndOfArray(arr, n);
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    return 0;
}
