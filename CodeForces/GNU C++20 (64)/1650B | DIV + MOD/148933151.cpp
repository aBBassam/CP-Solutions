#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll l, r, a; 
 
// codeforces was down for like 20 min
 
void solve( )
{
 cin >> l >> r >> a;
 
 ll ans = 0, x = r - r%a - 1; 
 
 if(x >= l)
  ans = x/a + x%a; 
  
 ans = max(ans, r/a + r%a);
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 