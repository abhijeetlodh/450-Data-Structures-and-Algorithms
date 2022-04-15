/******************************************************************************

                    Abhijeet Lodh solving Arrays from Love Babbar 450 DSA Sheet

                    Question: Kth smallest element
*******************************************************************************/
// I am using QuickSelect Method

#include <climits>
#include <iostream>
using namespace std;
 
int partition(int arr[], int low, int high);
int Kthsmall(int arr[], int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);

        if (pos - low == k - 1)
            return arr[pos];
        if (pos - low > k - 1) 
            return Kthsmall(arr, low, pos - 1, k);
 
        return Kthsmall(arr, pos + 1, high, k - pos + low - 1);
    }
 
    return INT_MAX;
}
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int arr[], int low, int high)
{
    int x = arr[high], i = low;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
 
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element = " << Kthsmall(arr, 0, n - 1, k);
    return 0;
}