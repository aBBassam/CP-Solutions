// Problem: E. Binary Deque
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/E
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
 
const int N = 200100; 
int n, a[N], pre[N];  
ll reqSm, sm; 
 
 
 
void solve( )
{
 cin >> n >> reqSm; 
 sm = 0; 
 for(int i=1 ;i <=n; i++)
  cin >> a[i], sm += a[i]; 
 
 if(sm < reqSm)
  return void(cout << "-1\n"); 
 
 int ans = 0; 
 for(int i=1 ;i <=n;i++)
  pre[i] = pre[i - 1] + a[i]; 
 
 int rem = sm - reqSm; 
 
 
 for(int i=1 ;i <=n; i++)
 {
  int st = 0, en = n - i + 1, anss = 1e9; 
 
  while(st <= en)
  {
   int mid = (st + en) / 2; 
   int ones = (pre[i + mid - 1] - pre[i  -  1]); 
    
   if(ones <= reqSm) anss = mid, st = mid + 1; 
   else en = mid  - 1; 
  }
  
  ans = max(ans, anss);
 }
 cout << n - ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 