// Problem: D. Maximum Product Strikes Back
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/D
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
ll n, a[N], pro[N];
int s, e; 
map<int, int> val; 
 
int solve(int st, int en)
{
 val[1] = val[-1] = 0; 
 int tw = 0; 
 int sign = 1; 
 
 for(int i=st ; i<=en ; i++)
 {
  if(a[i] < 0) sign = !sign; 
  if(abs(a[i]) == 2) tw ++ ; 
  val[sign] = tw; 
 }
 
 tw = 0; 
 int ind = -1; 
 int mx = -1; 
 sign = 1; 
 
 for(int i=st ; i<=en ; i++)
 {
  if(val[sign] - tw > mx)
   mx = val[sign] - tw, ind = i; 
  
  if(a[i] < 0) sign = !sign; 
  if(abs(a[i]) == 2) tw ++ ; 
 }
 
 if(ind == -1) return -1; 
 
 // cout << st << ' ' << en << ' ' << ind << ' ' << mx << endl;
 
 
 s = ind - 1; 
 tw = 0; 
 sign = 1; 
 for(int i=ind ; i<=en ; i++)
 {
  if(abs(a[i]) == 2) tw ++ ; 
  if(a[i] < 0) sign = !sign; 
  
  if(sign == 1 && tw == mx)
  {
   e = n - i; 
   break;
  }
 }
 
 return mx; 
}
 
 
 
 
int main()
{
    test
 {
  cin >> n; 
  for(int i=1 ;i<= n;i++) cin >> a[i]; 
  
  int ans = -100;
  int fr = n, sc = 0; 
   
  for(int i=1 ; i<=n ;i++)
  {
   while(i <= n && !a[i]) i ++; 
   if(i > n) break; 
   
   int st = i; 
   while(i + 1 <= n && a[i + 1]) i ++ ; 
   
   int sol = solve(st, i);
   //cout << st << ' ' << i << endl;
   
   if(sol >= ans)
    ans = sol, fr = s, sc = e; 
  }
  
  if(ans <= 0) cout << n << ' ' << 0 << '\n';
  else cout << fr << ' ' << sc << '\n'; 
 }
}