// Problem: B. Robots
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1680/problem/B
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
 
 
 
int n, m; 
string s[10]; 
 
 
void solve()
{
 cin >> n >> m; 
 for(int i=1 ; i<=n; i++) cin >> s[i], s[i] = "*" + s[i];  
 
 
 for(int i=1 ; i<=n; i++)
  for(int j=1 ; j<=m ; j++) if(s[i][j] == 'R')
  {
   int ind = j; 
   
   for(int k=i +1 ; k<=n ;k ++)
    for(int j=1 ; j<=m; j++) 
     if(s[k][j] == 'R' && j < ind)
      return void(cout << "NO\n"); 
      
   return void(cout << "YES\n"); 
  }
}
 
 
int main()
{
    test
  solve();
}
 
 
 