// Problem: C. Where's the Bishop?
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/C
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
 
 
string s[10]; 
int n = 8; 
 
 
 
bool valid(int x, int y)
{
 return (max(x, y) <= n && min(x, y) > 0);
}
 
void solve( )
{
 for(int i=1 ; i<=8 ; i++)
  cin >> s[i], 
  s[i] = "*" + s[i]; 
 
 
 for(int i= 1 ;i <=n; i++)
  for(int j=1 ; j<=n ; j++)
   if(valid(i - 1, j - 1) && valid(i + 1, j + 1))
    if(s[i][j] == '#' && s[i+1][j + 1] == '#' &&  s[i+1][j-1] == '#' && s[i-1][j+1] == '#')
      cout << i << ' ' << j << '\n';
} 
 
 
int main()
{
    test
  solve();
}
 
 
 