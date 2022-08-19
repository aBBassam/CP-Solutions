#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 131072 + 10; 
ll n, p; 
int a, b, col[2 * N], globalCount, vis[N]; 
vector<pair<int, int>> dir[N]; 
 
 
 
void dfs(int node, int prev)
{
 vis[node] = 1; 
 for(auto it : dir[node])
 {
  int nd = it.F; 
  int ed = it.S; 
  
  if(vis[nd]) continue; 
   
  col[nd] = globalCount + (prev ? 0 : n);
  col[ed] = globalCount + (prev ? n : 0); 
  globalCount ++; 
  dfs(nd, !prev); 
 } 
}
 
 
void solve()
{
 cin >> p; 
 n = (1 << p); 
 for(int i=1 ; i<n ;i++)
  cin >> a >> b,
  dir[a].push_back({b, n + i}),
  dir[b].push_back({a, n + i}); 
 
 globalCount = 1;
 dfs(1, 1);
 
 col[1] = n; 
 cout << 1 << '\n';
 for(int i=1 ;i<=n ;i++) cout << col[i] << ' '; cout << '\n'; 
 for(int i=1 ;i <n ;i++) cout << col[n + i] << ' '; cout << '\n'; 
 for(int i=0 ; i<=n ; i++) dir[i].clear(), vis[i] = 0; 
}
 
int main()
{
 test
  solve(); 
}