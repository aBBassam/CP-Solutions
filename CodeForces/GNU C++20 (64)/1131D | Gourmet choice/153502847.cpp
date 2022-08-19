#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 1010; 
int n, m, Parent[N + N], dist[N + N], vis[N + N], cyc; 
string a[N];
set<int> adj[N + N]; 
 
 
int root(int x)
{
   return  (x == Parent[x]) ? x : Parent[x]=root(Parent[x]);
}
void merge (int x,int y)
{
    if(root(x) != root(y)) Parent[root(x)]=root(y);
}
 
void dfs(int node)
{
 if(vis[node] == 2) return;
 if(adj[node].size() == 0)
  return void(dist[node] = 1); 
 
 vis[node] = 1;  
 dist[node] = 0; 
 for(int nd : adj[node])
 {
  if(vis[nd] == 1) return void(cyc = 1); 
  dfs(nd);
  dist[node] = max(dist[node], 1 + dist[nd]);
 }
 
 vis[node] = 2; 
}
 
int main()
{
 cin >> n >> m;
 for(int i=1 ; i<=n + m ; i++) Parent[i] = i, dist[i] = 0; 
 for(int i=1 ; i<=n; i++) cin >> a[i], a[i] = '*' + a[i]; 
 
 for(int i=1 ; i<=n;  i++)
  for(int j=1 ; j<=m ; j++)
   if(a[i][j] == '=')
    merge(i, n + j);
 
 for(int i=1 ; i<=n;  i++)
  for(int j=1 ; j<=m ; j++) if(a[i][j] != '=')
  {
   int par = (a[i][j] == '<') ? root(n + j) : root(i); 
   int son = (par == root(n + j)) ? root(i) : root(n + j); 
   
   if(root(i) == root(n + j)) return cout << "No", 0;
   adj[par].insert(son);
  }
 
 
 for(int i=1 ; i<=n + m ; i++)
  dfs(root(i)); 
 
 if(cyc) return cout << "No\n", 0;
 
 cout << "Yes\n";
 for(int i=1 ;i <=n + m; i++)
 {
  cout << dist[root(i)] << ' '; 
  if(i == n) cout << '\n';
 }
}