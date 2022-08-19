#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define deb(x) cout<<#x<<"="<<x<<endl
#define F first
#define S second
using namespace std;
 
 
const int N = 200100; 
int n, m, u, v, in[N], dp[N], ans = 1; 
vector<int> adj[N]; 
 
int solve(int node)
{
 if(adj[node].size() <= 1) return 1; 
 
 int &ret = dp[node]; 
 if(ret + 1) return ret; 
 ret = 1; 
  
 for(int nd : adj[node]) if(in[nd] > 1)
  ret = max(ret, solve(nd) + 1);
 
 return ret; 
}
 
 
int main()
{
 cin >> n >> m; 
 for(int i=0 ; i<m ; i++)
  cin >> u >> v, 
  adj[u].push_back(v), 
  in[v] ++; 
 
 memset(dp, -1, sizeof dp); 
 for(int i=1 ; i<=n ; i++) if(adj[i].size() > 1)
  ans = max(ans, solve(i)); 
 
 cout << ans; 
}