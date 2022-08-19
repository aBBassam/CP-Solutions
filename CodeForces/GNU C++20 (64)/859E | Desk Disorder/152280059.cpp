#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 200100, Mod = 1e9 + 7; 
int n, vis[N], cycle, sz;
ll ans = 1; 
set<int> nodes, bad; 
vector<int> adj[N]; 
 
void dfs(int node, int par)
{
 if(vis[node]) return void(cycle = 1); 
 sz ++, vis[node] = 1; 
 
 for(int nd : adj[node]) if(nd != par)
  dfs(nd, node);
}
 
int main()
{
 cin >> n; 
 for(int i=1, a, b ; i<=n ;i++)
 {
  cin >> a >> b,
  nodes.insert(a); 
  if(a == b) 
  { 
   bad.insert(a);
   continue;
  }
  
  adj[a].push_back(b), adj[b].push_back(a);
 }
 
 for(int i : bad)
  dfs(i, -1);
 
 for(int i : nodes) if(!vis[i])
 {
  sz = cycle = 0; 
  dfs(i, -1);
  
  if(cycle) ans *= (sz < 2) ? 1 : 2; 
  else ans *= sz; 
  
  ans %= Mod;
 }
 
  cout << ans; 
}