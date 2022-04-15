/******************************************************************************

                    Abhijeet Lodh solving Arrays from Love Babbar 450 DSA Sheet

                    Question: Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n = 19;
    int a[n] = {0,1,0,2,0,0,2,2,1,2,1,1,2,0,1,2,1,2,0};
         int i,j,k;
   i = j = 0;
   k = n - 1;
    while(j<=k){
        switch(a[j]){
            case 0: swap(a[i++], a[j++]);
            break;
            case 1: j++;
            break;
            case 2: swap(a[j], a[k--]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << ", ";
    }
    

    return 0;
}
