// Problem: A. Grass Field
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/A
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
 
 
int a, b, c, d; 
 
 
void solve( )
{
 cin >> a >> b >> c >> d; 
 int sm = a + b + c + d; 
 
 if(sm == 0) cout << 0; 
 else if(sm == 4) cout << 2; 
 else cout << 1; 
 
 cout << endl;
}
 
 
int main()
{
    test
  solve();
}
 
 
 