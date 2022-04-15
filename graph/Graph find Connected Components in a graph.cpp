// Graph: find Connected Components in a graph
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
const int N  = 1e5+10;
bool vis[N];
vector<int> g[N];
vector<int> current_cc;
vector<vector<int>> cc;

void dfs(int vertex){
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(int child : g[vertex])
    {
        if(vis[child]) continue;
    // cout << "vertex: " << vertex << " child: " << child << " ";
        dfs(child);
    }
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
    
int count = 0;
 for(int i  = 1 ; i <=nodes; i++){
     if(vis[i]) continue;
     current_cc.clear();
     dfs(i);
     cc.push_back(current_cc);
     count++;
 }
cout << "count: " << count << endl << "current component: " << endl;
for(auto c_cc : cc){
    for(int br: c_cc){
        cout << br <<  " ";
    }
    cout << endl;
}
    return 0;
}
