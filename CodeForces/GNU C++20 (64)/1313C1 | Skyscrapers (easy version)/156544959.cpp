// Problem: C1. Skyscrapers (easy version)
// Contest: Codeforces - Codeforces Round #622 (Div. 2)
// URL: https://codeforces.com/contest/1313/problem/C1
// Memory Limit: 512 MB
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
 
 
const int N = 1010; 
ll n, a[N], b[N]; 
 
 
ll fn(ll ind)
{
 ll ans = a[ind]; 
 ll x = a[ind]; 
 
 for(ll i=ind + 1; i<=n; i++)
 {
  x = min(x, a[i]); 
  ans += x; 
 }
 
 x = a[ind]; 
 
 for(ll i=ind - 1; i>0; i--)
 {
  x = min(x, a[i]); 
  ans += x; 
 }
 
 return ans; 
}
 
 
 
int main()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 
 ll ans = -1; 
 ll ind = 0; 
 for(int i=1 ;i<=n ;i++)
 {
  if(fn(i) > ans)
   ind = i, ans = fn(i); 
 }
 
 
 
 b[ind] = a[ind]; 
 ll x = a[ind]; 
 for(ll i=ind + 1; i<=n; i++)
 {
  x = min(x, a[i]); 
  b[i] = x;  
 }
 
 x = a[ind];
 for(ll i=ind - 1; i>0; i--)
 {
  x = min(x, a[i]); 
  b[i] = x; 
 }
 
 for(ll i=1 ;i <=n; i++) cout << b[i] << ' ';   
}