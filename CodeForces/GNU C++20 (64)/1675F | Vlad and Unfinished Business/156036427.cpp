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
int n, k, x, y, ans; 
int u, v; 
int isTask[N], tasksInSub[N], isPath[N], par[N]; 
vector<int> adj[N], dir[N]; 
 
 
 
void dfs(int node, int pr)
{
 for(int nd : dir[node]) if(nd != pr)
  par[nd] = node, 
  adj[node].push_back(nd), 
  dfs(nd, node); 
}
 
int dfs2(int node, int pr)
{
 if(node == y) 
 {
  isPath[node] = 1; 
  return 1; 
 }
 
 for(int nd : adj[node]) if(nd != pr)
  if(dfs2(nd, node)) 
  {
   isPath[nd] = 1; 
   ans ++; 
   return 1; 
  }
  
 if(par[node] && pr != par[node] && dfs2(par[node], node)) 
 {
  ans ++; 
  isPath[par[node]] = 1; 
  return 1; 
 }
 
 return 0; 
}
 
 
int dfs3(int node)
{ 
 int ys = 0; 
 for(int nd : adj[node])
  ys |= dfs3(nd); 
 
 tasksInSub[node] = ys;
 return isTask[node] || tasksInSub[node];
}
 
void dfs4(int node)
{
 for(int nd : adj[node])
 {
  if((isTask[nd] || tasksInSub[nd]) && !isPath[nd])
    ans += 2;  
   
  if(tasksInSub[nd])
   dfs4(nd);
 } 
}
 
int main()
{
    test
 {
  cin >> n >> k >> x >> y; 
  for(int i=1 ;i<=k;i++) cin >> u, isTask[u] = 1; 
  for(int i=1 ;i<n; i++) 
   cin >> u >> v,  
   dir[u].push_back(v), 
   dir[v].push_back(u);
   
 
  dfs(x, 0);  // make a x-directed tree
  dfs2(x, 0); // find optimal path x -> y
  dfs3(x);    // compute tasksInSub array 
  dfs4(x);    // calc answer
   
 
  cout << ans << '\n';
  ans = 0; 
  for(int i=1 ; i<=n; i++) isTask[i] = tasksInSub[i] = isPath[i] = par[i] = 0, dir[i].clear(), adj[i].clear();
 }
}