// Problem: G. Sorting Pancakes
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/G
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
 
 
 
const int N = 265; 
int n, m, a[N], dp[N][N][2 * N]; 
 
int solve(int i, int last, int move)
{
 if(i > n) return !move ? 0 : 1e5; 
 else if(abs(move) > m) return 1e5; 
 
 int &ret = dp[i][last][move + N]; 
 if(ret + 1) return ret; 
 ret = abs(move) + solve(i + 1, last, move + a[i] - last);
 
 if(last)
  ret = min(ret, solve(i, last - 1, move)); 
 
 return ret; 
}
 
 
 
int main()
{
 cin >> n >> m; 
 for(int i=1 ; i<=n ;i++) cin >> a[i]; 
 
 memset(dp, -1, sizeof dp);
 cout << solve(1, m, 0); 
}