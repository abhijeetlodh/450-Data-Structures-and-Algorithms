/******************************************************************************


                     Abhijeet Lodh Solving Search-Sort from Lover Babbar 450 DSA
        
                    Question: find majority element in an array
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
 
 bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)
 
        if (a[i] == cand)
            count++;
 
    if (count > size / 2)
        return 1;
 
    else
        return 0;
}
 
int majorityElement(int a[], int size)
{
    int cand = findCandidate(a, size);
    if (isMajority(a, size, cand))
        return cand;
        else
     return -1;
}
int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}