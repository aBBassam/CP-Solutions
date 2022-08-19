// Problem: E. Mirror Grid
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/E
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
 
const int N = 110;
ll n; 
string a[N], b[N], org[N]; 
 
 
 
void solve( )
{
 cin >> n; 
 for(int i=0;i<n;i++)
  cin >> a[i], org[i] = b[i] = a[i] ;
 
 ll ans = 0; 
 
 
 for(int i=0 ; i< n; i++)
  for(int j=0 ; j < n; j++)
  {
   int cnt = (a[i][j] - '0') + (a[n - 1 - j][i] - '0') + (a[j][n - 1 - i] - '0') +( a[n - 1 - i][n - 1 - j] - '0');   
   
   ans += min(cnt, abs(4 - cnt)); 
  }
 
 cout << ans / 4 << '\n'; 
}
 
 
int main()
{
    test
  solve();
}