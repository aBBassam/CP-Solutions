// Problem: D. Color with Occurrences
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/D
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
 
const int N = 15; 
ll dp[110], n, len; 
string t, s[N];
 
 
ll solve(int stepOn)
{
 if(stepOn == len) return 0; 
 ll &ret = dp[stepOn]; 
 if(ret + 1) return ret; 
 ret = 1e10; 
 
 for(int i=0 ; i < n ; i++)
 {
  int ln = s[i].length(); 
  
  if((stepOn + ln - 1) < len)
  {
   int j = stepOn; 
   int ys  = 1; 
   
   for(int k =0 ; k < ln ; k++)
   {
    if(t[j] != s[i][k]) ys = 0; 
    j ++; 
   }
   
   if(ys)
   { 
    for(int take_=1 ; take_ <= ln ; take_++)
     ret = min(ret, 1 + solve(stepOn + take_)); 
   }
  }
 }
  
 return ret; 
}
 
 
void goo(int stepOn)
{
 if(stepOn == len) return ; 
 ll theAns = solve(stepOn); 
 
 
 for(int i=0 ; i < n ; i++)
 {
  int ln = s[i].length(); 
  
  if((stepOn + ln - 1) < len)
  {
   int j = stepOn; 
   int ys  = 1; 
   
   for(int k =0 ; k < ln ; k++)
   {
    if(t[j] != s[i][k]) ys = 0; 
    j ++; 
   }
   
   if(ys)
   { 
    for(int take_=1 ; take_ <= ln ; take_++)
     if(theAns == 1 + solve(stepOn + take_))
     {
      cout << i + 1<< ' ' << stepOn + 1 << '\n';
      goo(stepOn + take_); 
      return; 
     }
   }
  }
 }
}
 
 
void solve()
{
 cin >> t; 
 len = t.length(); 
 
 cin >> n; 
 for(int i=0 ; i <n; i++) cin >> s[i]; 
 for(int i=0 ; i <= len ; i++) dp[i] = -1; 
 
 if(solve(0) >= 1e10) cout << "-1\n"; 
 else cout << solve(0) << '\n', goo(0);
}
 
 
int main()
{
 test 
  solve(); 
}
 
 