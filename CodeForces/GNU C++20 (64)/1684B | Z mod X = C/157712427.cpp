// Problem: B. Z mod X = C
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/B
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
 
 
ll a, b, c; 
 
 
void solve( )
{
 ll x, y, z; 
 cin >> a >> b  >> c; 
 
 y = b; 
 z = c;  
 c ++; 
 c *= 5; 
 
 ll rem = c % y; 
 c -= rem;
 c += a; 
 x = c; 
 
 cout << x << ' ' << y << ' ' << z << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 