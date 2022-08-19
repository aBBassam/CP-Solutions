// Problem: A. Array Balancing
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/0
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
 
 
int n, a[1010], b[1010]; 
 
 
void solve( )
{ 
 cin >> n; 
  
 
 for(int i=1 ;i <=n; i++) cin >> a[i]; 
 for(int i=1 ;i <=n; i++) cin >> b[i]; 
 
 
 for(int i=1 ; i<=n; i++)
 {
  if(b[i] > a[i]) swap(a[i], b[i]);
  }
 
 ll ans = 0; 
 for(int i=2 ; i<= n;  i++) 
  ans += abs(a[i] - a[i-1]) + abs(b[i] - b[i - 1]);
 
 cout << ans << '\n';
 
}
 
 
int main()
{
    test
  solve();
}
 
 
 