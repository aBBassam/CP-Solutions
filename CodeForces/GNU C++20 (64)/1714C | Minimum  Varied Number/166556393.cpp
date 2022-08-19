// Problem: C. Minimum Varied Number
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/C
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
 
 
 
ll fstPO(ll x, ll y, ll m = 1e18) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
ll ans[50]; 
const ll K = (1ll << 12) + 12;
bool vis[K]; 
 
 
void solve()
{
 int n; cin >> n; 
 cout << ans[n] << '\n'; 
}
 
 
void f(ll mask)
{ 
 ll sm = 0; 
 for(ll i=0 ;i < 10 ; i++)
  if(mask&(1ll << i))
   sm += i;
 
 
 if(sm > 45) return ;
 
 ll k = 0; 
 ll di = 0; 
 
 for(ll i=10 ;i >= 0 ; i--)
  if(mask&(1ll << i))
   k += fstPO(10, di ++) * i; 
   
 ans[sm] = min(ans[sm], k); 
 vis[mask] = 1; 
 
  for(ll i=0 ;i < 10 ; i++)
  if((mask&(1ll << i)) == 0) if(!vis[mask | (1ll << i)])
   f(mask | (1ll << i)); 
}
 
 
 
int main()
{
 for(int i=0 ; i< 50 ; i++) ans[i] = 1e9;  
 f(1ll<<11); 
 
 test 
  solve(); 
}
 
 