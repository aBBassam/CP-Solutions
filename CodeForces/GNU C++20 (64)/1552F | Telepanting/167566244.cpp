#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 200100, mod = 998244353; 
 
struct BIT { //1-based index
 
  int n; vector<ll> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  ll query(int i) {
    ll ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i], ans %= mod;
    return ans;
  }
  void update(int i, ll val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val, t[i] %= mod;
  }
  void update(int l, int r, ll val) {
    update(l, val);
    update(r + 1, -val);
  }
  ll query(int l, int r) {
    return (query(r) - query(l - 1) + mod) % mod;
  }
};
 
 
ll n;
map<ll, ll> init, To, costHere, compress; 
vector<pair<ll, ll>> v; 
set<ll> sts; 
 
 
 
 
 
int main()
{
 go; 
 cin >> n; 
 
 v.push_back({0, 0}); 
 for(int i=1 ;i <=n; i++)
 {
  ll a, b; cin >> a >> b >> init[i];  
  v.push_back({a, b}); 
  sts.insert(a);
 }
 
 
 int m = 1; 
 for(ll start : sts) compress[start] = m ++; 
 
 
 BIT sm = BIT(n + 10); 
 
 for(auto it : v)
 {
  costHere[compress[it.F]] = it.F - it.S + sm.query(compress[*sts.lower_bound(it.S)], compress[it.F]);
  costHere[compress[it.F]] %= mod;
  sm.update(compress[it.F], costHere[compress[it.F]]); 
 }
 
 
 ll ans = 0;  
 for(int i=1 ;i <=n; i++) if(init[i]) ans += costHere[compress[v[i].F]], ans %= mod;
  
 cout << (ans + v[n].F + 1) % mod;  
}
 
 