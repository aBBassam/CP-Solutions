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
ll n, cnt[N]; 
vector<int> adj[N]; 
int vis[N]; 
int cyc; 
 
int dfs(int node)
{
 if(adj[node].size() == 1) cyc = 0; 
 
 if(vis[node]) return 0; 
 
 vis[node] = 1; 
 
 int len = 1; 
 for(int nd : adj[node])
  len += dfs(nd); 
  
 return len; 
}
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ; i<=n;i ++)
  adj[i].clear(), cnt[i] = vis[i] = 0; 
 
 int ys = 1;  
 for(int i=1 ;i <=n; i++)
 {
  int x, y; 
  cin >> x >> y; 
 
 
  if(x == y) ys = 0; 
  cnt[x] ++; 
  cnt[y] ++; 
  
  if(max(cnt[x], cnt[y]) > 2) ys = 0; 
  
  adj[x].push_back(y); 
  adj[y].push_back(x);
 }
 
 
 for(int i=1 ; i<=n;i++) if(!vis[i])
 {
  cyc = 1; 
  int len = dfs(i); 
  if(cyc && (len & 1))
   ys = 0;
 }
 
 answer(ys); 
 for(int i=1 ;i <=n; i++)
  adj[i].clear(); 
}
 
 
int main()
{
    test
  solve();
}