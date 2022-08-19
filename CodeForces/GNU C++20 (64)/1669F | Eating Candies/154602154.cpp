// Problem: F. Eating Candies
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/F
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
int n, a[N]; 
 
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ;i<=n ;i++) cin >> a[i]; 
 
 ll ans = 0; 
 ll alice = 0, bob = 0; 
 
 int s = 1, e = n; 
 while(s <= e)
 {
  if(alice <= bob) alice += a[s ++]; 
  else bob += a[e --];
  
  if(alice == bob)
  {
   int i = s - 1; 
   int j = n - e; 
   ans = i + j;  
  }
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}