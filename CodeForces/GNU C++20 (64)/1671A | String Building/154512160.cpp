// Problem: A. String Building
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/0
// Memory Limit: 512 MB
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
 
 
 
string s; 
 
void solve( )
{
 cin >> s; 
 int n = s.length(); 
 
 for(int i=0 ; i<n; i++)
 {
  int cnt = 0;
  char c = s[i]; 
   
  while(i < n && s[i] == c) cnt ++, i++; 
  if(i != n) i --; 
  if(cnt == 1) return void(cout << "NO\n"); 
 }
 
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 