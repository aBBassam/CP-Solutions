#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int MAX_VALUE = 1e6 + 10, N = 300100;
int n, m, q; 
vector<pair<int, int>> v; 
vector<int> ps, sts, ens; 
set<int> starts; 
int startRoot[MAX_VALUE + 20], endRoot[MAX_VALUE + 20]; 
 
struct Vertex 
{
    Vertex *l, *r;
    int sum;
 
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
 
Vertex* build(int s, int e) 
{
    if (s == e)
        return new Vertex(0);
    int tm = (s + e) / 2;
    return new Vertex(build(s, tm), build(tm+1, e));
}
 
int get_sum(Vertex* v, int s, int e, int l, int r) 
{
    if (l > r)
        return 0;
    if (l == s && e == r)
        return v->sum;
        
    int tm = (s + e) / 2;
    return get_sum(v->l, s, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, e, max(l, tm+1), r);
}
 
Vertex* update(Vertex* v, int s, int e, int pos, int new_val) 
{
    if (s == e)
        return new Vertex(v->sum + new_val);
    int tm = (s + e) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, s, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, e, pos, new_val));
}
 
 
 
 
int main()
{
 go; 
 cin >> n >> q; 
 for(int i=1 ;i <=n; i++)
 {
  int a, b; 
  cin >> a >> b; 
  v.push_back({a, b}); 
  
  starts.insert(a); 
  
  sts.push_back(a); 
  ens.push_back(b); 
 }
 
 sort(all(v));
 sort(all(sts));
 sort(all(ens)); 
 
 
 vector<Vertex*> roots; 
 roots.push_back(build(0, MAX_VALUE));
 
    for(int i=0 ; i<n; i++)
    {
     if(!startRoot[v[i].F]) startRoot[v[i].F] = i + 1; 
     endRoot[v[i].F] = i + 1; 
     
        roots.push_back(update(roots.back(), 0, MAX_VALUE, v[i].S, 1)); 
 }
 
 
 while(q --)
 {
  cin >> m; 
  ps.resize(m); 
  for(int i=0 ; i<m ;i++) cin >> ps[i];
  ps.push_back(0); 
  ps.push_back(MAX_VALUE); 
  m += 2; 
  sort(all(ps)); 
 
  
  int ans = n;
  for(int i=1 ;i <m ; i++)
  {
   int fr =  ps[i - 1];
   int sc =  ps[i]; 
   
   if((sc - fr) <= 1) continue; 
   
   int f = 0, s = 0; 
   
 
   
   auto it1 = starts.upper_bound(fr); 
   if(it1 != starts.begin())
   {
    it1 --;
    f = get_sum(roots[endRoot[*it1]], 0, MAX_VALUE, fr + 1, sc - 1);
   }
   
   auto it2 = starts.lower_bound(sc); 
   if(it2 != starts.begin())
   {
    it2 --; 
    
    
    s = get_sum(roots[endRoot[*it2]], 0, MAX_VALUE, fr + 1, sc - 1);
   }
  
   ans -= max(0, s - f);
  }
   
  cout << ans << '\n';
 }
}
 
 
 