#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 55, M = 20010; 
ll n, m, k, dp[N][M], a[N][M], vals[N][M], pre[N][M], seg[4 * M], lazy[4  * M]; 
 
 
 
 
void chk (int p , int s , int e)
{
    if(lazy[p])
    {
        seg[p] += lazy[p];
        if(s!=e) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }
}
void update(int p , int s , int e, int a , int b , int v)
{
    chk(p,s,e);
 
    if(s >= a && e <= b) 
    {
        seg[p] += v; 
        
        if(s!=e)
        {
            lazy[2*p] += v; 
            lazy[2*p+1] += v; 
        }
        return ; 
    }
 
    if(s>b || e<a)
        return ;
 
    update(2*p,s,(s+e)/2,a,b,v);
    update(2*p+1,(s+e)/2+1,e,a,b,v);
 
    seg[p] = max(seg[2*p] , seg[2*p+1]);
}
int gt(int p , int s , int e , int a , int  b)
{
    chk(p,s,e);
 
    if(s >= a && e <= b)
        return seg[p];
    
    if(s>b || e<a)
        return 0; 
    
    return max(gt(2*p,s,(s+e)/2,a,b) , gt(2*p+1,(s+e)/2+1,e,a,b));
}
 
int main()
{
 cin >> n >> m >> k;
 for(int i=1 ;i <=n ;i++)
  for(int j=1 ; j<=m ; j++)
   cin >> a[i][j], 
   pre[i][j] = a[i][j] + pre[i][j-1];
 
 
 for(int i=1 ; i<=n ;i++)
  for(int j=1 ; j + k - 1 <=m ; j++) 
   vals[i][j] = pre[i][j+k-1] - pre[i][j-1] + pre[i+1][j+k-1] - pre[i+1][j-1];
   
   
 for(int j=1 ; j + k - 1<=m ; j++)
  dp[1][j] = vals[1][j];
 
 for(int i=2 ; i<=n ; i++)
 {
  memset(seg, 0, sizeof seg); 
  memset(lazy, 0, sizeof lazy);
  
  for(int j=1 ; j + k - 1 <= m ; j++)
   update(1, 1, m, j, j, dp[i-1][j]);
   
   
  for(int j=1 ; j<=k ; j++)
   update(1, 1, m, 1, j, -a[i][j]);
   
 
  for(int j=1 ; j + k - 1 <= m ; j++)
  {
   dp[i][j] = gt(1, 1, m, 1, m) + vals[i][j];
  
   update(1, 1, m, j+1, j + k, -a[i][j + k]);
   update(1, 1, m, max(1ll, j - k + 1) , j, a[i][j]);
  }
 }
 
 
 ll ans = 0; 
 for(int i=1 ; i<=m ; i++) 
  ans = max(ans, dp[n][i]);
 cout << ans; 
}