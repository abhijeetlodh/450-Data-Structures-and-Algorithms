#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int rank1[1000];
void makeSet(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank1[i] = i;
    }
}
int findPar(int node){
    if(node == parent[node]) 
    return node;
    // path compression
    // 7 -> 6 -> 4 -> 3
    return parent[node] = findPar(parent[node]);
}
void union(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if(rank1[u] < rank1[v])
    {
        parent[u] = v;
    }
    else if(rank1[u] > rank1[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank1[u]++;
    }
}

int main(){
    makeSet();
    int m;
    cin >> m;
    while(m--){
        int u, v;
        union(u, v);
    }
    if(findPar(2) != findPar(3)){
        cout << "Different";
    }
        else cout << "Same";
    return 0;
}
/*
6
 1 2 
 2 3 
 4 5 
 6 7 
 5 6 
 3 7
*/