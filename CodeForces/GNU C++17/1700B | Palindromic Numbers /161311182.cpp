// Problem: B. Palindromic Numbers
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/B
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
 
int n; 
string s, ans; 
 
 
 
void solve2()
{
 ans = ""; 
 
 int carry = 0; 
 for(int i=0 ; i<n; i++)
 {
  int dig = s[i] - '0'; 
  
  int sm = dig + carry;
  carry = 0; 
  
  int to1 = 11, to2 = 1; 
  if(i == 0 || i == n - 1)
   to1 = 13, to2 = 3; 
  
  if(sm <= to2)
   ans += to_string(to2 - sm); 
  else 
   carry = 1, ans += to_string(to1 - sm);
 }
 
 reverse(all(ans));
 cout << ans << '\n';
}
 
 
void solve()
{
 cin >> n >> s, ans = ""; 
 reverse(all(s)); 
 
 int carry = 0; 
 
 for(int i=0 ; i<n; i++)
 {
  int dig = s[i] - '0'; 
  
  int sm = dig + carry;
  carry = 0; 
  
  if(sm == 1 && i == n - 1)
  { 
   solve2(); 
   return; 
  }
  else if(sm == 0) ans += "1"; 
  else if(sm == 1) ans += "0";  
  else carry = 1, ans += to_string(11 - sm); 
 }
 reverse(all(ans));
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}