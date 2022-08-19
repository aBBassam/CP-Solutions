// Problem: E. 2-Letter Strings
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/E
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
 
 
const int N = 100100; 
int n; 
string s[N]; 
map<string, int> rep; 
map<char, int> frLet, scLet; 
 
void solve()
{
 rep.clear(), frLet.clear(), scLet.clear(); 
 
 cin >> n; 
 for(int i=1 ; i<=n ;i++)
  cin >> s[i], 
  rep[s[i]] ++, 
  frLet[s[i][0]] ++, 
  scLet[s[i][1]] ++; 
 
 ll ans = 0; 
 for(int i=1 ; i<=n; i++)
 {
  ll fr = frLet[s[i][0]] - rep[s[i]]; 
  ll sc = scLet[s[i][1]] - rep[s[i]]; 
  ans += fr + sc; 
 }
 
 cout << ans / 2<< '\n';
}
 
 
int main()
{
    test
  solve();
}