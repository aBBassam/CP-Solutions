#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 200100; 
int n, c[N], a; 
vector<int> adj[N], undir[N]; 
map<int, int> vis; 
set<int> cycs, nodes; 
 
 
void dfs3(int node)
{
 vis[node] = 1; 
 nodes.insert(node);
 for(int nd : undir[node]) if(nodes.count(nd) == 0)
  dfs3(nd);
}
 
int dfs2(int node)
{
 int ret = c[node]; 
 vis[node] = 1; 
 
 for(int nd : adj[node]) if(!vis[nd])
  ret = min(ret, dfs2(nd));
  
 return ret; 
}
 
void dfs(int node)
{
 if(vis[node]) return void(cycs.insert(node)); 
 vis[node] = 1; 
 for(int nd : adj[node]) dfs(nd);
}
 
int main()
{
 cin >> n; 
 for(int i=1 ; i<=n ;i++) cin >> c[i]; 
 for(int i=1 ; i<=n ;i++) cin >> a, adj[i].push_back(a), undir[a].push_back(i), undir[i].push_back(a);
 for(int i=1; i<=n ;i++) if(!vis[i]) dfs(i), nodes.clear(), dfs3(i);
 
 vis.clear();
 
 ll ans = 0; 
 for(int nd : cycs)
  ans += dfs2(nd);
 
 cout << ans; 
}
 
 
 