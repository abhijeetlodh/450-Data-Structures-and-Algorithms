/******************************************************************************


                     Abhijeet Lodh solving Arrays from Love Babbar 450 DSA Sheet

                    Question: Reverse an array or string

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string str = "hdoL teejihbA";
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

   int start, end;
   int arr[] = {10, 16, 26, 32, 46};
    start = 0;
    end = (sizeof(arr)/sizeof(arr[0])) -1 ;
    while(start < end)
    {
        int temp  = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for(int i =0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
