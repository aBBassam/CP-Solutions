// Problem: D. Black and White Stripe
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/D
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
int n, k; 
string s; 
int pre[N]; 
 
 
 
void solve( )
{
 cin >> n >> k >> s; 
 s = "*" + s; 
 
 
 for(int i=1 ; i<=n; i++)
  pre[i] = pre[i - 1] + (s[i] == 'W');
 
 int ans = 1e9; 
 for(int i=1 ; i + k - 1 <= n; i++)
  ans = min(ans, pre[i + k - 1] - pre[i - 1]); 
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}