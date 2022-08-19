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
    ll pre, sum; 
    node(){
        pre = sum = -1e17; 
    };
    node(ll val){     
     sum = pre = val;
    };
};
 
 
 
const int N = 200100; 
ll n, a[N];
node seg[4 * N];
stack<pair<ll, int>> st; 
 
 
node Merge(node l,node r)
{
 if(l.pre == -1e17)
  return r;
 if(r.pre == -1e17)
  return l; 
 
 
    node c; 
    c.sum = l.sum + r.sum; 
    c.pre = max(l.pre, l.sum + r.pre);
    return c; 
}
void build(int p, int s, int e)
{
    if (s == e)
        return void(seg[p] = node(a[s]));
    build(2 * p, s, (s + e) / 2);
    build(2 * p + 1, (s + e) / 2 + 1, e);
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
 
 
 
 
bool f()
{
 build(1, 1, n);
 while(st.size()) st.pop(); 
 
 
 st.push({1e18, n + 1}); 
 
 for(int i=n ; i > 0 ; i--)
 {
  while(a[i] >= st.top().F) st.pop(); 
  int ind = st.top().S - 1; 
  
  if(ind > i && a[i] < gt(1, 1, n, i, ind).pre)
   return 0; 
  
  
  st.push({a[i], i});
 }
 
 return 1; 
}
 
 
 
 
 
int main()
{
 test
 {
  cin >> n; 
  for(int i=1 ; i<=n; i++) cin >> a[i]; 
  
  int ans = f(); 
  reverse(a + 1, a + n + 1); 
  ans &= f(); 
  
  answer(ans);
 }
}