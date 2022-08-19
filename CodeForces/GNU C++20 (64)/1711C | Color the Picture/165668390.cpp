// Problem: C. Color the Picture
// Contest: Codeforces - Codeforces Round #810 (Div. 2)
// URL: https://codeforces.com/contest/1711/problem/C
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
 
const int K = 100100; 
ll n, m, k, a[K]; 
 
 
bool sl(int n, int m)
{
 bool haveEx = 0; 
 ll rem = m; 
 
 
 for(int i=1 ; i<= k ; i ++) if(rem)
 {
  ll r = a[i] / n; 
  if(r >= 2)
  {
   if(r > 2) haveEx = 1; 
   
   if(rem == 1)
   {
    if(haveEx) rem = 0; 
   }
   else rem -= min(rem, r);
  }
 }
 
 
 return rem == 0; 
}
 
void solve( )
{
 cin >> n >> m >> k; 
 for(int i=1 ; i <= k ; i ++) cin >> a[i]; 
 answer(sl(n, m) || sl(m, n));
}
 
 
int main()
{
    test
  solve();
}
 
 
 