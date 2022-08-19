// Problem: H2. Maximum Crossings (Hard Version)
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/H2
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
 
 
const int N = 200100; 
ll n, a[N], seg[5 * N]; 
map<int, int> rep;  
 
void update(int p , int s , int e , int i , ll v)
{
    if(s == e) 
    {
        seg[p] += v; 
        return;
    }
    
    if(i <= (s+e)/2) update(2*p,s,(s+e)/2,i,v);
    else update(2*p+1,(s+e)/2+1,e,i,v);
    seg[p] = seg[2*p] + seg[2*p+1];
}
 
ll gt(int p , int s , int e , int a , int  b)
{
    if(s >= a && e <= b) return seg[p];
    if(s>b || e<a) return 0; 
    return gt(2*p,s,(s+e)/2,a,b) + gt(2*p+1,(s+e)/2+1,e,a,b);
}
 
void solve( )
{
 cin >> n; 
 for(int i=1 ;i <=n; i++) cin >> a[i]; 
 
 ll ans = 0; 
 for(int i=1 ;i <=n; i++)
 {
  ans += gt(1, 1, n, a[i], n);
  update(1, 1, n, a[i], +1); 
 }
 
 
 cout << ans << '\n';
 for(int i=0 ;i <= 4* n; i++)seg[i] = 0; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 