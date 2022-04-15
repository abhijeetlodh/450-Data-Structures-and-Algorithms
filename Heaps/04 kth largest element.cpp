/******************************************************************************


Abhijeet Lodh solving Heap from Love Babbar 450 DSA Sheet
Question: 04 kth largest element

*******************************************************************************/
#include <iostream>
using namespace std;
int swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
class MinHeap {
 
    int size;
    int* arr;
 
public:
    MinHeap(int size, int input[]);
 
    void heapify(int i);
    void buildHeap();
};
MinHeap::MinHeap(int size, int input[])
{
    this->size = size;
    this->arr = input;
    buildHeap();
}
 
void MinHeap::heapify(int i)
{   if (i >= size / 2)
        return;
    int smallest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    smallest = arr[left] < arr[i] ? left : i;
     if (right < size)
        smallest = arr[right] < arr[smallest]
                             ? right : smallest;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}
 
void MinHeap::buildHeap()
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}
 
void FirstKelements(int arr[],int size,int k){
    MinHeap* m = new MinHeap(k, arr);
    for (int i = k; i < size; i++) {
       if (arr[0] > arr[i])
            continue;
         else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
 
    int arr[] = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    int k = 3;
 
    FirstKelements(arr,size,k);
 
    return 0;
}