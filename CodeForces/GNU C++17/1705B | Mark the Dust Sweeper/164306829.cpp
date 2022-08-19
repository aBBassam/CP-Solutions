// Problem: B. Mark the Dust Sweeper
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
 ll sm = 0; 
 
 cin >> n; 
 for(int i=1 ;i <=n; i++)
  cin >> a[i], 
  sm += a[i]; 
 
 sm -= a[n];
 
 int fr = n; 
 int done = 0; 
 ll prev = 0; 
 ll ans = 0; 
 
 for(int i=1 ;i < n; i++) if(done || a[i])
 { 
  if(!done) fr = i; 
  done = 1; 
  
  prev += a[i]; 
  
  if(a[i] == 0 && prev)
   prev --, a[i] ++, ans ++; 
 }
 
 for(int i=fr ; i < n; i++)
  if(!a[i]) ans ++;
 
 
 cout << ans  + sm << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 