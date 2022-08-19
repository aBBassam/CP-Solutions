// Problem: C. Dolce Vita
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/C
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
ll n, x, a[N], pre[N]; 
 
 
ll mxDays(ll i)
{
 ll ans = 0; 
 ll s = 1, e = 1e9; 
 
 while(s <= e)
 {
  ll mid = (s + e) / 2;  // = days
  
  ll cost = pre[i] + i * (mid - 1);
 
  if(x >= cost) ans = mid, s = mid + 1; 
  else e = mid - 1;
 }
 
 return ans; 
}
 
 
void solve()
{ 
 cin >> n >> x; 
 for(int i=1 ; i<=n ;i++)
  cin >> a[i]; 
 
 sort(a + 1, a + n + 1);
 
 ll ans = 0; 
 for(int i=1 ; i<=n; i++)
  pre[i] = pre[i - 1] + a[i]; 
 
 for(int i=1 ; i<=n ;i++)
  ans += mxDays(i); 
  
 cout << ans << '\n';
}
 
int main()
{
    test
  solve();
}
 
 
 