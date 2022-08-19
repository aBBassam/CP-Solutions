// Problem: F. Longest Strike
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int N = 200100; 
ll n, k, a[N]; 
vector<pair<ll, ll>> v; 
set<pair<ll, int>> st; 
map<ll, int> rep; 
 
 
void solve()
{
 v.clear();
 st.clear(); 
 rep.clear(); 
 
 cin >> n >> k;
 for(int i=1 ;i<=n; i++) cin >> a[i], rep[a[i]] ++; 
 
 for(auto it : rep) 
  st.insert({it.F, (it.S >= k ? 1 : 0)}); 
 
 ll lst = 0; 
 for(auto it : rep) 
 {
  if(lst + 1 != it.F)
   st.insert({it.F - 1, 0});
  lst = it.F; 
 }
 
 for(auto it : st)
  v.push_back({it.F, it.S}); 
 
 int n = v.size(); 
 ll ans = 0, nm; 
 for(int i=0 ; i<n ;i++) if(v[i].S == 1)
 {
  ll l_ans = 0; 
  ll l_nm = v[i].F; 
  
  while(i < n && v[i].S == 1)
   l_ans ++, i ++; 
  
  if(l_ans > ans)
   nm = l_nm, ans = l_ans; 
 }
 
 if(!ans) cout << "-1\n"; 
 else cout << nm << ' ' << nm + ans - 1 << '\n'; 
}
 
 
int main()
{
    test
  solve();
}