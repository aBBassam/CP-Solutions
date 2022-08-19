// Problem: A. XOR Mixup
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/A
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
 
 
const int N = 110; 
ll n, a[N];
 
 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ;i <=n; i++) cin >> a[i];
 
 
 for(int i=1 ;i <=n; i++)
 {
  
  ll x = 0;
  
  for(int j=1 ; j<=n ; j++) if(i != j)
   x ^= a[j];
   
   
  if(x == a[i]) 
   return void(cout << x << '\n');
 }
}
 
 
int main()
{
    test
  solve();
}
 
 
 