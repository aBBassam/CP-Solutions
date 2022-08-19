#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 300100; 
ll  n, m, a, b, c, w[N], dp[N][2]; 
map<pair<int, int>, ll> cost; 
vector<int> adj[N]; 
 
 
void dfs(int node, int par)
{
 dp[node][0] = dp[node][1] = w[node];
 
 for(int nd : adj[node]) if(nd != par)
 {
  dfs(nd, node);
  dp[node][1] = max({dp[node][1], dp[nd][1], dp[node][0] + dp[nd][0] - cost[{min(node, nd), max(node, nd)}]});
  dp[node][0] = max(dp[node][0], w[node] + dp[nd][0] - cost[{min(node, nd), max(node, nd)}]);
 }
}
 
int main()
{
    cin >> n ; 
    for(int i=1 ; i<=n ;i++) cin >> w[i]; 
    for(int i=1 ; i<n ;i++)
     cin >> a >> b >> c, 
     adj[a].push_back(b), 
     adj[b].push_back(a),
     cost[{min(a, b), max(a, b)}] = c; 
    
    dfs(1, 1); 
    cout << dp[1][1]; 
}
 
 
 