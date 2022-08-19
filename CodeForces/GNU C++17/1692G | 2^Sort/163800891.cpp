// Problem: G. 2^Sort
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/G
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
ll n, q, a[N]; 
 
 
void solve( )
{
 cin >> n >> q; 
 q ++; 
 
 for(int i=1 ;i <=n;i++)
  cin >> a[i]; 
  
 ll ans = 0; 
 
 int k = 1; 
 while(k <= n)
 {
  int st = k, en = st + 1; 
  
  while(en <= n && a[en] * 2 > a[en - 1]) en++;  
  
  ll len = en - st; 
  if(len >= q)
  {
   ans += len - q + 1; 
  }
  
  k = en; 
  if(st == en)
   k ++;
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 