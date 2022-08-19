#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
const int N = 40010, K = 55; 
int n, k, dp[N], seg[4 * N], lazy[4 * N], a[N], last[N], bef[N]; 
 
 
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
        if(s!=e) lazy[2*p] += v, lazy[2*p+1] += v; 
        return ; 
    }
    if(s>b || e<a) return ;
 
    update(2*p,s,(s+e)/2,a,b,v);
    update(2*p+1,(s+e)/2+1,e,a,b,v);
 
    seg[p] = max(seg[2*p] , seg[2*p+1]);
}
int gt(int p , int s , int e , int a , int  b)
{
    chk(p,s,e);
    if(s >= a && e <= b) return seg[p];
    if(s>b || e<a) return 0; 
    
    return max(gt(2*p,s,(s+e)/2,a,b) , gt(2*p+1,(s+e)/2+1,e,a,b));
}
 
 
int main()
{
    cin >> n >> k; 
    for(int i=1 ; i<=n; i++) 
     cin >> a[i], 
     bef[i] = last[a[i]], 
     last[a[i]] = i;
    
 set<int> st; 
 for(int i=1 ; i<=n ;i++)
  st.insert(a[i]), 
  dp[i] = st.size();
 
    for(int tkn=2 ; tkn<=k ;tkn ++)
    {
        for(int i=1 ; i<=n ; i++)
      update(1, 1, n, i, i, dp[i]);
 
     for(int i=1 ; i<=n; i++)
      update(1, 1, n, bef[i], i-1, 1),
      dp[i] = gt(1, 1, n, tkn - 1, i);
 
     memset(seg, 0, sizeof seg); 
     memset(lazy, 0, sizeof lazy);  
    }
     
    cout << dp[n];
}