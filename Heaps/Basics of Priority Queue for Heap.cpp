/******************************************************************************


Abhijeet Lodh solving Heap from Love Babbar 450 DSA Sheet
Question: Basics of Priority Queue for Heap

*******************************************************************************/

#include <iostream>
#include <queue>
#include<vector>
using namespace std;


int main()
{
    auto Lowestcmp = [](int a, int b){
        return a > b;
    };
    auto Highestcmp = [](int a, int b){
        return a < b;
    };
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> Q;
priority_queue<int, vector<int>, decltype(Lowestcmp)> AutoQ1(Lowestcmp);
priority_queue<int, vector<int>, decltype(Highestcmp)> AutoQ2(Highestcmp);
    vector<int> v = {7, 12, 3, 0, 1, 8,  9, 28};
    vector<int> v1 = {7, 12, 3, 0, 1, 8,  9, 28};
    vector<int> v2 = {7, 12, 3, 0, 1, 8,  9, 28};
    vector<int> v3 = {7, 12, 3, 0, 1, 8,  9, 28};
    cout << "Priority Queue(pq) in Highest order : " <<endl;
    for(int x : v) pq.push(x);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    cout << "Priority Queue(AutoQ2) in Highest order using auto comparator: " <<endl;
    for(int x : v2) AutoQ2.push(x);
    while(!AutoQ2.empty()){
        cout << AutoQ2.top() << " ";
        AutoQ2.pop();
    }
    cout << endl;
    cout << "Priority Queue(Q) in Lowest order : " <<endl;
    for(int y : v1) Q.push(y);
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;
    cout << "Priority Queue(Q) in Lowest order using auto comparator : " <<endl;
    for(int y : v3) AutoQ1.push(y);
    while(!AutoQ1.empty()){
        cout << AutoQ1.top() << " ";
        AutoQ1.pop();
    }
    cout << endl;
    return 0;
}
