// Problem: A. Round Down the Price
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/0
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
 
 
ll fstPO(ll x, ll y, ll m = 1e18) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
 
void solve( )
{
 ll n; cin >> n; 
 
 
 int i = 0; 
 for(; i<=10; i++)
 {
  if(fstPO(10, i) > n) break;
 }
 i --;
 
 cout << n - fstPO(10, i) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 