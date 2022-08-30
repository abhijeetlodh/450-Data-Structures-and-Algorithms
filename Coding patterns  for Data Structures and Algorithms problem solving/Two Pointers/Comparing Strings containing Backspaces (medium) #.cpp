/******************************************************************************
Comparing Strings containing Backspaces (medium) #
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int getNextValue(string str, int idx)
{
    int backspace = 0;
    
    while(idx >=0)
    {
    if(str[idx] == '#')
    backspace++;
    else if(backspace > 0) backspace--;
    else break;
        idx--;
    }
    return idx;
}

bool solve(string str1, string str2)
{
    int idx1 = str1.size()-1;
    int idx2 = str2.size()-1;
    while(idx1 >= 0 and idx2 >= 0)
    {
        
        int i1 = getNextValue(str1, idx1);
        int i2 = getNextValue(str2, idx2);
        if(i1 < 0 and i2 < 0) return true;
        if(i1 < 0 || i2 < 0) return false;
        if(str1[i1] != str2[i2]) return false;
        idx1 = i1 - 1;
        idx2 = i2 - 1;
    }
   
   return true;
}


int main()
{
    
string str1="xy#z", str2="xzz#";
cout << solve(str1, str2) << endl;
cout << solve("xywrrmp", "xywrrmu#p") << endl;
cout << solve("xp#", "xyz##") << endl;
cout << solve("xy#z", "xyz#") << endl;


    return 0;
}
