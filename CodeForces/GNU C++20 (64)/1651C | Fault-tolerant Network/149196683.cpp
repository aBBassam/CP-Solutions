// Problem: C. Fault-tolerant Network
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/C
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
 
 
ll n, a[200100], b[200100]; 
set<ll> sa, sb; 
 
 
void solve( )
{
 cin >> n; 
 sa.clear(), sb.clear(); 
 for(int i=0 ; i<n ;i++) cin >> a[i], sa.insert(a[i]); 
 for(int i=0 ; i<n ;i++) cin >> b[i], sb.insert(b[i]);
 
 
 ll ans1, ans2, ans3, ans4; 
 ans1 = ans2 = ans3 = ans4 = 1e15; 
 
 auto it = sb.upper_bound(a[0]); 
 if(it != sb.end()) ans1 = *it - a[0]; 
 if(it != sb.begin())
 {
  it -- ; 
  ans1 = min(ans1, a[0] - *it); 
 }
 it = sb.upper_bound(a[n-1]); 
 if(it != sb.end()) ans2 = *it - a[n-1]; 
 if(it != sb.begin())
 {
  it -- ; 
  ans2 = min(ans2, a[n-1] - *it); 
 }
 
 
 
 it = sa.upper_bound(b[0]); 
 if(it != sa.end()) ans3 = *it - b[0]; 
 if(it != sa.begin())
 {
  it -- ; 
  ans3 = min(ans3, b[0] - *it); 
 }
 it = sa.upper_bound(b[n-1]); 
 if(it != sa.end()) ans4 = *it - b[n-1]; 
 if(it != sa.begin())
 {
  it -- ; 
  ans4 = min(ans4, b[n-1] - *it); 
 }
 
 ll answer1 = ans1 + ans2 + ans3 + ans4; 
 ll answer2 = answer1; 
  
 answer1 -= max(0ll,(ans1 + ans3) - abs(a[0] - b[0]));
 answer1 -= max(0ll,(ans2 + ans4) - abs(a[n-1] - b[n-1]));
  
 answer2 -= max(0ll,(ans1 + ans4) - abs(a[0] - b[n-1]));
 answer2 -= max(0ll,(ans2 + ans3) - abs(a[n-1] - b[0]));
 
 cout << min(answer1, answer2) << '\n';
}
 
int main()
{
    test
  solve();
}
 
 
 