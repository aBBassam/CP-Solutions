// Problem: C. Most Similar Words
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/C
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
 
const int N = 60; 
 
int n, m; 
string s[N]; 
 
ll f(string a, string b)
{
 ll ans  = 0; 
 
 for(int j=1 ;j<=m ;j++)
  ans +=  abs(max(b[j], a[j]) - min(a[j], b[j]));
 
 return ans;
}
 
 
 
void solve( )
{ 
 ll ans = 1e18; 
 cin >> n >> m; 
 
 for(int i=1 ;i <=n; i++)
  cin >> s[i], s[i] = "&" + s[i]; 
  
  
 for(int i=1 ;i <=n; i++) 
  for(int j=i+1; j<=n; j++)
   ans = min(ans, f(s[i], s[j]));
  
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}