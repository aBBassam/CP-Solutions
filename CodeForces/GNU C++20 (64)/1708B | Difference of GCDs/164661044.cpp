// Problem: B. Difference of GCDs
// Contest: Codeforces - Codeforces Round #808 (Div. 2)
// URL: https://codeforces.com/contest/1708/problem/B
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
ll n, l, r, ans[N]; 
 
 
 
void solve( )
{
 cin >> n >> l >> r; 
 
 
 for(int i=1 ; i<=n;i ++)
 {
  ll k = l / i; 
  if(l % i != 0) k ++;
  k *= i;
 
  if(k <= r)  
   ans[i] = k;
  else 
   return void(cout << "NO\n");
 }
 
 cout << "YES\n"; 
 for(int i=1 ; i<=n;i ++) cout << ans[i] << ' ';
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 