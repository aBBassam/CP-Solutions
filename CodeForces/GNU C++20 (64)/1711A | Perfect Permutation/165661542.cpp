// Problem: A. Perfect Permutation
// Contest: Codeforces - Codeforces Round #810 (Div. 2)
// URL: https://codeforces.com/contest/1711/problem/A
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
 int n; cin >> n; 
 
 if(n%2 == 0)
 {
  for(int i = 1 ; i<=n; i+=2)
  {
   cout << i + 1 << ' ' << i << ' ';
  }
 }
 else 
 {
  cout << 1 << ' '; 
  for(int i = 2 ; i<=n; i+=2)
  {
   cout << i + 1 << ' ' << i << ' ';
  }
 }
 
 cout << "\n"; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 