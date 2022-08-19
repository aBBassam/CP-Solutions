// Problem: A. Little Pony and Expected Maximum
// Contest: Codeforces - Codeforces Round #259 (Div. 1)
// URL: https://codeforces.com/problemset/problem/453/A
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
 
double n, m; 
 
double fstPO(double x, int y) {
 
  double res = 1;
  for (int i = 0; (1<< i) <= y; i++, x = x * x)
    if (y & 1 << i)
      res = res * x;
      
  return res;
}
 
int main()
{
    cin >> m >> n; 
    double ans = 0; 
    for(double i = 1 ; i <= m; i++)
     ans += i * (fstPO(i / m, n) - fstPO((i - 1) / m, n)); 
    
    cout << fixed << setprecision(15) << ans;
}