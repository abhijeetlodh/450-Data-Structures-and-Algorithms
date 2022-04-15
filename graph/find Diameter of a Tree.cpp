/******************************************************************************
find Diameter of a Tree
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int depth[N];
int height[N];
vector<int> g[N];

void dfs(int v, int par = -1){
    for(int child : g[v]){
        if(child==par) continue;
        depth[child] = depth[v] +1;
        dfs(child, v);
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
 int mx_Depth = -1;
 int mx_d_node;
 for(int i = 1; i <= n; ++i){
     if(mx_Depth < depth[i]){
         mx_Depth = depth[i];
         mx_d_node = i;
     }
     depth[i] = 0;
 }
 dfs(mx_d_node);
 mx_Depth = -1;
 for(int i = 1; i <= n; ++i){
     if(mx_Depth < depth[i]){
         mx_Depth = depth[i];
     }
 }
 cout << mx_Depth << endl;
 
    return 0;
}