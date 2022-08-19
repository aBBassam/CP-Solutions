// Problem: A. Optimal Path
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/A
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
 
 
ll n, m; 
 
 
void solve( )
{
 cin >> n >> m; 
 
 ll fr = (m * ( m - 1 )) / 2; 
 ll sc = (n * ( m + n * m )) / 2;
  
 cout << fr + sc << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 