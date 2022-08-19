// Problem: E. Breaking the Wall
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/E
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
 
 
 
ll sls(ll f, ll s)
{
 if(f < s) swap(f, s); 
 return min(max(f, s), (f - s + 1) / 2 + s); 
}
 
 
ll sl(ll f, ll s)
{
 if(f < s) swap(f, s); 
 if(s * 2 <= f) return (f + 1) / 2; 
 
 ll req = f - s; 
 f -= 2 * req; 
 s -= req; 
 if(s < 0) return req; 
 ll ans = req; 
 ans += (s + s + 2) / 3; 
 return ans;
}
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ; i<=n;  i++) cin >> a[i]; 
 
 
 ll ans = 1e18; 
 for(int i=1 ; i<=n;  i++)
 {
  if(i + 2 <= n)
   ans = min(ans, sls(a[i], a[i + 2])); 
  
  if(i + 1 <=n)
   ans = min(ans, sl(a[i], a[i + 1]));
 }
 
 sort(a + 1, a + n + 1); 
 
 ll ans1 = (a[1] / 2 + (a[1] % 2 != 0)) + (a[2] / 2 + (a[2] % 2 != 0));
 
 cout << min(ans, ans1) << '\n';
}
 
int main()
{
    go; 
  solve();
}
 
 
 