/******************************************************************************


                     Abhijeet Lodh solving String from Love Babbar 450 DSA Sheet
                Question:Minimum characters to be added at front to make string palindrome

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s)
{
	int l = s.length();
	int j;
	
	for(int i = 0, j = l - 1; i <= j; i++, j--)
	{
		if(s[i] != s[j])
			return false;
	}
	return true;
}
int main()
{
	string s = "AACECAAAA";
	int count = 0;
	int label = 0;
	
	while(s.length()>0)
	{	if(ispalindrome(s))
		{
			label = 1;
			break;
		}
		else
		{
		count++;
		s.erase(s.begin() + s.length() - 1);
		}
	}	if(label)
		cout << count;
}
