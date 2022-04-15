#include <bits/stdc++.h>
using namespace std;
 
    string getPermutation(int n, int k) {
        int fact  = 1;
        vector<int> numbers;
        for (int i = 1; i <n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k -1;
        while(true){
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0){
                break;
            }
            k %=fact;
            fact /= numbers.size();
        }
        return ans;
    }

int main()
{
 
    int n = 3, k = 4;
 
    string kth_perm_seq
        = getPermutation(n, k);
 
    cout << kth_perm_seq << endl;
 
    return 0;
}