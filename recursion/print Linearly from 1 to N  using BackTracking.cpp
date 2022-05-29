/******************************************************************************
print Linearly from 1 to N  using BackTracking.cpp

*******************************************************************************/

#include <iostream>

using namespace std;

void printLinearlyBackTracking(int J, int N){
    if(J > N) return;
    printLinearlyBackTracking(J+1, N);
    cout << J << " ";
}

int main()
{
  
   int N  = 10;
   printLinearlyBackTracking(1, N);

    return 0;
}
