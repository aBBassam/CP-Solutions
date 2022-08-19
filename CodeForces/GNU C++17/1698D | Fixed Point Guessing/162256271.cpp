// Problem: D. Fixed Point Guessing
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/D
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
 ll n; cin >> n; 
 
 ll s = 1, e = n; 
 while(s <= e)
 {
  ll mid = (s + e) / 2; 
  cout << "? " << s << ' ' << mid << endl;
  
  
  vector<ll> v; 
  v.resize(mid - s + 1); 
  for(auto &it : v) cin >>it; 
 
   ll cnt = 0; 
   
   for(int i : v) if(i >= s && i <= mid)
   cnt ++; 
   
  ll len = mid - s + 1; 
  
  if(cnt % 2 == 1) e = mid - 1; 
  else s = mid + 1; 
  
 }
 
 cout << "! " << s << endl;
}
 
 
int main()
{
    test
  solve();
}
 
 
 