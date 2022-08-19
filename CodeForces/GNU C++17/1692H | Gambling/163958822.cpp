// Problem: H. Gambling
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
 
struct node
{
    int pre, suf, sum, ans; 
    node(){
        pre = suf = sum = ans = 0; 
    };
    node(int val){     
     sum = val;
     pre = suf = ans = max(0, val); 
    };
};
 
const int N = 200100;
node seg[4 * N];
ll n, ina[N], a[N];;
 
node Merge(node l,node r)
{
    node c; 
    c.sum = l.sum + r.sum; 
    c.pre = max(l.pre, l.sum + r.pre);
    c.suf = max(r.suf, r.sum + l.suf); 
    c.ans = max(max(l.ans, r.ans), l.suf + r.pre);
    return c; 
}
void update(int p, int s, int e, int i, int v)
{
    if (s == e)
        return void(seg[p] = node(v));
    if (i <= (s + e) / 2)
        update(2 * p, s, (s + e) / 2, i, v);
    else
        update(2 * p + 1, (s + e) / 2 + 1, e, i, v);
    seg[p] = Merge(seg[2 * p], seg[2 * p + 1]);
}
 
node gt(int p, int s, int e, int a, int b)
{
    if (s >= a && e <= b)
        return seg[p];
    if (s > b || e < a)
        return node();
    return Merge(gt(2 * p, s, (s + e) / 2, a, b), gt(2 * p + 1, (s + e) / 2 + 1, e, a, b));
}
 
 
 
set<int> vis; 
map<int, vector<int>> rep; 
 
void solve( )
{
 rep.clear(); 
 vis.clear(); 
 cin >> n; 
 for(int i=1 ;i <=n;i++) cin >> ina[i], rep[ina[i]].push_back(i), update(1, 1, n, i, -1);
 
 ll ans = 0; 
 ll theA = a[1], l = 1, r = 1; 
 
 for(int i=1 ;i <=n; i++) if(vis.count(ina[i]) == 0)
 {
  for(int I : rep[ina[i]]) update(1, 1, n, I, 1); 
  
  vis.insert(ina[i]); 
  
  
  for(int I : rep[ina[i]])
   if(gt(1, 1, n, I, n).ans >= ans)
    ans = gt(1, 1, n, I, n).ans,
    theA = ina[i], 
    l = I; 
   
  for(int I : rep[ina[i]]) update(1, 1, n, I, -1); 
 }
 
 // find r
 cout << theA << ' ' << l << ' ';
 
 ll sm = 0; 
 while(1)
 {
  if(ina[l] == theA) sm ++; 
  else sm --; 
  
  if(sm == ans) break;
  l ++; 
 }
 
 cout << l << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 