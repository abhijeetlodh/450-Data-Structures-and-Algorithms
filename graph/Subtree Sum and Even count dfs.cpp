#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int subTree_Sum[N];
int even_count[N];
vector<int> g[N];

void dfs(int vertex, int par = 0){
    if(vertex%2 == 0){
        even_count[vertex]++;
    }
    subTree_Sum[vertex] += vertex;
    for(int child : g[vertex]){
        if(child == par) continue;
        dfs(child, vertex);
        subTree_Sum[vertex] += subTree_Sum[child];
        even_count[vertex] += even_count[child];
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
    cout << "subTree_Sum " << subTree_Sum[i] << " even_count " << even_count[i] << endl;
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
