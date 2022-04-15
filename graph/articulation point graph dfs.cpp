/*
5 5
0 1
1 4
2 4
3 4
2 3
*/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>  

void dfs(int idx, int par, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &articulate) {
    vis[idx] = 1; 
    tin[idx] = low[idx] = timer++;
    int child = 0; 
    for(auto it: adj[idx]) {
        if(it == par) continue;
        
        if(!vis[it]) {
            dfs(it, idx, vis, tin, low, timer, adj, articulate); 
            low[idx] = min(low[idx], low[it]); 
	    child++; 
            if(low[it] >= tin[idx] && par != -1) {
                articulate[idx] = 1; 
            }
        } else {
            low[idx] = min(low[idx], tin[it]); 
        }
    }
    
    if(par == -1 && child > 1) {
        articulate[idx] = 1; 
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vi adj[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi tin(n, -1);
    vi low(n, -1);
    vi vis(n, 0);
    vi articulate(n, 0);
    int timer = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i])
        dfs(i, -1, vis, tin, low, timer, adj, articulate);
    }
    for(int i = 0; i < n; i++)
    if(articulate[i] == 1)
    cout << i << endl;

    return 0;
}
