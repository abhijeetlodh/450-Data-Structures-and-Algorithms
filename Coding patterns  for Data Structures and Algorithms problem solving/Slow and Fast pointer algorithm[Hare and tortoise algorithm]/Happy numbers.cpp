/******************************************************************************

  Happy Numbers
  Any number will be called a happy number if, after repeatedly replacing it with a number equal
  to the sum of the square of all of its digits, leads us to number ‘1’. All other 
  (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers
  which does not include ‘1’.
  
*******************************************************************************/

#include <iostream>
using namespace std;

int findSquare(int num)
{
    int sum = 0, digit;
    while(num > 0)
    {
        digit = num%10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool Happy(int a)
{
    int slow = a, fast = a;
    do{
        slow = findSquare(a);
        fast = findSquare(findSquare(a));
    }while(slow != fast);
    return slow == 1;
}

int main()
{
    cout<< Happy(23) << endl;
    cout<< Happy(12);

    return 0;
}
