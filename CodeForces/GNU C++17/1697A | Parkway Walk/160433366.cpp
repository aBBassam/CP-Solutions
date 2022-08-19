// Problem: A. Parkway Walk
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/A
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
 
 
const int N = 1010; 
ll n, m, a[N]; 
 
 
void solve( )
{
 ll ans = 0; 
 cin >> n >> m; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 
 for(int i=1 ; i<=n; i++)
 {
  ll ad = 0; 
  if(a[i] > m)
   ad = a[i] - m; 
   
  m -= a[i];
  m += ad; 
  ans += ad; 
 }
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 