// Problem: B2. Tokitsukaze and Good 01-String (hard version)
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/B2
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
ll n, dp[N][2][2]; 
string s; 
 
 
ll solve(int i, int zeroRem, int oneRem)
{
 oneRem %= 2, zeroRem %= 2; 
 if(i > n) return max(zeroRem, oneRem) > 0 ? 1e9 : 0; 
 ll &ret = dp[i][zeroRem][oneRem]; 
 if(ret + 1) return ret; 
 ret = 1e9; 
 
 // can flip it to 0 or 1
 if(!max(zeroRem, oneRem)) 
 {
  // flip to one
  ret = min(ret, (s[i] == '0') + solve(i + 1, 0, 1));
  
  // flip to zero
  ret = min(ret, (s[i] == '1') + solve(i + 1, 1, 0));
 }
 
 if(oneRem)
  ret = min(ret, (s[i] == '0') + solve(i + 1, 0, 0));
 
 if(zeroRem)
  ret = min(ret, (s[i] == '1') + solve(i + 1, 0, 0));
 
 return ret;
} 
 
int main()
{
 test
 {
  cin >> n >> s, s = "&" + s; 
  for(int i=1 ; i<=n; i++)
   for(int j=0 ; j<2 ; j++)
    for(int k=0 ; k<2 ; k++)
     dp[i][j][k] = -1; 
     
  cout << solve(1, 0, 0) << '\n'; 
 }
}