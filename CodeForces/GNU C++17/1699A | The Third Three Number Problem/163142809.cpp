// Problem: A. The Third Three Number Problem
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/A
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
 if(n  & 1) cout << -1 << endl;
 else cout << "0 " << n / 2 << " " << n / 2 << '\n';
 
}
 
 
int main()
{
    test
  solve();
}