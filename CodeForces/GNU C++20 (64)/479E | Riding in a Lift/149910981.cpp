#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 5010, mod = 1e9 + 7; 
ll n , a, d, k, lst, dp[N], swp[N], pre[N], f[N];
 
 
int main()
{
 go;
 cin >> n >> a >> d >> k;
 dp[a] = 1; 
 
 for(int i=1 ; i<=n ;i++) f[i] = -1;
 
 lst = d - 3; 
 for(int i=d-2 ; i>0 ; i--) // when i < d : st = 1 , en = f[i]
  while(lst >= 2 * i - d + 1 && lst > 0)
   f[lst --] = i; 
 
 
 lst = d + 3; 
 for(int i=d + 2 ; i <= n ;i++) // when i > d : st = f[i] , en = n
  while(lst <= 2 * i - d - 1 && lst <= n) 
   f[lst ++] = i; 
 
 for(int i=1 ; i<=k ; i++)
 {
  for(int i=1 ; i<=n ; i++) 
   swp[i] = dp[i], pre[i] = pre[i - 1] + dp[i], pre[i] %= mod, dp[i] = 0;
    
  for(int i=1 ; i<=n ; i++)
   if(i < d)
   {
    dp[i] = pre[i] - swp[i] + mod; 
    if(f[i] + 1) dp[i] += pre[f[i]] - pre[i] + mod;
    dp[i] %= mod;
   } 
   else if(i > d)
   {
    dp[i] = pre[n] - pre[i] + mod;
    if(f[i] + 1) dp[i] += pre[i - 1] - pre[f[i] - 1] + mod;
    dp[i] %= mod; 
   }
 }
 
 ll ans = 0 ; 
 for(int i=1 ; i<=n; i++) ans += dp[i];
 cout << ans % mod;
}