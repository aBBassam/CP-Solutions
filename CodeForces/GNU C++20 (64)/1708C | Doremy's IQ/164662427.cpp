// Problem: C. Doremy's IQ
// Contest: Codeforces - Codeforces Round #808 (Div. 2)
// URL: https://codeforces.com/contest/1708/problem/C
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
 
const int N = 200100; 
ll n, iq, a[N], ans[N]; 
 
 
 
void solve( )
{
 cin >> n >> iq; 
 ll theIq = 0; 
 
 for(int i=1 ;i <=n;i++) cin>> a[i], ans[i] = 0; 
 
 reverse(a + 1,  a + n + 1); 
 
 for(int i=1 ;i <=n; i++)
  if(theIq >= a[i]) ans[i] = 1; 
  else if(iq) iq -- , theIq ++, ans[i] =1;
 
 for(int i = n ; i> 0 ;i --) cout << ans[i];
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 