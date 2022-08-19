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
 
const int N = 200100, M  = 30; 
ll n, vis[N], depth[N], dp[N][M], parr[N];
vector<int> adj[N]; 
set<int> vs; 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
void dfs(int node, int par)
{
 if(vis[node]) return; 
 vis[node]= 1; 
 
 if(vs.empty())return; 
 
 if(vs.count(node)) 
 {
  vs.erase(node); 
  vis[node] = 0; 
  dfs(node, par); 
  return; 
 }
 int targ = *vs.begin();
 
 int mnDist = 1e9; 
 int to;
 
 for(int i : adj[node])
  if(Dist(i, targ) < mnDist)
   to = i, 
   mnDist = Dist(i, targ);
 
 dfs(to, node);
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
 
 Dfss(1, -1, 0); 
 
 for(int j=1; j<M; j++)
        for(int i=1; i<=n; i++)
            dp[i][j]=dp[dp[i][j-1]][j-1];
 
   
 int q; cin >> q; 
 while(q --)
 {
  for(int i=1 ;i <=n;i ++)
   vis[i] = 0; 
   
   
   
  int k; cin >> k;
  vs.clear(); 
  for(int i=1,v ; i<=k ; i++)
   cin >> v, 
   vs.insert(v); 
   
  int stNode = *vs.begin(); 
  int dpth = -1; 
  
  
  for(auto node : vs)
   if(depth[node] > dpth)
    dpth = depth[node], 
    stNode = node; 
   
 
  dfs(stNode, 0); 
  answer(vs.size() == 0);
 }
}
 
 
 