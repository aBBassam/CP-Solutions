// Problem: B. Making Towers
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int N= 100100; 
ll n; 
vector<int> v [N]; 
 
void solve()
{
 cin >> n;
 for(int i=1 ;i <=n; i++) v[i].clear(); 
 for(int i=1 ;i <=n; i++)
 {
  int k; cin >> k;
  v[k].push_back(i); 
 }
 
 for(int i=1  ;i <=n; i++)
  if(v[i].empty()) cout << "0 "; 
  else 
  {
   int ans = 1; 
   int m = v[i].size(); 
   
   for(int j=1 ;j<m ;j++)
   {
    if(abs(v[i][j] - v[i][j - 1]) % 2 == 1) ans ++;
   }
   
   cout << ans << ' '; 
  }
 
 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 