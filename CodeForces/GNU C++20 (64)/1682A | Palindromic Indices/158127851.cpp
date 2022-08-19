// Problem: A. Palindromic Indices
// Contest: Codeforces - Codeforces Round #793 (Div. 2)
// URL: https://codeforces.com/contest/1682/problem/A
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
 
int n; 
string s; 
 
 
void solve()
{
 
 cin >> n >> s; 
 
 int ind = n/ 2;  
 int ind2 = ind; 
 
 int ans = 0; 
 while(ind2 < n && s[ind] == s[ind2])
  ans ++, ind2 ++; 
  
 ans *= 2;
 if(ans && (n&1)) ans --;
  
  
 cout << ans << '\n';
}
 
int main()
{
    test
  solve();
}
 
 
 