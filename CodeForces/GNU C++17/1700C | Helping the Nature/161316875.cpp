// Problem: C. Helping the Nature
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/C
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
ll n, a[N]; 
 
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++)
  cin >> a[i];
 
 ll lev = a[1]; 
 ll sufSub = 0; 
 ll ans = 0; 
 
 
 for(int i=1 ;i <=n; i++)
  if((a[i] - sufSub) < lev)
   ans += lev - (a[i] - sufSub), lev = a[i] - sufSub; 
  else if((a[i] - sufSub) > lev)
   ans += (a[i] - sufSub) - lev, 
   sufSub += (a[i] - sufSub) - lev; 
  
 cout << ans + abs(lev) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 