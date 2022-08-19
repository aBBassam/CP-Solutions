// Problem: B. Card Trick
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/B
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
ll n, k, a[N], b[N]; 
 
 
void solve( )
{
 cin >> n ; 
 for(int i=1 ; i<=n; i++) cin >> a[i];
 
 
 ll sm = 0;
 
 cin >> k;  
 for(int i=1 ; i<=k; i++) cin >> b[i], sm += b[i]; 
 
 sm  %= n; 
 cout << a[sm + 1] << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 