// Problem: H. Maximal AND
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/H
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
ll n, k, a[N], bts[50]; 
 
 
void solve()
{ 
 cin >> n >> k; 
 for(int i=1 ;i<=n ;i++) cin >> a[i]; 
 for(int i=0 ;i<=30 ; i++) bts[i] = 0;  
 
 for(int i=1 ;i<=n ;i++)
  for(ll bt = 0; bt <= 30 ; bt++) if(a[i] & (1 << bt))
   bts[bt]++;  
 
 ll ans = 0; 
 for(ll i=30 ; i>=0 ; i--)
 {
  ll rem = n - bts[i]; 
  if(rem > k) continue; 
  k -= rem; 
  ans += (1 << i);
 }
 
 cout << ans << '\n';
}
 
 
int main()
{ 
    test
  solve();
}