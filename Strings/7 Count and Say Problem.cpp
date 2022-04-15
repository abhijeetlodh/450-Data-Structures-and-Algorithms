/******************************************************************************


                     Abhijeet Lodh solving Stings from Love Babbar 450 DSA Sheet
                    Question:   Count and Say Problem

*******************************************************************************/

#include <iostream>
using namespace std;

string countAndSay(int n)
{
     if (n == 1)      return "1";
    if (n == 2)      return "11";
string S = "11"; 
    for (int i = 3; i<=n; i++)
    {        S += '$';
        int len = S.length();
        int count = 1;
        string  temp = ""; 
        for (int j = 1; j < len; j++)
        {
            if (S[j] != S[j-1])
            {
                temp += count + '0';                temp += S[j-1];
 
    count = 1;
            }
            else count++;
        }
         S = temp;
    }
 
    return S;
}

int main()
{
   int n; cin >> n;
 cout <<  countAndSay(n);
    return 0;
}