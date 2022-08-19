// Problem: D. Permutation Restoration
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
 
const int N = 500100; 
int n, b[N]; 
vector<pair<pair<ll, ll>, ll>> v;
int ans[N];  
set<ll > stt; 
 
 
void solve()
{
 v.clear(); 
 
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> b[i]; 
 
 for(int i=1 ; i<=n; i++)
 {
  ll st = 1, en = n, ans;
  while(st <= en)
  {
   ll mid = (st + en) / 2; 
   
   if((i / mid) <= b[i]) ans = mid, en = mid - 1; 
   else st = mid + 1; 
  }
  
  ll fr = ans;
  
  st = fr, en = n; ans = n; 
  
  while(st <= en)
  {
   ll mid = (st + en) / 2; 
  
   if((i / mid) == b[i]) ans = mid, st = mid + 1; 
   else en = mid - 1; 
  }
 
  ll sc = ans; 
  
  stt.insert(i); 
  v.push_back({{sc, fr}, i}); 
 }
 
 sort(all(v)); 
 
 
 for(int i=0 ; i<n; i++)
 {
  auto it = stt.lower_bound(v[i].F.S);
  ans[v[i].S] = *it; 
  stt.erase(it);
 }
 
 for(int i=1 ;i<=n; i++) cout << ans[i] << ' ';
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}