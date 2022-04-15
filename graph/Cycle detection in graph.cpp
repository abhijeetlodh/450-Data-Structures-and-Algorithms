// Graph: Cycle Detection in a graph
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
const int N  = 1e5+10;
bool vis[N];
vector<int> g[N];

bool dfs(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExits = false;
    for(int child : g[vertex])
    {
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
      isLoopExits |=  dfs(child, vertex);
    }
    return isLoopExits;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    for(int i  = 0 ; i < edges; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool isLoopExits = false;
 for(int i  = 1 ; i <=nodes; i++){
     if(vis[i]) continue;
     if(dfs(i, 0)){
         isLoopExits = true;
         break;
     };
     
 }
 
 cout << isLoopExits;
    return 0;
}
