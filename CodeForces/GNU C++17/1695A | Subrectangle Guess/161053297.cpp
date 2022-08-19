// Problem: A. Subrectangle Guess
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/0
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
 
ll n, m; 
ll a[55][55]; 
 
 
 
 
void solve( )
{ 
 cin >> n >> m; 
 
 ll mx = -1e18; 
 for(int i=1 ;i <=n; i++)
  for(int j=1 ; j<=m ; j++)
   cin >> a[i][j], mx = max(mx, a[i][j]); 
 
 
 for(ll i=1 ;i <=n; i++)
  for(ll j=1 ; j<=m ; j++) 
   if(a[i][j] == mx)
   {
    
    ll h = max(i, n - i + 1); 
    ll k = max(j, m - j + 1); 
    
    cout << h * k << '\n';
    break; 
   }
}
 
 
int main()
{
    test
  solve();
}
 
 
 