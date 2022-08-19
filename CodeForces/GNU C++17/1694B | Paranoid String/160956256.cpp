// Problem: B. Paranoid String
// Contest: Codeforces - Codeforces Round #800 (Div. 2)
// URL: https://codeforces.com/contest/1694/problem/B
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
string s; 
 
 
 
void solve( )
{
 cin >> n >> s; 
 s = "*" + s; 
 
 ll ans = 0; 
 
 for(int i=1 ; i<=  n; i++) 
  if((s[i] == '0' && s[i - 1] == '1') || (s[i] == '1' && s[i - 1] == '0'))
   ans += i;
  else 
   ans ++;
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 