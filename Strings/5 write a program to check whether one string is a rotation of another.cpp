/******************************************************************************


                     Abhijeet Lodh solving string from Love Babbar 450 DSA Sheet
                    Question: Write a code to check whether one string is a rotation of another

*******************************************************************************/

#include <iostream>

using namespace std;

string findstring(string s1, string s2)
{
    string temp = s1 + s1;
size_t found = temp.find(s2);
if (found != string::npos)
return "  are Rotations of One-Another ";
else
return "  are not Rotations of One-Another ";
}
int main()
{
    string s1 = "ABACD";
    string  s2 = "CDABA";
cout << s1 << " " << s2 << findstring(s1, s2);

    return 0;
}