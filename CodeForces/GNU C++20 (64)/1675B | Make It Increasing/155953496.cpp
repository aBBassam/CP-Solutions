// Problem: B. Make It Increasing
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/B
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
 
const int N  = 50; 
ll dp[N][N];
ll n, a[N]; 
 
ll solve(ll i, ll lstOp)
{
 if(i > n) return 0; 
 ll &ret = dp[i][lstOp]; 
 if(ret + 1) return ret;
 
 ll lst = a[i - 1]; 
 while(lstOp --) lst /= 2; 
 ret = 1e9; 
 
 ll done  = 0; 
 ll x = a[i]; 
 while(x > lst)
 {
  ret = min(ret, done + solve(i + 1, done));
  
  x /= 2; 
  done ++; 
 }
 
 return ret; 
}
 
void sl()
{
 cin >> n; 
 for(int i=1 ;i<=n;i++) cin >> a[i]; 
 memset(dp, -1, sizeof dp); 
 
 ll ans = 1e9; 
 ll x = a[n]; 
 ll done = 0; 
 
 for(int done = 0 ; done <= 40 ; done ++)
  ans = min(ans, done + solve(2, done)); 
 
 if(ans >= 1e9) cout << "-1\n";
 else cout << ans << '\n'; 
}
 
 
int main()
{
    test
  sl();
}
 
 
 