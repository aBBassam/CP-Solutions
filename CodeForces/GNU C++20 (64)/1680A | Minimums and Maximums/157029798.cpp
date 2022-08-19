// Problem: A. Minimums and Maximums
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1680/problem/0
// Memory Limit: 512 MB
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
 
 
 
ll l1, l2, r1, r2; 
 
void solve( )
{
 cin >> l1 >> r1 >> l2 >> r2; 
 
 ll ans1 = 1e18, ans2 = 1e18, ans3 = 1e18; 
 
 if(r2 >= r1 && l2 <= r1)
  ans1 = max(l1, l2);
  
 if(r1 >= r2 && l1 <= r2)
  ans2 = max(l1, l2); 
  
 ans3 = l1 + l2; 
 
 
 cout << min(ans1, min(ans2, ans3)) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 