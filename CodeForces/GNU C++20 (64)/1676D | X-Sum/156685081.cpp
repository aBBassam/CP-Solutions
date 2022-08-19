// Problem: D. X-Sum
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/D
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
 
 
const int N = 310; 
ll n, m, a[N][N], pre1[N][N], pre2[N][N], pre3[N][N], pre4[N][N]; 
 
 
ll solve1(int i, int j)
{
 if(min(i, j) < 1 || i > n || j > m) return 0; 
 
 if(pre1[i][j]) return pre1[i][j]; 
 return pre1[i][j] = a[i][j] + solve1(i-1, j + 1); 
}
 
ll solve2(int i, int j)
{
 if(min(i, j) < 1 || i > n || j > m) return 0; 
 
 if(pre2[i][j]) return pre2[i][j]; 
 return pre2[i][j] = a[i][j] + solve2(i -1, j - 1);
}
ll solve3(int i, int j)
{
 if(min(i, j) < 1 || i > n || j > m) return 0; 
 
 if(pre3[i][j]) return pre3[i][j]; 
 return pre3[i][j] = a[i][j] + solve3(i + 1, j - 1) ;
}
 
ll solve4(int i, int j)
{
 if(min(i, j) < 1 || i > n || j > m) return 0; 
 
 if(pre4[i][j]) return pre4[i][j]; 
 return pre4[i][j] = a[i][j] +solve4(i + 1, j + 1);
}
 
void solve()
{
 cin >> n >> m;
 for(int i=1 ;i  <=n; i++) 
  for(int j=1 ; j<=m ;j++) 
   cin >> a[i][j],  pre1[i][j] = pre2[i][j] = pre3[i][j] = pre4[i][j] = 0;
 
 ll ans = 0;  
 for(int i=1 ;i <=n ; i++)
  for(int j=1 ; j<=m ; j++)
   solve1(i, j), 
   solve2(i, j), 
   solve3(i, j), 
   solve4(i, j); 
 
 for(int i=1 ;i <=n ; i++)
  for(int j=1 ; j<=m ; j++)
   ans = max(ans, pre1[i][j] + pre2[i][j] +pre3[i][j] +pre4[i][j] - 3 * a[i][j]);  
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 