// Problem: A. Marathon
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/A
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
 
 
 
 
 
void solve( )
{
 
 ll a, k; 
 ll ans = 0; 
 
 cin >> a; 
 for(int i =0 ; i < 3 ; i++)
  cin >> k, 
  ans += (k > a);
  
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 