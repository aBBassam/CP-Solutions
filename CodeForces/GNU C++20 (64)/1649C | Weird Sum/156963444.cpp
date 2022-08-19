// Problem: C. Weird Sum
// Contest: Codeforces - Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1649/problem/C
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
 
 
const int N = 100100; 
ll n, m, pre[N]; 
vector<ll> xs[N], ys[N]; 
 
 
 
 
int main()
{
 cin >> n >> m; 
 for(int i=1 ; i<=n ;i++)
  for(int j=1 ; j<=m ; j++)
  {
   int a; cin >> a; 
   xs[a].push_back(i); 
   ys[a].push_back(j);
  }
 
 ll ans = 0; 
 
 for(int i=1 ; i<N ; i++) if(xs[i].size() > 1)
 { 
  int n = xs[i].size(); 
  xs[i].push_back(0); 
  sort(all(xs[i])); 
 
  for(int j=1 ; j<= n; j++)
   pre[j] = pre[j - 1] + xs[i][j]; 
  
  
  for(int j=1 ; j< n; j++)
  {
   ll me = (n - j) * xs[i][j]; 
   ll sm = pre[n] - pre[j]; 
   ans += sm - me; 
  }
  
   n = ys[i].size(); 
  ys[i].push_back(0); 
  sort(all(ys[i])); 
  
  for(int j=1 ; j<= n; j++)
   pre[j] = pre[j - 1] + ys[i][j]; 
   
  for(int j=1 ; j< n; j++)
  {
   ll me = (n - j) * ys[i][j]; 
   ll sm = pre[n] - pre[j]; 
   ans += sm - me; 
  }
 }
 
 cout << ans; 
}