#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int depth[N];
int height[N];
vector<int> g[N];

void dfs(int vertex, int par = 0){
    for(int child : g[vertex]){
        if(child == par) continue;
        depth[child] = depth[par] +1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
    }
}


int main()
{
 int n; cin >> n;
 for(int i = 0 ; i < n; i++)
 {
     int u, v; cin >> u >> v;
     g[u].push_back(v);
     g[v].push_back(u);
 }
    dfs(1);    
for(int i  = 1; i <=n; i++){
    cout << "depth " << depth[i] << " height " << height[i] << endl;
}
    return 0;
}
/*
input:

13
1
2
1
3
1
13
2
5
3
4
5
6
5
7
5
8
8
12
4
9
4
10
10
11
*/
