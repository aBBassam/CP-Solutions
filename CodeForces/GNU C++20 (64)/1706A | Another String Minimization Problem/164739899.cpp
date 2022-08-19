// Problem: A. Another String Minimization Problem
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/0
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
 
 
const int N = 1010; 
int n, m, ans[N], a[N]; 
 
 
void solve()
{
 
 cin >> n >> m; 
 for(int i=1 ;i <=n; i++) cin >> a[i]; 
 sort(a + 1, a + n + 1);
 
 
 for(int i=1 ;i <=m; i++) ans[i] = 0; 
 
 
 for(int i=1 ;i <=n;i++)
 {
  int fr = a[i]; 
  int sc = m + 1 - a[i]; 
  
  if((fr >= 1 && fr <= m) && (sc >= 1 && sc <= m))
  {
   if(ans[min(fr, sc)]) ans[max(fr, sc)] = 1; 
   else ans[min(fr, sc)] = 1; 
  }
  else if(fr >= 1 && fr <= m) 
   ans[fr] = 1;
  else if(sc >= 1 && sc <= m)
   ans[sc] = 1;
 }
 
 
 for(int i=1 ; i<=m; i++)
  if(ans[i]) cout << 'A'; 
  else cout << 'B'; ;
 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 