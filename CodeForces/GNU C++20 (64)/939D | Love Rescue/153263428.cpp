#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n, vis[100], ex[100]; 
string a, b; 
vector<int> adj[50];
vector<pair<int, int>> ans; 
 
void dfs(int node)
{
 vis[node] = 1; 
 for(int nd : adj[node]) if(!vis[nd])
  ans.push_back({node, nd}), 
  dfs(nd); 
}
int main()
{
 cin >> n >> a >> b; 
 for(int i=0 ; i<n; i++) 
  ex[a[i] - 'a'] = ex[b[i] - 'a'] = 1,
  adj[a[i] - 'a'].push_back(b[i] - 'a'), 
  adj[b[i] - 'a'].push_back(a[i] - 'a');
 
 for(int i=0 ; i<=25 ;i ++) if(ex[i] && !vis[i])
  dfs(i); 
  
 cout << ans.size() << '\n';
 for(auto it : ans) cout << (char)(it.F + 'a')  << ' ' << (char)(it.S + 'a') << '\n'; 
}