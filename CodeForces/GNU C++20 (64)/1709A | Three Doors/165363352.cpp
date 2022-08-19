// Problem: A. Three Doors
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/A
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
 
 
int a[10]; 
int n, x; 
 
 
 
void solve( )
{
 cin >> x; 
 for(int i=0 ; i < 10 ; i++) a[i] = 0;
 cin >> a[1] >> a[2] >> a[3]; 
 answer(a[x] && a[a[x]] && (a[a[x]] != a[x]));
}
 
 
int main()
{
    test
  solve();
}
 
 
 