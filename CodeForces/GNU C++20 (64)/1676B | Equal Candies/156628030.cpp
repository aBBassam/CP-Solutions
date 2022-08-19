// Problem: B. Equal Candies
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/B
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
 
 
 
const int N = 100; 
ll n, a[N]; 
 
 
void solve( )
{
 ll mn = 1e18; 
 ll sm = 0; 
 cin >> n; 
 for(int i=1 ; i<=n; i++) 
  cin >> a[i], sm += a[i], mn = min(mn, a[i]);
 
 cout << sm -  mn * n << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 