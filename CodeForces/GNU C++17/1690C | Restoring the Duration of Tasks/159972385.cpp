// Problem: C. Restoring the Duration of Tasks
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/C
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
ll n, a[N], b[N]; 
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i];
 for(int i=1 ; i<=n; i++) cin >> b[i];
 
 for(int i=1 ;i<=n; i++)
 {
  ll prev = a[i]; 
  ll bef = i > 1 ? b[i - 1] : prev; 
  
  ll mx = max(prev, bef); 
  
  cout << b[i] - mx << ' '; 
 }
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 