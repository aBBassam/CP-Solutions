// Problem: A. Difference Operations
// Contest: Codeforces - Codeforces Round #808 (Div. 2)
// URL: https://codeforces.com/contest/1708/problem/A
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
 
 
const int N = 1011; 
ll n, a[N]; 
 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ;i <=n;i ++) cin >> a[i]; 
 
 ll gc = a[1]; 
 
 for(int i=2 ; i<=n ; i++)
  if(!gc || (a[i] % gc != 0)) return void(cout << "NO\n"); 
  else gc == __gcd(gc, a[i]);
 
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 