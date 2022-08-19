#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N =1010; 
int n, m, k, vis[N]; 
vector<int> adj[N]; 
multiset<int, greater<int>> g_comps, g;
ll ans;
 
int dfs(int node)
{
 vis[node] = 1; 
 int ret = 1; 
 for(int nd : adj[node]) if(!vis[nd])
  ret += dfs(nd); 
 return ret; 
}
 
int main()
{
 cin >> n >> m >> k;
 for(int i=1 ,nd; i<=k ; i++) 
  cin >> nd, 
  g.insert(nd); 
 
 for(int i=1, a, b ; i<=m ; i++)
  cin >> a >> b,
  adj[a].push_back(b), 
  adj[b].push_back(a); 
 
 for(int i : g)
  g_comps.insert(dfs(i)); 
  
 ll mx = *g_comps.begin(); 
 g_comps.erase(g_comps.begin());
 
  
 ll sm = 0; 
 for(int i=1 ; i<=n; i++) if(!vis[i])
  sm += dfs(i); 
 
 sm += mx; 
 
 if(sm)
  ans = sm * (sm - 1); 
 
 
 for(int i : g_comps) if(i >= 1)
  ans += i * (i - 1);
 
 cout << ans / 2 - m; 
}