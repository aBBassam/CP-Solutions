// Problem: B. Also Try Minecraft
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/B
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
 
const int N = 100100; 
ll n, q, a[N], pre[N], suf[N]; 
 
 
 
void solve( )
{
 cin >> n >> q; 
 for(int i=1 ;i <= n; i++) cin >> a[i]; 
 
 for(int i=1 ;i <=n ; i++)
  suf[i] = suf[i - 1] + ((i > 1 && (a[i] > a[i - 1])) ? abs(a[i - 1] - a[i]): 0),
  pre[i] = pre[i - 1] + ((i > 1 && (a[i] < a[i - 1])) ? abs(a[i - 1] - a[i]): 0);
 
 while(q --)
 {
  int l, r; cin >> l >> r; 
  if(r > l)
   cout << pre[r] - pre[l] << '\n';
  else 
   cout << suf[l] - suf[r] << '\n';
 }
}
 
 
int main()
{
   // test
  solve();
}
 
 
 