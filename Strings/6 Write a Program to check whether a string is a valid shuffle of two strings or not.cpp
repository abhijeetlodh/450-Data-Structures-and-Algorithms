/******************************************************************************


                     Abhijeet Lodh solving Stings from Love Babbar 450 DSA Sheet
                    Question: Write a Program to check whether a string is a valid shuffle of two strings or not

*******************************************************************************/

#include <iostream>
using namespace std;

bool shuffle(string s1, string s2, string results)
{
    if( s1.size() + s2.size() != results.size())
    {
       return 0;
    }
    else { 
        int i = 0, j = 0, k = 0;
        while(k != results.size())
        {
            if(i < s1.size() && s1[i] == results[k])
            i++;
            else if(j < s2.size() && s2[j] == results[k])
            j++;
             else {
                return 0;
                 }
                 k++;
            }
        if(i < s1.size() || j < s2.size())
        {
            return 0;
        }
}
 return 1;
    
}

int main()
{
    string s1 = "XY";
    string  s2 = "12";
    string results = "XY12";

shuffle(s1, s2, results);
if(shuffle(s1, s2, results) == 1)
cout << "VAlid";
if(shuffle(s1, s2, results) == 0)
cout << "inVAlid";
    return 0;
}