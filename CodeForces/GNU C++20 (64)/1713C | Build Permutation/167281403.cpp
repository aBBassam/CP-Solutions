// Problem: C. Build Permutation
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/C
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
 
 
const int N = 100100; 
int n; 
vector<ll> perfs, ans;  
bool vis[N]; 
 
 
// matters only to 2e5
// n -1 + n -1 = 2 * n - 2
 
 
 
void solve()
{
 cin >> n, n --; 
 ans.resize(n + 10); 
 for(int i=0 ; i<=  n; i++) vis[i] = 0; 
 
 
 for(int i= n ; i >= 0  ; i--)
 { 
  bool answered = 0; 
  
  for(auto it : perfs)
  {
   if(it >= i && ((it - i) <= n) && !vis[it - i])
   {
    vis[it - i] = 1; 
    ans[i] = it - i; 
    answered = 1; 
    break;
   }
  }
 
  if(!answered)
   return void(cout << "-1\n");
 }
 
 for(int i=0 ; i<=n; i++)
  cout << ans[i] << ' '; 
 cout << '\n'; 
}
 
 
int main()
{
 for(ll i = 0 ; i <= 1e5 ; i++)
 {
  if(i * i > 2e5)  break;
  perfs.push_back(i * i); 
 }
 
 reverse(all(perfs));
 
 test 
  solve(); 
}
 
 