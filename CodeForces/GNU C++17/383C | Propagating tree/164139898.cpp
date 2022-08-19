#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int t; cin >> t; while(t--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
#define T int
using namespace std;
 
 
const int N = 200100; 
vector <int> adj[N]; 
vector<pair<int, int>> evenIns, oddIns; 
int n, q, Time = 0, a[N], isEven[N], in[N], out[N], thisInIsForNode[N], indexInIns[N];
 
int seg[4 * N][2], lazy[4 * N][2];
 
 
void chk(int p, int s, int e, int dim)
{
    if (lazy[p][dim])
    {
        seg[p][dim] += lazy[p][dim] * (e - s + 1);
 
        if (s != e)
        {
            lazy[2 * p][dim] += lazy[p][dim],
            lazy[2 * p + 1][dim] += lazy[p][dim];
        }
        
        lazy[p][dim] = 0;
    }
}
 
int Merge(int A, int B)
{
 return A + B; 
}
 
void update(int p, int s, int e, int a, int b, int v, int dim = 0)
{
    chk(p, s, e, dim);
 
    if (b < s || e < a)
        return;
        
    if (a <= s && e <= b)
    {
        lazy[p][dim] = v;
        chk(p, s, e, dim);
        return;
    }
 
    update(2 * p, s, (s + e) / 2, a, b, v, dim);
    update(2 * p + 1, (s + e) / 2 + 1, e, a, b, v, dim);
 
    seg[p][dim] = Merge(seg[2 * p][dim], seg[2 * p + 1][dim]);
}
int gt(int p, int s, int e, int a, int b, int dim = 0)
{
    chk(p, s, e, dim);
    if (s >= a && e <= b)
        return seg[p][dim];
    if (s > b || e < a)
        return 0;
    return Merge(gt(2 * p, s, (s + e) / 2, a, b, dim), gt(2 * p + 1, (s + e) / 2 + 1, e, a, b, dim));
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
void dfs(int node, int par, int ev)
{
 in[node] = Time; 
 thisInIsForNode[Time] = node; 
 isEven[node] = ev; 
 
 if(ev) evenIns.push_back({in[node], node}); 
 else oddIns.push_back({in[node], node}); 
 
 for (int nd : adj[node]) if(nd != par)
  Time ++, dfs(nd, node, !ev); 
 
 out[node] = Time; 
}
 
int main()
{
 cin >> n >> q; 
 for(int i=1 ; i<=n ; i++) cin >> a[i];
 for(int i=1, a, b ; i< n; i++)
  cin >> a >> b, 
  adj[a].push_back(b), 
  adj[b].push_back(a); 
  
 dfs(1, 0, 1);
 
 sort(all(evenIns)); 
 sort(all(oddIns)); 
 
 int od = oddIns.size(); 
 int ev = evenIns.size();
 
 
 
 
 for(int i=0 ; i < evenIns.size() ; i++) indexInIns[evenIns[i].S] = i; 
 for(int i=0 ; i < oddIns.size() ; i++) indexInIns[oddIns[i].S] = i; 
 
 for(auto node : evenIns) update(1, 0, ev - 1, indexInIns[node.S], indexInIns[node.S], a[node.S], 0);
 for(auto node : oddIns) update(1, 0, od - 1, indexInIns[node.S], indexInIns[node.S], a[node.S], 1); 
   
 
 
 while(q --)
 {
  int task, x; cin >> task >> x;
  if(task == 1)
  {
   int v; cin >> v; 
   int lastNodeInSubTree = thisInIsForNode[out[x]];
   
   if(isEven[x])
   {
    auto it = upper_bound(all(evenIns), make_pair(in[lastNodeInSubTree], lastNodeInSubTree)); 
    it --; 
    
    update(1, 0, ev - 1, indexInIns[x], indexInIns[it->S], v, 0);
    
  
    it = upper_bound(all(oddIns), make_pair(in[x], x));
    if(it != oddIns.end() && in[it->S] <= out[x])
    {
     int fr = it->S; 
     it = upper_bound(all(oddIns), make_pair(in[lastNodeInSubTree], lastNodeInSubTree)); 
     it --; 
    // cout << indexInIns[fr] << q << " " << 0 <<   ' ' << indexInIns[it->S] <<" " << v <<  endl;
     update(1, 0, od - 1, indexInIns[fr], indexInIns[it->S], -v, 1);
    }
   }
   else
   {
    auto it = upper_bound(all(oddIns), make_pair(in[lastNodeInSubTree], lastNodeInSubTree)); 
    it --; 
    //cout << indexInIns[x] << q << " " << 0 <<   ' ' << indexInIns[it->S] << " " << v << endl;
    
    update(1, 0, od - 1, indexInIns[x], indexInIns[it->S], v, 1);  
 
    it = upper_bound(all(evenIns), make_pair(in[x], x));
    if(it != evenIns.end() && in[it->S] <= out[x])
    {
     int fr = it->S; 
     
     it = upper_bound(all(evenIns), make_pair(in[lastNodeInSubTree], lastNodeInSubTree)); 
     it --; 
  
     //cout << indexInIns[x] << q << " " << 1 <<   ' ' << indexInIns[it->S] <<" " << v <<  endl;
     update(1, 0, ev - 1, indexInIns[fr], indexInIns[it->S], -v, 0);
    }
   }
  } 
  else 
  {
   if(isEven[x]) cout << gt(1, 0, ev - 1, indexInIns[x], indexInIns[x], 0); 
   else cout << gt(1, 0, od - 1, indexInIns[x], indexInIns[x], 1);  
   
   cout << '\n';
  }
 }
}
 
 
 