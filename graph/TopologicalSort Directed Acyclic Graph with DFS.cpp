// TopologicalSort Directed Acyclic Graph with DFS
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	 void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }
	public:
	vector<int> topoSort(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(vis[i] == 0) {
	            findTopoSort(i, vis, st, adj); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo; 
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
  /*
  1
  201 61
52 16
60 16
41 4
4 18
18 51
52 26
58 26
18 26
51 26
51 22
26 22
26 35
22 35
8 2
4 2
26 2
22 2
35 2
51 0
26 0
2 0
0 45
41 14
26 14
0 14
45 14
16 32
4 32
2 32
45 32
14 32
53 37
4 37
18 37
35 37
45 37
32 37
53 9
0 9
37 9
8 59
32 59
9 59
60 40
16 40
35 40
14 40
9 40
59 40
3 31
16 31
2 31
45 31
14 31
32 31
37 31
40 31
60 43
51 43
37 43
31 43
0 17
37 17
9 17
43 17
40 20
43 20
17 20
26 56
35 56
17 56
20 56
20 1
56 1
14 30
17 30
1 30
53 27
40 27
56 27
1 27
30 27
22 57
17 57
56 57
1 57
30 57
27 57
8 6
32 6
1 6
30 6
57 6
56 34
6 34
3 29
45 29
9 29
6 29
34 29
59 25
57 25
29 25
6 15
34 15
29 15
25 15
9 13
31 13
56 13
1 13
34 13
15 13
37 21
29 21
25 21
15 21
13 21
0 54
21 54
0 48
1 48
6 48
21 48
54 48
29 23
21 23
54 23
48 23
34 36
21 36
54 36
23 36
21 12
48 12
36 12
32 28
6 28
54 28
23 28
12 28
18 47
59 47
12 47
28 47
40 10
57 10
23 10
36 10
28 10
47 10
51 55
23 55
47 55
10 55
48 24
36 24
47 24
55 24
1 38
24 38
8 46
1 46
36 46
10 46
38 46
15 7
28 7
24 7
46 7
15 49
24 49
7 49
41 19
14 19
21 19
55 19
7 19
49 19
25 50
12 50
55 50
19 50
1 11
55 11
46 11
49 11
19 11
50 11
11 42
50 33
42 33
53 39
33 39
11 44
42 44
39 44
13 5
10 5
49 5
44 5*/