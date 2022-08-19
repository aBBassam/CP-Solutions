#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const ll N = 200100, INF = 1e18; 
ll n, k, a[N]; 
map<ll, ll> rep;
multiset<ll> reps;
 
 
ll chk(ll mid) 
{ 
 ll cnt = 0; 
 for(auto it : rep) if(it.F < mid) cnt ++; 
 return ((k >= (mid - cnt)) && (n >= mid)) ?  (mid - cnt) : INF;
}
 
 
void solve( )
{
 rep.clear(), reps.clear(); 
 
 cin >> n >> k; 
 for(int i=1 ;i<=n ;i++) cin >> a[i], rep[a[i]] ++; 
 
 ll st = 0, en = 1e9, mex = 1e9, req = 1e9; 
 while(st <= en)
 {
  ll mid = (st + en) / 2; 
 
  if(chk(mid) != INF) mex = mid, req = chk(mid), st = mid + 1; 
  else en = mid - 1; 
 }
 
 for(auto it : rep) 
  if(it.F > mex) reps.insert(it.S);
  
 ll dif = mex + reps.size(); 
 
 while(k && reps.size())
 {
  ll val = (*reps.begin()) - 1; 
  reps.erase(reps.begin()); 
  k--; 
  
  if(val) reps.insert(val); 
  else dif--; 
 }
  
 cout << dif - mex << '\n';
}
 
 
int main()
{
    test
  solve();
}