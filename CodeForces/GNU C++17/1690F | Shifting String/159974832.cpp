// Problem: F. Shifting String
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
 
ll gcd(ll a , ll b)
{
   return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a , ll b)
{
   return (a*b)/gcd(a, b);
}
 
 
const int N = 210; 
ll n, id, vis[N], a[N]; 
vector<ll> v[N], gcds[N]; 
string s; 
 
 
void solve( )
{
 cin >> n >> s; 
 for(int i=1 ; i<=n;i++) cin >> a[i]; 
 
 id = 1; 
 for(int i=0 ; i< N; i++) v[i].clear(), gcds[i].clear(), vis[i] = 0; 
 s = "*" + s; 
 
 
 for(int i=1 ; i<=n; i++) if(!vis[i])
 {
  int node = i; 
  
  while(!vis[node])
   v[id].push_back(node), vis[node] = 1, node = a[node];
   
  id ++;  
 }
 
 for(int i=1 ; i<id ; i++)
 {
  int n = v[i].size(); 
  for(int st=1 ; st<n ; st++)
  {
   vector<int> vv; 
   int ind = st; 
   
   for(int times=0 ; times < n ; times++)
   {
    vv.push_back(v[i][ind]); 
    ind = (ind + 1) % n; 
   }
 
   
   int same = 1;
   for(int j=0 ; j<n; j++)
    same &= s[v[i][j]] == s[vv[j]];
   if(same) gcds[i].push_back(st); 
  }
  
  gcds[i].push_back(n);
 }
 
 ll mx = 0; 
 for(int i=1 ; i<id ; i++)
  mx = max(mx, (ll)gcds[i].size()); 
  
 
 
 ll finalAns = 1e18;
 for(ll mn = 1 ; mn <= mx; mn++)
 { 
  ll lccm = 1; 
  
  for(ll i=1 ; i < id ; i++)
  {
   ll gccd = gcds[i][0]; 
   int n = gcds[i].size(); 
   
   for(int j=0 ; j<n ; j++)
   { 
    if(gcds[i][j] > mn) break;
    gccd = gcd(gccd, gcds[i][j]); 
   }
   
   lccm = lcm(lccm, gccd); 
  }
  
  finalAns = min(finalAns, lccm); 
 }
 
 
 
 cout << finalAns << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 