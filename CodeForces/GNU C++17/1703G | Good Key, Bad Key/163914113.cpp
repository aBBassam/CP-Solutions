// Problem: G. Good Key, Bad Key
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
 
 
ll fstPO(ll x, ll y, ll m = 1e18) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
const int N = 100100; 
ll n, k, dp[N][40], a[N]; 
 
 
ll solve(int i, int twos)
{
 if(twos > 32) return 0; 
 if(i > n) return 0; 
 
 
 ll &ret = dp[i][twos]; 
 if(ret + 1) return ret; 
 ret = 0; 
 
 ll gt = (a[i]) / (fstPO(2, twos));
 
 
 ll ret1 = gt - k + solve(i + 1, twos); // good key
 
 gt /= 2;
 ll ret2 = gt + solve(i + 1, twos + 1);
 
 return ret = max(ret1, ret2);
}
 
 
void sl()
{
 cin >> n >> k; 
 for(int i=1 ;i <=n;i++) cin >> a[i]; 
 
 for(int i=1 ; i<=n; i++)
  for(int j=0 ; j<40 ; j++)
   dp[i][j] = -1; 
 
 cout << solve(1, 0) << '\n'; 
}
 
 
int main()
{
    test
  sl();
}
 
 
 