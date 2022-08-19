// Problem: B. Permutation
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
ll fstPO(ll x, ll y, ll m = 1e18) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
 
 
const int N = 200100; 
ll n; 
bool vis[N]; 
 
 
void solve( )
{
 cin >> n; 
 cout << "2\n"; 
 
 for(int i=1 ;i <=n; i++) if(!vis[i])
 {
  vis[i] = 1; 
  cout << i << ' '; 
  
  ll j = i; 
  
  while((j * 2) <= n && !vis[j * 2])
   j *= 2, 
   vis[j] = 1, 
   cout << j << ' '; 
 }
  
  
  
 cout << '\n'; 
 for(int i=1 ;i <=n; i++) vis[i] = 0; 
}
 
 
int main()
{
    test
  solve();
}