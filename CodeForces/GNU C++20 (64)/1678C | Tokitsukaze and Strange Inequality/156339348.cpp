// Problem: C. Tokitsukaze and Strange Inequality
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
 
const int N = 5010; 
int n, a[N], seg[4 * N]; 
ll ans; 
 
 
void update(int p , int s , int e , int i , int v)
{
    if(s == e) 
    {
        seg[p] = v; 
        return;
    }
    if(i <= (s+e)/2) update(2*p,s,(s+e)/2,i,v);
    else update(2*p+1,(s+e)/2+1,e,i,v);
    seg[p] = seg[2*p] + seg[2*p+1];
}
int gt(int p , int s , int e , int a , int  b)
{
    if(s >= a && e <= b) return seg[p];
    if(s>b || e<a) return 0; 
    return gt(2*p,s,(s+e)/2,a,b) + gt(2*p+1,(s+e)/2+1,e,a,b);
}
 
 
 
void solve()
{
 ans = 0; 
 cin >> n; 
 for(int i=1 ;i<= n ;i++) cin >> a[i]; 
 for(int i=0 ; i<4*n ; i++) seg[i] = 0; 
 
 for(int i=1 ; i<=n; i++)
 {
  ll fr = 0; 
  
  for(int j=i+1 ; j<=n ;j++)
   if(a[j] < a[i]) fr ++; 
   
  for(int j=i+1 ; j<=n ; j++)
  {
   if(a[j] < a[i]) fr--; 
   
   ll sc = gt(1, 1, n, 1, a[j] -1); 
   ans += fr * sc;
  }
  update(1, 1, n, a[i], 1);
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}