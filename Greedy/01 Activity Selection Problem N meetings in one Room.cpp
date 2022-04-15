/******************************************************************************


                     Abhijeet Lodh Solving Greedy from Lover Babbar 450 DSA
        
                    Question: Activity Selection Problem N meetings in one Room
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second)
        return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) v[i] = {start[i], end[i]};
        sort(v.begin(), v.end(), cmp);
        int i =  0;
        int j = 1;
        int c = 1;
        while(j<n){
            if(v[i].second  < v[j].first){
                c++;
                i=j;
                j++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  