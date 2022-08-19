// Problem: D. Required Length
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/D
// Memory Limit: 512 MB
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
 
 
ll n, x;
map<ll, ll> dp; 
 
ll f(ll nm)
{
 if(dp.count(nm) != 0) 
  return dp[nm];
  
  
 if(nm == 0) return 1e9;
 if((int)to_string(nm).size() > n) return 1e9;
 if((int)to_string(nm).size() == n) return 0; 
 
 string s = to_string(nm); 
 int nn = s.size(); 
 
 int ntZO = 0; 
 for(int i=0 ;i <nn; i++)
  ntZO |= (s[i] != '0' && s[i] != '1'); 
 
 ll ret = 1e9; 
 for(int i=0 ; i<nn; i++) if(s[i] != '1')
  ret = min(ret, 1 + f(nm * (s[i] - '0'))); 
  
 return dp[nm] = ret; 
}
 
 
 
int main()
{
 cin >> n >> x;  
 if(x == 1) return cout << -1, 0;
 ll ans = f(x); 
 if(ans >= 1e9) ans = -1; 
 cout << ans; 
}
 
 
 