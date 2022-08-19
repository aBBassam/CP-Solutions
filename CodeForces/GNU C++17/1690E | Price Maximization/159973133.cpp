// Problem: E. Price Maximization
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/E
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
 
 
const int N = 200100; 
ll n, k;
multiset<ll, greater<ll>> st;
multiset<ll> st2; 
 
 
 
void solve( )
{
 ll ans = 0; 
 st.clear(); 
 st2.clear(); 
 
 cin >> n >> k; 
 for(int i=1 ; i<=n; i++)
 {
  ll tmp; cin >> tmp; 
  ans += (tmp / k);
  
  if(tmp % k)
   st.insert(tmp % k), 
   st2.insert(tmp % k); 
 }
 
 
 while(st.size() >= 2)
 {
  ll fr = *st.begin(); 
  
  st.erase(st.begin()); 
  st2.erase(st2.find(fr)); 
  
  auto it = st2.lower_bound(k - fr); 
  if(it == st2.end()) continue;
  
  ans ++; 
  
  st2.erase(it); 
  st.erase(st.find(*it)); 
 }
  
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 