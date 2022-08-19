#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
 
ll n, m; 
 
void solve()
{
 cin >> n >> m; 
 
 if(n == 1 && m == 1) cout << 0 << '\n';
 else if(n == m) cout << 2 * n - 2 << '\n'; 
 else if(min(n, m) == 1 && abs(n - m) > 1) cout << -1 << '\n';  
 else 
 {
  if(n < m) swap(n, m); 
  ll ans = 2 * m - 1; 
  n -= m + 1; 
  
  cout << ans + (n / 2) * 4 + (n % 2 == 1 ? 3 : 0) << '\n';
 }
}
 
 
int main()
{
    test
  solve();
}
 
 
 