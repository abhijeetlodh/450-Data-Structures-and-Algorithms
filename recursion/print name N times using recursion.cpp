/******************************************************************************
print name N times using recursion.cpp

*******************************************************************************/

#include <iostream>

using namespace std;

void printName(string str, int N){
    if(N < 1)
    return;
    cout << str << " ";
    printName(str, N-1);
}

int main()
{
   string str = "Abhijeet";
   int N  = 4;
   printName(str, N);

    return 0;
}
