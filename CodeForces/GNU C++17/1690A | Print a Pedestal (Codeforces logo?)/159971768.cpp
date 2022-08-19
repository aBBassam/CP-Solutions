// Problem: A. Print a Pedestal (Codeforces logo?)
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/A
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
 
 
 
 
 
void solve( )
{
 ll n; cin >> n;
 n -= 3; 
 
 ll A = n / 3 + 2;
 if(n % 3 != 0) A ++; 
 
 ll rem = n + 3 - A; 
 
 ll B = rem / 2 + 1; 
 ll C = rem - B; 
 
 cout << B << ' ' << A << ' ' << C << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 