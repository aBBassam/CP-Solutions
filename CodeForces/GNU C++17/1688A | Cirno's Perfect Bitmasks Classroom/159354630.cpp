// Problem: A. Cirno's Perfect Bitmasks Classroom
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.com/contest/1688/problem/A
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
 
 
 
ll n; 
 
 
void solve( )
{
 cin >> n; 
 ll ans; 
 
 
 for(ll i=0; ; i++) if(((1ll << i) & n) != 0)
 {
  ans = (1ll << i); 
  break;
 }
 
 if(ans == n)
 for(ll i=0; ; i++) if(((1ll << i) & ans) == 0)
 {
  ans += (1ll << i); 
  break;
 } 
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 