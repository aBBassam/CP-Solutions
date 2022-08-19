// Problem: C. LIS or Reverse LIS?
// Contest: Codeforces - Codeforces Round #793 (Div. 2)
// URL: https://codeforces.com/contest/1682/problem/C
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
map<ll, int> rep;  
 
 
 
void solve( )
{
 rep.clear(); 
 cin >> n; 
 for(int i=1 ;i<=n; i++) cin >> a[i], rep[a[i]] ++; 
 
 
 ll once = 0, repeated = 0, ans = 0;
 
 for(auto it : rep) 
  if(it.S == 1) once ++; 
  else repeated ++; 
 
 ll x = 0; 
 if(once) once --, x ++; 
 
 for(ll i=1 ; i<=n;  i++) // LIS(A) = i
 {
  // take repeated first
  ll j = repeated + once + x; 
  ll rem = i - (repeated + x);
  if(rem > 0)
   j -= rem; 
  
  ans = max(ans, min(i, j)); 
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 