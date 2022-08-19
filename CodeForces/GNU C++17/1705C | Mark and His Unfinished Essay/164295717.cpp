// Problem: C. Mark and His Unfinished Essay
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/C
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
 
 
const int N = 200100, C  = 42, Q = 10000; 
ll n, c, q; 
set<pair<ll, pair<ll, ll>>> st; 
string s; 
 
 
char solve(ll ind)
{
 if(ind <= n) return s[ind]; 
 
 auto it = *st.lower_bound({ind,{-1, -1}});
 
 ll fr = it.S.F; 
 ll sc = it.S.S; 
 ll beg = it.F - (sc - fr); 
 
 ll nw = fr + (ind - beg);
 
 
 return solve(nw);
}
 
void slv()
{
 st.clear();
 cin >> n >> c >> q >> s; 
 n = s.length(); 
 s = "*" + s; 
 
 ll lst = n;
 st.insert({lst, {1, n}});
 
 for(ll i=0 ; i<c ; i++)
 {
  ll a, b; cin >> a >> b; 
  lst += b - a + 1;
  
  st.insert({lst ,{a, b}});
 }
 
 
 while(q --)
 { 
  ll ind; cin >> ind;
  cout << solve(ind) << '\n';
 }
}
 
 
int main()
{
    test
  slv();
}
 
 
 