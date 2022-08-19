// Problem: C. Directional Increase
// Contest: Codeforces - Codeforces Round #800 (Div. 2)
// URL: https://codeforces.com/contest/1694/problem/C
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
 
const int N = 200100; 
ll n, a[N]; 
 
 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ;i <=n; i++)
  cin >> a[i];  
  
  
 ll sm = 0; 
 for(int i=1 ; i<=n; i++)
 {
  sm += a[i]; 
  if(sm < 0) return void(cout << "NO\n"); 
  else if(sm == 0)
  {
   i++; 
   while(i <= n)
    if(a[i++]) return void(cout << "NO\n");
   return void(cout << "YES\n"); 
  }
 }
 
 if(sm) return void(cout << "NO\n");
}
 
 
int main()
{
    test
  solve();
}