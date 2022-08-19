// Problem: C. Train and Queries
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/C
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
 
 
const int N = 200100; 
map<int, vector<int>> ind; 
int n, m; 
 
 
void solve( )
{
 ind.clear();
 cin >> n >> m;
 for(int i=1 ;i<=n;i++)
 {
  int a; cin >> a; 
  ind[a].push_back(i);
 }
 
 while(m --)
 {
  int a, b; cin >> a >> b; 
  if(ind.find(a) == ind.end() || ind.find(b) == ind.end()) cout << "NO\n"; 
  else 
  {
   int in = ind[a][0];
   if(lower_bound(all(ind[b]), in) != ind[b].end()) cout << "YES\n";  
   else cout << "NO\n";
  }
 }
}
 
 
int main()
{
    test
  solve();
}
 
 
 