// Problem: A. Digit Minimization
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/0
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
 
 
int n;
string s; 
 
 
void solve( )
{
 cin >> s ;
 n = s.length(); 
 
 
 if(n == 2)
 {
  cout << s[1];
 }
 else 
 {
  sort(all(s)); 
  cout << *min(all(s)); 
 }
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 