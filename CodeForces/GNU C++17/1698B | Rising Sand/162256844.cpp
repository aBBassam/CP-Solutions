// Problem: B. Rising Sand
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/B
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
ll n, k, a[N]; 
 
 
void solve( )
{
 cin >> n >> k; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 
 ll ans = 0; 
 for(int i=1 ; i<=n; i++)
  if((i - 1 >= 1) && (i + 1 <= n))
  {
   if(k == 1) i ++, ans ++; 
   else if(a[i] > (a[i + 1] + a[i -1]))
    ans ++; 
  }
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}