// Problem: A. Subtle Substring Subtraction
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/A
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
 cin >> s; 
 n  = s.length(); 
 s = '&' + s; 
 
 if(n == 1)
 {
  cout << "Bob "; 
  cout << (s[1] - 'a') +1; 
  cout << '\n';
  return ;
 }
 
 cout << "Alice ";
 if(n % 2 == 1)
 { 
  ll sc1 = 0, sc2 = 0; 
  for(int i=1 ; i<n ; i++)
   sc1 += (s[i] - 'a') +1; 
   
  for(int i=2 ; i<=n ; i++)
   sc2+= (s[i] - 'a') +1; 
  
  if(sc1 > sc2)
  {
   ll b = (s[n] - 'a') +1; 
   cout << sc1 - b << '\n'; 
  }
   else
   {
    ll b = (s[1] - 'a') +1; 
    cout << sc2 - b << '\n';
   }
 }
 else 
 {
  ll sc = 0; 
  for(int i=1 ; i<=n ; i++)
   sc += (s[i] - 'a') +1; 
  
  cout << sc << '\n';
 }
}
 
 
int main()
{ 
    test
  solve();
}
 
 
 