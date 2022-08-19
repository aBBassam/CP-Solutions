// Problem: C. Get an Even String
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/C
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
int n;
string s; 
bool exi[50]; 
 
int main()
{
 test
 {
  cin >> s, n = s.length(), s = '&' + s; 
  for(int i=0 ; i<=40; i++) exi[i] = 0; 
  
  int tkn = 0; 
  
  for(int i=1 ; i<=n ;i++)
   if(exi[s[i] - 'a']) memset(exi, 0, sizeof exi), tkn += 2; 
   else exi[s[i] - 'a'] = 1;
   
  cout << n - tkn << '\n';
 }
}