// Problem: A. AvtoBus
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/A
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
 
 
ll n; 
 
 
void solve( )
{
 cin >> n;
 if((n&1) || (n < 4)) return void(cout << "-1\n"); 
 ll ans1 = 0, ans2 = 0; 
 
 ll fr = n / 4; 
 ll sx = 0; 
 
 n -= fr * 4;
 if(n) 
  sx ++, fr --; 
  
 ans2 = fr + sx; 
 
 ll k =  fr / 3; 
 fr -= k * 3; 
 sx += k * 2; 
 ans1 = sx + fr; 
 
 cout << ans1 << ' ' << ans2 << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 