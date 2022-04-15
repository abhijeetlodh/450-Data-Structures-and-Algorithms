/******************************************************************************


                     Abhijeet Lodh solving Strings from Love Babbar 450 DSA Sheet

                    Question: Reverse an string

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
int len = str.length();
int loop = len - 1;
int i = 0;
while(i  < loop)
{
    swap(str[i], str[loop]);
    loop = loop - 1;
    i++;
}
cout << str << endl;

    return 0;
}