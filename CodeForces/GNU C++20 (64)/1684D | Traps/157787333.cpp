// Problem: D. Traps
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/D
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
ll n, k, a[N], take[N]; 
set<pair<ll, ll>> st;
 
 
void solve( )
{
 st.clear(); 
 cin >> n >> k; 
 for(int i=1 ;i<= n; i++) cin >> a[i], take[i] = 0; 
 
 for(int i=1 ; i<=n; i++)
  st.insert({-(a[i] - (n - i)), i}); 
 
 
 for(auto it : st) if(k) take[it.S] = 1, k--; 
 
 ll ans = 0, carry = 0; 
 for(int i=1 ; i<=n; i++)
 {
  if(take[i]) carry ++; 
  else ans += a[i] + carry;
 }
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 