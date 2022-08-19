#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 100100; 
ll  n, m, a[N], cnt[N]; 
vector<pair<int, int>> v; 
ll ans = 0; 
 
 
void solve( )
{
 cin >> n >> m; 
 for(int i=1 ; i<=n; i++) cin >> a[i], cnt[i] = 0; 
 for(int i=1, a, b ; i<=m ; i++)
  cin >> a >> b, 
  cnt[a] ++,  cnt[b] ++, 
  v.push_back({a, b}); 
 
 ans = 0; 
 if(m&1)
 {
  ans = 1e18;
  for(int i=0 ; i < m ; i++)
  {
   if(cnt[v[i].F] & 1) ans = min(ans, a[v[i].F]); 
   if(cnt[v[i].S] & 1) ans = min(ans, a[v[i].S]); 
   ans = min(ans, a[v[i].F] + a[v[i].S]);
  }
 }
 
 v.clear();
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 