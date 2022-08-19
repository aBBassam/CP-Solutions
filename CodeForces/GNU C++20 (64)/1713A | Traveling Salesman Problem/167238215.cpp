// Problem: A. Traveling Salesman Problem
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/0
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
set<ll> st[2]; 
 
void solve()
{
 ll n; cin >> n; 
 ll ans = 0 ;
 
 st[0].clear(), st[1].clear(); 
 
 
 for(int i=1 ;i <=n; i++)
 {
  int a, b; cin >> a >> b; 
  if(a == 0) st[0].insert(b); 
  else st[1].insert(a); 
 }
 
 for(int i=0 ;i < 2 ; i++)
 {
  if(st[i].size())
  {
   if(*st[i].begin() < 0) ans += 2 * abs(*st[i].begin()); 
   ll mx = *st[i].rbegin(); 
   if(mx > 0)
    ans += 2 * mx;
  }
 }
 
 cout << ans << '\n';
}
 
 
int main()
{
 test 
  solve(); 
}
 
 