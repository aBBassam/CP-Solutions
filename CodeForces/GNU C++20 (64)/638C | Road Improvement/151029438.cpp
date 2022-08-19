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
map<pair<int, int>, int> id; 
map<pair<int, int>, bool> vis; 
int n, m, u, v;
vector<int> adj[N], ans[N];
 
void dfs(int node, int day)
{
 int cnt = 1; 
 
 for(int nd : adj[node]) if(!vis[{min(node,  nd), max(node, nd)}])
 {
  vis[{min(node,  nd), max(node, nd)}] = 1; 
  
  if(cnt == day) ++ cnt; 
  
   
  ans[cnt].push_back(id[{min(node, nd), max(node, nd)}]);
  dfs(nd, cnt ++);
 }
}
 
 
 
int main()
{
 cin >> n;   
 for(int i=1 ; i<n ;i++)
  cin >> u >> v, 
  adj[u].push_back(v), 
  adj[v].push_back(u), 
  id[{min(u, v), max(u, v)}] = i; 
 
 
 int k = 0, rt = 0; 
 for(int i=1 ; i<N; i++) if(adj[i].size() > k)
  k = adj[i].size(), rt = i; 
 
 // k = maximum degree
 dfs(rt, -1); 
 cout << k << '\n'; 
 for(int i=1 ; i<=k ; i++)
 {
  cout << ans[i].size() << ' ';
  for(int d : ans[i]) cout << d << ' '; 
  cout << '\n'; 
 }
}