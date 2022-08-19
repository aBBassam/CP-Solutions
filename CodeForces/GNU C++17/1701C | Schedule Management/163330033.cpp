// Problem: C. Schedule Management
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/C
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
 
 
 
const int M = 200100; 
ll n, m, workerHas[M], ex; 
 
bool chk(ll hours)
{
 ll jobs = m; 
 
 for(int i=1 ; i<=n ; i++)
 {
  if(hours >= workerHas[i])
   jobs -= (hours - workerHas[i]) / 2, 
   jobs -= workerHas[i];
  else 
   jobs -= hours;
 }
 
 
 return jobs <= 0;  
}
 
 
 
void solve( )
{
 cin >> n >> m; 
 for(int i=1 ; i<=m ; i++) workerHas[i] = 0; 
 for(int i=1, w ; i<=m; i++)
  cin >> w, 
  workerHas[w] ++; 
 
 // each perfect worker, how many perfect to take : 
 ll st = 0, en = 2 * M, ans = 1e18; 
 while(st <= en)
 {
  ll mid = (st + en) / 2; 
  if(chk(mid)) ans = mid, en = mid - 1; 
  else st = mid + 1; 
 }
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}