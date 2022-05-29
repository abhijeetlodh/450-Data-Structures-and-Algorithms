/******************************************************************************
print Linearly from 1 to N using recursion.cpp

*******************************************************************************/

#include <iostream>

using namespace std;

void printLinearly(int t, int N){
    if(N < t)
    return;
    cout << t << " ";
    printLinearly(++t, N);
}

int main()
{
  
   int N  = 10;
   printLinearly(1, N);

    return 0;
}
