// Problem: B1. Tokitsukaze and Good 01-String (easy version)
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/B1
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
ll n; 
string s; 
 
 
 
 
int main()
{
    test
 {
  cin >> n >> s; 
  s = "$" + s; 
  
  
  bool nn = 0; 
  ll ans = 0; 
  
  for(int i=1 ; i<=n ; i++)
  {
   char c = s[i]; 
   int cnt = 0; 
   
   int j = i;
   while(j <= n && s[j] == c)
    cnt ++, j ++; 
   
   i = j; 
   
   if(cnt & 1)
   {
    if(i > n)
    {
     nn = 1; 
     break;
    } 
    
    ans ++; 
   } 
   else i --;
  }
  
  
  
  if(nn) cout << n; 
  else cout << ans; 
  cout << '\n'; 
 }
}
 
 
 