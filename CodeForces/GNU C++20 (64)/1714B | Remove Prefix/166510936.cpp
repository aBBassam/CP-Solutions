// Problem: B. Remove Prefix
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/B
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
 
 
const int N = 200100; 
ll n, a[N]; 
vector<int> v[N]; ;
 
 
void solve()
{
 cin >> n; 
 
 for(int i=1 ;i <=n; i++) cin >> a[i], v[a[i]].push_back(i);
 
 int ans = 0; 
 for(int i=1 ;i <=n; i++) if(v[a[i]].size() > 1)
 {
  auto it = v[a[i]].end(); 
  it --, it --; 
  ans = max(ans, *it);
 }
 
 for(int i=1 ; i<=n; i++)  
  v[i].clear(); 
 cout << ans << '\n'; 
}
 
 
int main()
{
 test 
  solve(); 
}
 
 