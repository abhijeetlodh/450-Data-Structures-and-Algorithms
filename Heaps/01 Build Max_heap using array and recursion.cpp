/******************************************************************************


Abhijeet Lodh solving Heap from Love Babbar 450 DSA Sheet
Question: 01 Build Max_heap using array and recursion

*******************************************************************************/
#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2 ;
    if(l  < n and arr[l] > arr[largest])
    largest = l;
    if(r < n and arr[r] > arr[largest])
    largest = r;
    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

void printHeap(int arr[], int n)
{
    for(int i = 0; i <n; i++)
    cout << arr[i] << "   ";
}

int main(){
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    printHeap(arr, n);
    return 0;
}