// Problem: B. Array Cloning Technique
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/B
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
 
 
const int N = 100100; 
ll n, a[N]; 
map<ll, int> rep; 
 
void solve( )
{
 rep.clear(); 
 cin >> n; 
 for(int i=0 ; i<n ; i++) cin>> a[i], rep[a[i]] ++; 
 
 ll mx = 0; 
 for(auto it : rep)
  if(it.S > mx) mx = it.S; 
  
 
 ll rem = n - mx, ans = 0; 
 while(rem > 0)
 {
  ans += min(mx, rem) + 1;
  rem -= mx; 
  mx *= 2; 
 }
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}