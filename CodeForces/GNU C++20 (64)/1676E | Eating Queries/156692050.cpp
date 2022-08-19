// Problem: E. Eating Queries
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
 
 
const int N = 200000; 
ll n, q, a[N]; 
vector<ll> v; 
map<ll, int> req; 
 
void solve( )
{
 v.clear();
 req.clear(); 
 
 cin >> n >> q; 
 for(int i=1 ; i<=n; i++)
  cin >> a[i]; 
 
 sort(a + 1, a + n + 1); 
 reverse(a + 1, a + n + 1);
 
 ll sm = 0; 
 
 for(int i=1 ;i<=n; i++)
 {
  sm += a[i],
  v.push_back(sm); 
  if(!req[sm])
   req[sm] = i; 
 }
 
 
 while(q--)
 {
  ll val; cin >> val; 
  auto it = lower_bound(all(v), val);
  if(it == v.end()) cout << "-1\n"; 
  else cout << req[*it] << '\n';
 }
}
 
 
int main()
{
    test
  solve();
}