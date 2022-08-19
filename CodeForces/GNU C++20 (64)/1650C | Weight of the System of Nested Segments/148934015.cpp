#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll n, m, a, b; 
set<pair<ll, pair<ll, int>>> st; 
set<pair<ll, int>> take; 
 
 
void solve()
{
 cin >> n >> m; 
 st.clear(), take.clear(); 
 
 for(int i=0 ; i<m; i++)
  cin >> a >> b, 
  st.insert({b, {a, i + 1}}); 
 
 
 ll ans = 0; 
 for(auto it : st)
 {
  if((ll)take.size() == n * 2) break;
  
  take.insert({it.S.F, it.S.S}); 
  ans += it.F;  
 }
 
 cout << ans << '\n'; 
 
 while(take.size())
 {
  cout << take.begin()->S << ' ' << (--take.end())->S << '\n'; 
  take.erase(take.begin()), take.erase(--take.end());
 }
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 