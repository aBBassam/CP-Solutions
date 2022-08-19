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
ll n;
int vis[N];  
pair<ll, ll> a[N]; 
vector<int> adj[N]; 
int ans; 
 
 
 
int dfs(int node)
{ 
 ll gt = 0; 
 for(int nd : adj[node])
  gt += dfs(nd); 
 
 if(gt >= a[node].F)
 {
  return min(a[node].S, gt); 
 }
 else 
 {
  ans ++; 
  return a[node].S;
 }
}
 
 
 
 
void solve( )
{
 cin >> n; 
 for(int i=2 ; i<=n; i++)
 {
  int par; cin >> par; 
  adj[par].push_back(i); 
 }
 
 for(int i=1 ;i <=n;i++)
  cin >> a[i].F >> a[i].S; 
 
 ans = 0; 
 dfs(1); 
 
 cout << ans << '\n'; 
 for(int i=1 ; i<=n; i++)
  adj[i].clear(), vis[i] = 0; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 