#include<iostream>
using namespace std;

//swapping funciton to swap variable by reference
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//selectionSort
// void selectionSort(int arr[],  int n){
//     int i, j;
//     for( i = 0; i < n-1; i++){
//         for(j = i+1; j < n; j++){
//             if(arr[i] > arr[j]){
//                 swap(&arr[i], &arr[j]);
//             }
//         }
//     }
//         cout << "\nArray after Selection Sort is: " << endl;
// }



//Bubble Sort
// void bubbleSort(int arr[], int n){
//     int i, j, flag;
//     for(i = 0; i < n - 1; i++){
//         flag = 0;
//         for(j = 0; j < n-1-i; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(&arr[j], &arr[j+1]);
//             }
//         }
//     }
    
//     cout  << "\nArray after Bubble Sort is: " << endl;
// }

//Insertion Sort
// void insertionSort(int arr[], int n){
// int i, value, index;
// for(i = 0; i < n; i++){
//     value = arr[i];
//     index = i;
//     while(index > 0 && arr[index-1] > value){
//         arr[index]  =   arr[index-1];
//         index--;
//     }
//     arr[index]  = value;
// }
//     cout  << "\nArray after Insertion Sort is: " << endl;
// }


//Insertion Sort 
 void insertionSort(int arr[], int n){
        int i, value, index;
        for(i = 1; i < n; i++){
            value = arr[i];
            index = i;
            while( index > 0 && arr[index-1] > value){
                arr[index] = arr[index-1];
                index--;
            }
            arr[index] = value;
        }
cout  << "\nArray after Insertion Sort is: " << endl;
    }

// printing funciton
void printArr(int arr[], int n){
    
    for(int i  = 0; i  < n; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int arr[] = {65, 41, 22, 71, 28, 19};
    int n  = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array is: " << endl;
     for(int i  = 0; i  < n; i++){
        cout << arr[i] << " ";
    }
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    insertionSort(arr, n);
    
    printArr(arr, n);
    return 0;
}