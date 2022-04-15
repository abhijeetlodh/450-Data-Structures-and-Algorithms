/******************************************************************************


                     Abhijeet Lodh solving String from Love Babbar 450 DSA Sheet
                Question:   Longest Prefix Suffix(KMP)

*******************************************************************************/

#include <iostream>
using namespace std;
int largest_prefix_suffix(const std::string&str)
{
int n = str.length();
if(n < 2) {
	return 0;
}
int len = 0;
int i = 1;
while(i < n)
{	if(str[i] == str[len])
	{
	++len;
	++i;
	}
	else
	{
	i = i - len + 1;
	len = 0;
	}
}
return len;
}
int main()
{
	
string s = "abcabcabc";
cout << largest_prefix_suffix(s);
return 0;
}