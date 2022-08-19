// Problem: A. NIT orz!
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/0
// Memory Limit: 512 MB
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
 
 
const int N = 20010; 
ll n, a[N], z;
 
 
void solve( )
{
 cin >> n >> z; 
 for(int i=1 ; i<=n; i++)
  cin >> a[i]; 
  
 sort(a + 1, a + n + 1); 
 
 ll ans = 0; 
 
 for(int i=1 ; i<=n; i++)
  ans = max(ans, a[i] | z);
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 