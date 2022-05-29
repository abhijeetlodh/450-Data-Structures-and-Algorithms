/******************************************************************************
print Linearly from N to 1 using recursion.cpp

*******************************************************************************/

#include <iostream>

using namespace std;

void printLinearly( int N){
    if(N < 1)
    return;
    cout << N << " ";
    printLinearly( N-1);
}

int main()
{
  
   int N  = 10;
   printLinearly(N);

    return 0;
}
