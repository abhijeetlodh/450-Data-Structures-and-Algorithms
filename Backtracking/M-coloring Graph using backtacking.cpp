/*

M-coloring Graph using backtacking

input:
2
3
2
3
0
1
1
2
0
2

4
3
5
1 2 2 3 3 4 4 1 1 3
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such

//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node, int N, bool graph[101][101], int color[], int col){
    for(int k = 0; k < N; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col)
        return false;
    }
    return true;
}
bool solve(int node, int N, bool graph[101][101], int m, int color[]){
    if(node == N) return true;
    for(int i = 1; i <= m; i++){
        if(isSafe(node, N, graph, color, i)){
            color[node] = i;
            if(solve(node+1, N, graph, m, color))            return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    if(solve(0, V, graph, m,  color)) return true;
    return false;
}
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends