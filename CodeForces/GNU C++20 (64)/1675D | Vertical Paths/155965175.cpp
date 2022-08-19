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
int n;
int id; 
vector<int> adj[N], paths[N]; 
 
void dfs(int node)
{
 paths[id].push_back(node); 
 for(int nd : adj[node]) 
  dfs(nd);
 
 if(adj[node].size() == 0) id ++;
}
 
 
void solve()
{
 cin >> n; 
 int root; 
 for(int i=1 ; i<=n; i++)
 {
  ll p; cin >> p; 
  if(p != i)
   adj[p].push_back(i);
  else
   root = i;
 }
 id = 1; 
 dfs(root);
 cout << id - 1 << '\n'; 
 for(int i=1 ;i<= id-1 ; i++)
 {
  cout <<  paths[i].size() << '\n';
  for(int node : paths[i])
   cout << node << ' '; 
  cout << '\n';
 }
 
 for(int i=1 ;i <=n; i++)
  adj[i].clear(), paths[i].clear();
}
 
 
int main()
{
    test
  solve();
}
 
 
 