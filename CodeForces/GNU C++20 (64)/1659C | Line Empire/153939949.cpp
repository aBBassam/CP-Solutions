// Problem: C. Line Empire
// Contest: Codeforces - Codeforces Round #782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/C
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
ll n, a, b, ar[N], suf[N]; 
 
 
 
void solve()
{
 cin >> n >> b >> a; 
 for(int i=1 ; i<=n; i++) cin >> ar[i]; 
 
 suf[n + 1] = 0;
 for(int i=n ; i>0 ;i--)
  suf[i] = suf[i + 1] + ar[i]; 
  
 ll ans = 0, capital = 0; 
 
 for(int i=1 ;i <= n;i++)
 {
  ans += a * (ar[i] - capital); 
  
  ll rem = n - i; 
  ll makeMeCapital = b * (ar[i] - capital) + a * ((suf[i + 1] - (rem * ar[i])) - (suf[i + 1] - (rem * capital)));
  
  if(makeMeCapital <= 0 && i != n)
  {
   ans += b * (ar[i] - capital); 
   capital = ar[i]; 
  } 
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}