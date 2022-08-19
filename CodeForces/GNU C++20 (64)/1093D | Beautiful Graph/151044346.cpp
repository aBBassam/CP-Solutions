#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
ll fstPO(ll x, ll y, ll m = 998244353) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
 
const int N = 300100, mod = 998244353; 
int n, m, a, b, color[N];
vector<int> adj[N]; 
 
 
bool isBipartite(int node, int col)
{
 if(color[node]) return col == color[node]; 
 color[node] = col;
 
 (col == 1) ? a++ : b++; 
 
 bool ret = 1; 
 for(int nd : adj[node])
  ret &= isBipartite(nd, col == 1 ? 2 : 1); 
  
 return  ret; 
}
 
 
 
 
int main()
{
    test
 {
  cin >> n >> m; 
  for(int i=0, u, v ; i<m ; i++)
   cin >> u >> v, 
   adj[u].push_back(v), 
   adj[v].push_back(u);
  
  
  ll ans = 1; 
  for(int i=1 ;i <=n ; i++) if(!color[i])
  {
   a = b = 0;
   if(!isBipartite(i, 1)) ans = 0;  
   ans = (ans * (fstPO(2, a) + fstPO(2, b))) % mod; 
  }
  
  cout << ans << '\n';
  for(int i=1 ; i<=n ;i++) adj[i].clear(), color[i] = 0;
 }
}
 
 
 