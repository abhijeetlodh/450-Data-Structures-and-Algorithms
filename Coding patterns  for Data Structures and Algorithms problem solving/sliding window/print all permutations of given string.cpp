/******************************************************************************

Write a program to print all permutations of a given string

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void permute(string a, int l, int r)
{
    if(l == r) cout << a<< endl;
    else
    {
        for(int i = l;  i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    permute("Abhijeet", 0, 7);

    return 0;
}
