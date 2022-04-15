/******************************************************************************


                     Abhijeet Lodh solving String from Love Babbar 450 DSA Sheet

                    Question: Check whether a String is Palindrome or not

*******************************************************************************/

#include <iostream>
using namespace std;

int isPalindrome( string S)
{
    int l = 0;
    int h = S.size() - 1;
    while(  h > l)
    {
        if(S[l++] != S[h--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string S;
    getline(cin, S);
    cout << isPalindrome(S);

    return 0;
}