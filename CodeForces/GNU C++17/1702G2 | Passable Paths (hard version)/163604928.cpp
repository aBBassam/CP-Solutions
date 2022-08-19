// Problem: G1. Passable Paths (easy version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 200100, M = 25; 
ll n, vis[N], depth[N], dp[N][M], parr[N];
vector<int> adj[N]; 
set<pair<int, int>> vs, vs2; 
int lst; 
 
 
int kth(int u,int k)
{
    if(k>depth[u])
        return 0;
    for(int i=M-1; i>=0; i--)
        if(k&(1<<i))
            u=dp[u][i];
    return u;
}
 
 
void Dfss(int u,int p,int d)
{
 parr[u] = p;
    dp[u][0]=p;
    depth[u]=d;
    for(int v : adj[u])
        if(v!=p)
            Dfss(v,u,d+1);
}
 
 
int Lca(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);
    int k=depth[u]-depth[v];
    u=kth(u,k);
    if(u==v)
        return u;
    for(int i=M-1; i>=0; i--)
    {
        int x=dp[u][i];
        int y=dp[v][i];
        if(x && y && x!=y)
        {
            u=x;
            v=y;
        }
    }
    return dp[u][0];
}
 
 
int Dist(int u,int v)
{
    return depth[u]+depth[v]-2*depth[Lca(u,v)];
}
 
 
 
void dfs(int node)
{
 if(vs.empty())return;
 
 auto it = vs.lower_bound({-depth[node], -1000}); 
 if(it == vs.end()) return; 
 
 if(it->S == node) 
 {
  lst = node; 
  vs.erase(it); 
  dfs(node); 
  return; 
 }
 if(Lca(it->S, node) == it->S) // I'm your father 
  dfs(it->S);
 else 
 { 
  vs2.insert({-it->F, it->S}); 
  vs.erase(it); 
  dfs(node);
 }
}
 
 
void dfs2(int node)
{
 if(vs2.empty())return void(); 
 
 auto it = vs2.lower_bound({depth[node], -1000}); 
 if(it == vs2.end()) return; 
 
 if(it->S == node) 
 {
  vs2.erase(it); 
  dfs2(node); 
  return; 
 }
 
 if(Lca(it->S, node) == node) // I'm your father 
  dfs2(it->S); 
}
 
 
int main()
{
 go; 
 cin >> n;
 for(int i=1 ; i < n; i++)
 {
  int a, b;
  cin >> a >> b; 
  adj[a].push_back(b); 
  adj[b].push_back(a); 
 }
 
 Dfss(1, 0, 1); 
 
 for(int j=1; j<M; j++)
        for(int i=1; i<=n; i++)
            dp[i][j]=dp[dp[i][j-1]][j-1];
            
 
 int q; cin >> q; 
 while(q --)
 { 
  vs.clear(); 
  vs2.clear(); 
  
  vector<pair<int, int>> v; 
  
  int k; cin >> k;
  v.resize(k + 1); 
  
  vs.clear(); 
  for(int i=1; i<=k ; i++)
   cin >> v[i].S, v[i].F = -depth[v[i].S], 
   vs.insert(v[i]);
  
  for(int i=1; i<=k ; i++)
   v[i].F *= -1; 
  
  sort(v.begin() + 1, v.begin() + k + 1);
  
  dfs(vs.begin() -> S); 
  int ys = vs.size() == 0; 
  
  if(!vs2.empty())
  {
   int node = (vs2.begin())->S; 
   
   lst = Lca(lst, node); 
   
   for(int i=1 ;i <=k ;i ++)
    if((!vs2.count({depth[v[i].S], v[i].S})) && Lca(node, v[i].S) != lst)
     ys = 0; 
   
   dfs2(node); 
   if(!vs2.empty()) ys = 0;
  }
  
  answer(ys);
 }
}