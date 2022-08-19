#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 50010, K = 510; 
ll dp[N][K], ans, n, k; 
vector<int> adj[N]; 
 
void dfs(int node, int par)
{
 dp[node][0] = 1; 
 
 for(int nd : adj[node]) if(nd != par)
 {
  dfs(nd, node); 
  
  for(int i=0 ; i<=k ; i++) if(k - 1 - i >= 0)
   ans += dp[node][i] * dp[nd][k - 1 - i];
    
  for(int i=1 ; i<=k; i++)
   dp[node][i] += dp[nd][i-1];
 }
}
 
 
 
int main()
{
 cin >> n >> k; 
 for(int i=0, a, b ; i<n-1 ; i++)
  cin >> a >> b, 
  adj[a].push_back(b), 
  adj[b].push_back(a); 
 
 dfs(1, 1);
 cout << ans; 
}
 
 
 