// Problem: B. Madoka and the Elegant Gift
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.com/contest/1647/problem/B
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
 
 
int n, m; 
string a[110]; 
string s; 
 
void solve( )
{
 cin >> n >> m; 
 for(int i=1 ; i<=n ; i++)
 {
  cin >> s; 
  s = '%' + s; 
  a[i] = s; 
 }
 
 for(int i=1 ; i<=n ;i++)
  for(int j=1 ; j<=m ; j++)
 {
  if(i + 1 > n || j + 1 > m) continue; 
  
  int cnt = (a[i][j] == '1') + (a[i+1][j] == '1') + (a[i][j+1] == '1') + (a[i+1][j+1] == '1'); 
  if(cnt == 3)
   return void(cout << "NO\n");
 }
 
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 