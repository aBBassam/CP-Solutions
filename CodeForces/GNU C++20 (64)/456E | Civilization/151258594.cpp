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
int n, m, q, t, node1, node2, Parent[N], vis[N], dia[N], nw; 
vector<int> adj[N]; 
map<int, int> dist[N]; 
 
 
int root(int x)
{
   return  (x == Parent[x]) ? x : Parent[x] = root(Parent[x]);
}
void merge (int x,int y)
{
    if(root(x) != root(y))
        Parent[root(x)]=root(y);
}
 
 
int main()
{
 go; 
 cin >> n >> m >> q; 
 for(int i=1 ; i<=n ; i++) Parent[i] = i; 
 
 for(int i=0, a, b ; i<m ; i++)
  cin >> a >> b,
  adj[a].push_back(b), 
  adj[b].push_back(a), 
  merge(a, b);
  
 for(int i=1 ; i<=n ; i++) if(!vis[i])
 {
  queue <int> q;
     q.push(i);
     dist[i][i]=0;
  
     while(!q.empty())
     {
         int parent=q.front();
         q.pop();
         for(int son : adj[parent]) if(!dist[i].count(son))       
             vis[son] = 1,
                dist[i][son]=dist[i][parent]+1,
                q.push(son);
     }
     
     int a = i, ds = 0; 
     for(auto it : dist[i]) if(it.S > ds)
      ds = it.S, a = it.F; 
     
     q.push(a);
     dist[a][a] = 0;
     while(!q.empty())
     {
         int parent=q.front();
         q.pop();
         for(int son : adj[parent]) if(!dist[a].count(son))       
             vis[son] = 1,
                dist[a][son]=dist[a][parent]+1,
                q.push(son);
     }
     
     for(auto it : dist[a]) dia[root(i)] = max(dia[root(i)], it.S);
 }
 
 while(q--)
 {
  cin >> t; 
  if(t == 1) cin >> node1, cout << dia[root(node1)] << '\n';
  else 
  {
   cin >> node1 >> node2;
   if(root(node1) == root(node2)) continue;
   nw = ceil(dia[root(node1)] / 2.0) + ceil(dia[root(node2)] / 2.0) + 1,
   dia[root(node2)] = max({dia[root(node1)], dia[root(node2)], nw}),
   merge(node1, node2);
  }
 }
}