#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 300100, Mod = 998244353; 
pair<int, int> a[N]; 
int n, k, ans, seg[4 * N], lazy[4 * N];
map<int, set<int>> inds; 
 
 
void chk (int p , int s , int e)
{
    if(lazy[p])
    {
        seg[p] += lazy[p];
        if(s!=e) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }
}
void update(int p , int s , int e, int a , int b, int v)
{
    chk(p,s,e);
 
    if(s >= a && e <= b) 
    {
        seg[p] += v; 
        if(s!=e) lazy[2*p] += v, lazy[2*p+1] += v; 
        return ; 
    }
 
    if(s>b || e<a)return ;
    update(2*p,s,(s+e)/2,a,b, v);
    update(2*p+1,(s+e)/2+1,e,a,b, v);
    seg[p] = seg[2*p] + seg[2*p+1];
}
ll gt(int p , int s , int e , int a , int  b)
{
    chk(p,s,e);
    if(s >= a && e <= b) return seg[p];
    if(s>b || e<a) return 0; 
    
    return gt(2*p,s,(s+e)/2,a,b) + gt(2*p+1,(s+e)/2+1,e,a,b);
}
 
 
 
int Inv[N];
int Fact[N];
int iFact[N];
 
void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}
 
int add(int x, int y)
{
    return add_self(x, y), x;
}
 
void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += Mod;
}
 
int sub(int x, int y)
{
    return sub_self(x, y), x;
}
 
int mul(int x, int y)
{
    return (long long) x * y % Mod;
}
 
int C(int n, int r)
{
    if(n < 0 || r < 0 || n < r) return 0;
    return mul(Fact[n], mul(iFact[r], iFact[n - r]));
}
 
int fp(int x, int y)
{
    int Res = 1;
    for( ; y > 0; y >>= 1, x = mul(x, x))
        if(y & 1)
            Res = mul(Res, x);
    return Res;
}
void PreCalcMod()
{
    Inv[1] = 1;
    for(int i = 2; i < N; i++)  Inv[i] = sub(0, mul(Mod / i, Inv[Mod % i]));
 
    Fact[0] = iFact[0] = 1;
    for(int i = 1; i < N; i++)  Fact[i] = mul(i, Fact[i - 1]);
    for(int i = 1; i < N; i++)  iFact[i] = mul(Inv[i], iFact[i - 1]);
}
 
 
 
 
int main()
{
 go;
 PreCalcMod();
  cin >> n >> k; 
  for(int i=0 ; i<n ;i++)  cin >> a[i].F >> a[i].S;
    sort(a, a + n); 
    for(int i=0 ; i<n; i++)  inds[a[i].F].insert(i); 
   
    for(int i=0 ; i<n; i++)
    {
     inds[a[i].F].erase(i); 
     if(inds[a[i].F].empty()) 
      inds.erase(a[i].F);
  
     auto it = inds.upper_bound(a[i].S); 
     if(it == inds.begin() || inds.empty()) continue; 
     it -- ; 
     update(1, 0, n-1, i + 1, *(it->S).rbegin(), +1); 
 }
 
    for(int i=0 ; i<n ; i++) 
    {
     int interSections = gt(1, 0, n-1, i, i);  
     if(interSections >= k - 1) add_self(ans, C(interSections, k - 1));
    }
 
    cout  << ans;
}