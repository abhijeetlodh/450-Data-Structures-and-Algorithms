#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int S, vector<int> adj[],vector<bool> &vis){
	    vis[S] = true;
        
        for (auto v : adj[S])
        {
            if (vis[v] == 0)
                dfs(v, adj, vis);
        }
	}
	
	void step1(vector<int> adj[], vector<bool> &vis, int live, stack<int> &S){
	    vis[live] = true;
        
        for (auto v : adj[live])
            if (vis[v] == false)
                step1(adj, vis, v, S);
        
        S.push(live);
	}
	
	
	void step2(int V, vector<int> adj[], vector<int> adj2[]) 
	{
        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                adj2[v].push_back(u);
    }
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(vis[i] == false){
                step1(adj, vis, i, st);
            }
        }
        
        vector<int> adj2[V];
        step2(V, adj, adj2);
        
        int solution = 0;
        vis = vector<bool>(V,false);
        
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(!vis[t]){
                dfs(t,adj2,vis);
                solution++;
            }
        }
        return solution;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
/*
1
31 102
0 5
0 6
1 0
1 4
1 8
2 4
2 5
2 6
2 7
3 0
3 2
3 4
3 6
4 0
4 4
4 7
6 0
6 4
6 5
7 3
7 4
7 5
8 0
8 1
8 4
8 5
8 8
11 9
11 10
12 10
13 13
13 16
13 17
13 18
13 23
13 24
14 15
14 27
15 18
16 13
16 17
16 19
16 22
16 25
16 26
17 20
17 23
17 25
17 26
18 17
18 19
18 23
19 14
19 16
19 17
19 22
20 16
20 18
20 21
20 26
21 20
21 23
22 14
22 15
22 18
22 21
22 24
23 19
23 21
23 22
23 23
23 26
23 28
24 21
24 27
25 13
25 15
25 17
25 19
25 20
25 21
25 22
25 23
25 24
25 25
26 13
26 16
26 23
26 27
27 15
27 16
27 18
27 22
27 23
27 24
27 28
28 13
28 20
28 24
28 27
29 29
29 30
*/