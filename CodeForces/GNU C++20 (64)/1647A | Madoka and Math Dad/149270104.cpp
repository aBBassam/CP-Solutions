// Problem: A. Madoka and Math Dad
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.com/contest/1647/problem/0
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
 
 
 
ll n; 
 
void solve( )
{
 cin >> n; 
 
 
 if(n == 1) return void(cout << 1 << endl); 
 else if(n == 2) return void(cout << 2 << endl); 
 
 ll i = n % 3; 
 
 
 while(n)
 {
  ll nm = i % 2 == 0  ? 2 : 1; 
  n -= nm; 
  cout << nm;
  i++;
 }
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 