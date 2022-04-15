void BFS(vector<int> Graph[], int N, int idx) 
{ 
	int len[N];
	for(int i = 0;i<N;i++) len[i] = INT_MAX; 
	queue<int>  q;
	
	len[idx] = 0;
	q.push(idx); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:Graph[node]){
		    if(len[node] + 1 < len[it]){
		        len[it]=len[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << len[i] << " "; 
	
} 