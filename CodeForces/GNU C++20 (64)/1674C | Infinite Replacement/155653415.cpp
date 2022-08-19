// Problem: C. Infinite Replacement
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/C
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
 
string s, t; 
 
void solve()
{
 cin >> s >> t; 
 
 bool hasA = 0; 
 for(char c : t)
  hasA |= (c == 'a');
 
 if(hasA && t.length() > 1) return void(cout << "-1\n"); 
 
 if(hasA) cout << 1; 
 else if((s.length() == t.length()) && (s.length() == 1)) // both equal 1 
 {
  cout << 1 + (s != t); 
 }
 else if((s.length() > 1 )&& (t.length() > 1)) // both more than one and second don't have a'
 {
  ll k = s.length(); 
  cout << (1ll << k); 
 } 
 else if(s.length() == 1) // second more than 1
 {
  cout << 2; 
 }
 else 
 {
  ll k = s.length(); 
  cout << (1ll << k); 
 }
 
 
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 