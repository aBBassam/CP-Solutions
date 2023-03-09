#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
#define int long long
using namespace std;


const int INF = 1e17;
const int N = 151, M = 5010, Q = 1010; 
ll n, m, q, d[N][N];  
vector<pair<int, int>> adj[N]; 
vector<int> dist[N]; 





vector<int> floydWarshall(int node) // 1-based indexing
{
    vector<int> distance(n + 1, INF), parent(n + 1, -1);
    vector<bool> visited(n + 1, 0);
    vector< pair< int , pair < int , int > > > edges; 


	function<void(int)> dfs = [&](int node) 
	{
    	visited[node] = true; 
    	
    	for(auto it : adj[node]) // WEIGHT FIRST IN ADJ 
    		if(!visited[it.second])
    		{
    			edges.emplace_back(it.first, make_pair(node, it.second)); // directed
    			dfs(it.second); 
    		}
    };
    
    function<void(int, int, int, bool)> maximize = [&](int a, int b, int w, bool checkForNeg)
    {
		if(distance[a] < INF && (distance[b] > distance[a] + w))
		{
			if(checkForNeg) distance[b] = - INF; 
			else distance[b] = max(- INF, distance[a] + w); 
			
			parent[b] = a;
		}
    };
    

	dfs(node); 
	distance[node] = 0; 

	for(int i=0 ;i < n; i ++)
		for(auto it : edges)
			maximize(it.second.first, it.second.second, it.first, false);
	
	for(auto it : edges)
		maximize(it.second.first, it.second.second, it.first, true);
	
	return distance; 
}


int32_t main()
{
	go; 
	while(1)
	{
		cin >> n >> m >> q;
		if(max(n, max(m, q)) == 0)
			return 0; 
					
		for(int i=1 ;i <=n; i++)
			for(int j=1 ;j<= n; j ++)
				d[i][j] = INF; 
		
		for(int i=0 ;i < m ;i ++)
		{
			int a, b, w; 
			cin >> a >> b >> w; 
			a ++, b++; 
			
			d[a][b] = min(d[a][b], w); 
		}
			
		for(int i=1 ;i <=n; i++)
			for(int j = 1 ; j <= n ; j ++)
				if(d[i][j] != INF)
					adj[i].push_back({d[i][j], j}); 
		
		for(int i=1 ;i <=n; i++)
			dist[i] = floydWarshall(i); 
			
			
		for(int sr = 1 ; sr <= n ; sr ++)
			for(int i=1 ; i <= n  ;i ++)
				for(int j=1 ; j <= n ;j ++)
				{
					if(dist[sr][i] == - INF && dist[i][j] != INF)
						dist[i][j] = - INF; 
				}
		
		while(q --)
		{ 
			int i, j; cin >> i >> j; 
			i ++, j ++; 
			
			if(dist[i][j] == - INF) cout << "-Infinity\n"; 
			else if(dist[i][j] == INF) cout << "Impossible\n"; 
			else cout << dist[i][j] << endl; 
		}
		
		cout << endl; 
		for(int i=1 ;i <=n; i++) adj[i].clear(); 
	}
}


