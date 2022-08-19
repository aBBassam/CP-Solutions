// Problem: G. Fall Down
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/G
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
 
 
const int N = 100; 
int n, m; 
char a[N][N];  
 
void solve()
{
 cin >> n >> m; 
 for(int i=1 ; i<=n; i++)
  for(int j=1 ; j<=m ;j++) 
   cin >> a[i][j]; 
   
 
 for(int j=1 ; j<=m ;j++)
 {
  int lst = n; 
  for(int i=n; i>0 ; i--)
  {
   if(a[i][j] == 'o') lst = i - 1; 
   else if(a[i][j] == '*')
   {
    a[i][j] = '.'; 
    a[lst][j] = '*'; 
    lst --; 
   }
  }
 }
 
 
 for(int i=1 ; i<=n; i++)
 {
  for(int j=1 ; j<=m ;j++) 
   cout << a[i][j]; 
  
  cout << '\n';
 }
}
 
 
int main()
{
    test
  solve();
}