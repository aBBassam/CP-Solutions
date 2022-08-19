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
int n, m, st, vs[N], col[N]; 
int a, b, exi; 
vector<int> adj[N], rev[N], full[N], path[2]; 
 
 
 
void build(int node)
{
 vs[node] = 1; 
 for(int nd : full[node])
 {
  adj[node].push_back(nd), 
  rev[nd].push_back(node); 
  
  if(!vs[nd])
   build(nd); 
 }
}
 
 
void revDfs(int node, int where, int color, int fr)
{
 if(!fr) col[st] = color; 
 
 path[where].push_back(node); 
 if(node == st) return;
 
 for(int nd : rev[node]) if(col[nd] == color)
 {
  revDfs(nd, where, color, 0); 
  return; 
 }
}
 
void dfs(int node, int color)
{ 
 if(exi) return ;
 if(col[node])
 {
  exi = 1; 
  col[st] = col[node];
  revDfs(node, 0, color, 1); 
  revDfs(node, 1, col[node], 1); 
  return; 
 }
 
 col[node] = color;  
 for(int nd : adj[node]) if(col[nd] != color)
  dfs(nd, color); 
}
 
 
int main()
{
 cin >> n >> m >> st; 
 for(int i=1 ; i<=m ;i++) 
  cin >> a >> b, 
  full[a].push_back(b); 
 build(st);
 
 int cnt = 1; 
 for(int i : adj[st])
  col[st] = cnt, 
  dfs(i, cnt++);  
  
 if(!exi) return cout << "Impossible", 0;
 cout << "Possible\n"; 
 
 reverse(all(path[0])); 
 reverse(all(path[1])); 
 
 
 
 
 int noPar = 1; 
 for(int i : path[1]) if(i == st) noPar = 0; 
 
  cout << path[1].size() + noPar << '\n'; 
  if(noPar) cout << st << ' '; 
 for(int i : path[1]) cout << i << ' '; 
 
 noPar = 1; 
 for(int i : path[0]) if(i == st) noPar = 0; 
 cout << '\n'; 
 cout << path[0].size()  + noPar<< '\n';
 if(noPar) cout << st << ' '; 
 for(int i : path[0]) cout << i << ' ';  
}