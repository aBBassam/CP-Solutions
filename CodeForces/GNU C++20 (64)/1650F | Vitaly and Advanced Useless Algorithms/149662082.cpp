#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
 
const int N = 100100;
ll n, m, e, t, p, dp[N][110], deadline[N], ind[N]; 
vector<pair<ll, pair<ll, ll>>> v;
vector<pair<pll, pll>> ordV;  
set<ll> s; 
vector<ll> ans; 
 
 
ll solve(ll i, ll perc)
{ 
 if(i == m) return 0; 
 
 ll &ret = dp[i][perc]; 
 if(ret + 1) return ret; 
 
 if(i + 1 < m && v[i].F == v[i+1].F)
 { 
  ret = min(v[i].S.F + solve(i+1, min(100ll, perc + v[i].S.S)), solve(i + 1, min(100ll,perc)));
 }
 else 
 {
  if(perc + v[i].S.S < 100) ret = 1e15; 
  else if(perc == 100) ret = solve(i + 1, 0); 
  else ret = v[i].S.F + solve(i + 1, 0); 
 }
 
 return ret; 
}
 
 
 
void path(ll i, ll perc)
{ 
 if(i == m) return; 
 
 if(i + 1 < m && v[i].F == v[i+1].F)
 { 
  if(solve(i, perc) == solve(i + 1, min(100ll,perc))) path(i + 1, perc); 
  else ans.push_back(i), path(i+1, min(100ll, perc + v[i].S.S)); 
 }
 else
 {
  if(perc < 100) 
   ans.push_back(i);
  path(i+1, 0);
 }
}
 
 
int main()
{
  test
  {
   s.clear(), v.clear(), ordV.clear(), ans.clear();
   cin >> n >> m; 
   for(int i=0 ; i<=m ; i++)
    for(int j=0 ; j<=100 ; j++)
     dp[i][j] = -1; 
   
   for(int i=1 ; i<=n ;i++) 
    cin >> deadline[i];
     
   for(int i=1 ; i<=m ;i++)
    cin >> e >> t >> p,
    v.push_back({e, {t, p}}), 
    ordV.push_back({{e, t}, {p, i}}),
    s.insert(e);
   
   if(s.size() < n)
   {
    cout << "-1\n"; 
    continue; 
   }
   
   sort(all(v)); 
   sort(all(ordV)); 
   for(int i=0 ; i<m ; i++)
    ind[i] = ordV[i].S.S;
 
   if(solve(0, 0) >= 1e15) cout << -1; 
   else 
   { 
    path(0, 0);
   
    // check reached solution : 
    ll tm = 0, wrong = 0; 
    for(int i=0 ; i<ans.size() ; i++)
    {
     tm += v[ans[i]].S.F;
     
     if(i == ans.size() - 1 || v[ans[i+1]].F != v[ans[i]].F)
      wrong |= tm > deadline[v[ans[i]].F]; 
    }
  
    if(wrong) cout << -1; 
    else 
    {
     cout << ans.size() << '\n'; 
     for(ll i : ans)
      cout << ind[i] << ' ';
    }
   }
 
   cout << '\n';
  }
}
 
 
 