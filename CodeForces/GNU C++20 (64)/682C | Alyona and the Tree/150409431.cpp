#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 100100; 
int n, a[N], ans, p, c; 
map<pair<int, int>, ll> cst; 
vector<int> adj[N];
 
void dfs(int node, int father, ll val)
{
 val = max(val, 0ll);
 if(val > a[node]) return ;
 ans ++ ;
 for(int nd : adj[node]) if(nd != father)
  dfs(nd, node, val + cst[{min(nd, node), max(nd, node)}]);
}
 
 
int main()
{
    cin >> n; 
    for(int i=1 ; i<=n ;i++) 
     cin >> a[i];
    
    for(int i=1 ; i<n ; i++)
     cin >> p >> c, 
     cst[{min(i + 1, p), max(i + 1, p)}] = c, 
     adj[i + 1].push_back(p), 
     adj[p].push_back(i + 1); 
    
    dfs(1, -1, 0);
    cout << n - ans;    
}