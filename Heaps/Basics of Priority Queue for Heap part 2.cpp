/******************************************************************************

Abhijeet Lodh solving Heap from Love Babbar 450 DSA Sheet
Question: Basics of Priority Queue for Heap part 2


*******************************************************************************/

#include <iostream>
#include<queue>
using namespace std;

void showPriorityQueue(priority_queue<int> p)
{
    priority_queue<int> pq = p;
    cout << "<-----------------------------------Priority Queue----------------------------------->" << endl;
    while(!pq.empty())
    {
        cout << pq.top() << " " ;
        pq.pop();
    }
    cout << "\n<------------------------------------------------------------------------------------->" << endl;
}
void showPriorityQueueGreatest(priority_queue<int, vector<int>, greater<int>> p)
{
    priority_queue<int, vector<int>, greater<int>> pq = p;
    
    cout << "<-----------------------------------in increasing order----------------------------------->" << endl;
    while(!pq.empty())
    {
        cout << pq.top() << " " ;
        pq.pop();
    }
    cout << "\n<------------------------------------------------------------------------------------->" << endl;
}


int main()
{
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> p1;
    p.push(9);
    p1.push(9);
    p.push(-1);
    p1.push(-1);
    p.push(24);
    p1.push(24);
    p.push(5);
    p1.push(5);
showPriorityQueue(p);
showPriorityQueueGreatest(p1);
    return 0;
}
