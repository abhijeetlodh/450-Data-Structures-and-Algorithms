#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}


int findParent(int u, vector<int> &peer) {
    if(u == peer[u]) return u; 
    return peer[u] = findParent(peer[u], peer); 
}

void unionn(int u, int v, vector<int> &peer, vector<int> &que) {
    u = findParent(u, peer);
    v = findParent(v, peer);
    if(que[u] < que[v]) {
    	peer[u] = v;
    }
    else if(que[v] < que[u]) {
    	peer[v] = u; 
    }
    else {
    	peer[v] = u;
    	que[u]++; 
    }
}

int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	vector<int> peer(N);
	for(int i = 0;i<N;i++) 
	    peer[i] = i; 
	vector<int> que(N, 0); 
	int cost = 0;
	vector<pair<int,int>> miniMumSpanning; 
	for(auto it : edges) {
	    if(findParent(it.v, peer) != findParent(it.u, peer)) {
	        cost += it.wt; 
	        miniMumSpanning.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, peer, que); 
	    }
	}
	cout << cost << endl;
	for(auto it : miniMumSpanning) cout << it.first << " - " << it.second << endl; 
	return 0;
}