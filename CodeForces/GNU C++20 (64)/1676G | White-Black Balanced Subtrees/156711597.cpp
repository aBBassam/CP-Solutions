// Problem: G. White-Black Balanced Subtrees
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int N = 4010; 
int n, a[N], b[N]; 
string s; 
vector<int> adj[N]; 
 
 
int dfs1(int node)
{
 int ret = 0; 
 if(s[node] == 'W')ret ++; 
 
 for(int nd : adj[node])
  ret += dfs1(nd); 
 
 return a[node] = ret; 
}
int dfs2(int node)
{
 int ret = (s[node] == 'B'); 
 for(int nd : adj[node])
  ret += dfs2(nd); 
 
 return b[node] = ret; 
}
 
 
 
void solve()
{
 ll ans = 0; 
 cin >> n;
 for(int i=2 ; i<=n; i++)
 {
  int par; cin >> par; 
  adj[par].push_back(i); 
 }
 cin >> s; 
 s = "&" + s; 
 
 dfs1(1), dfs2(1); 
 
 
 for(int i=1 ;i<=n; i++) 
  ans += a[i] == b[i]; 
 
 cout << ans << '\n'; 
 
 for(int i=0 ; i<=n; i++)
  adj[i].clear(), a[i] = b[i] = 0; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 