// Problem: B. Promo
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/B
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
ll n, q, a[N], pre[N]; 
 
 
void solve( )
{
 cin >> n >> q; 
 for(int i=1 ;i <=n; i++) cin >> a[i]; 
 sort(a + 1, a + n + 1); 
 reverse(a + 1, a + n  +1); 
 
 
 
 for(int i=1 ;i <=n; i++) pre[i] = pre[i - 1] + a[i]; 
 
 while(q--)
 {
  int x, y; cin >> x >> y; 
  cout << pre[x] - pre[x - y] << '\n';
 }
}
 
 
int main()
{
 go;
    //test
  solve();
}
 
 
 