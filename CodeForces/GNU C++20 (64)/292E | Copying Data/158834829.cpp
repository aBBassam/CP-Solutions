#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
 
 
struct node
{
 ll val; 
    node(ll x)
    {
     val = x; 
    };
    node()
    {
       val = 0; 
    };
};
 
 
 
const int N = 100100; 
int n, q, a[N], b[N]; 
vector<pair<pair<int, int>, int>> queries; 
int lazy[4 * N]; 
node seg[4 * N];
 
 
node Merge(node A, node B)
{
 return node(A.val + B.val); 
}
void chk (int p , int s , int e) 
{
    if(lazy[p])
    {
        seg[p].val = lazy[p];
        if(s!=e)
        {
            lazy[2*p] = lazy[p],
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}
void update(int p , int s , int e, int a , int b , int v)
{
    chk(p,s,e);
 
    if(s >= a && e <= b) 
    {
        seg[p].val = v; 
        
        if(s!=e)
        {
            lazy[2*p] = v; 
            lazy[2*p+1] = v; 
        }
        return ; 
    }
 
    if(s>b || e<a)
        return ;
 
    update(2*p,s,(s+e)/2,a,b,v);
    update(2*p+1,(s+e)/2+1,e,a,b,v);
 
    seg[p] = Merge(seg[2*p] , seg[2*p+1]);
}
node gt(int p, int s, int e, int a, int b)
{
 chk(p, s, e);
    if (s >= a && e <= b)
        return seg[p];
    if (s > b || e < a)
        return node();
    return Merge(gt(2 * p, s, (s + e) / 2, a, b), gt(2 * p + 1, (s + e) / 2 + 1, e, a, b));
}
 
 
 
 
int main()
{
 go;
    cin >> n >> q;
    for(int i=1 ; i<=n ;i++) cin>> a[i]; 
    for(int i=1 ; i<=n ;i++) cin>> b[i]; 
    
    queries.push_back({{0, 0}, 0}); 
    int cnt = 1; 
    
    while(q--)
    {
     int t; cin >> t; 
     if(t == 1)
     {
      int aI, bI, k; cin >> aI >> bI >> k;  
      queries.push_back({{aI, bI}, k}); 
      update(1, 1, n, bI, bI + k - 1, cnt++);
     }
     else 
     {
      int ind; cin >> ind; 
      int qr = gt(1, 1, n, ind, ind).val;
    
 
      if(qr) cout << a[queries[qr].F.F + (ind - queries[qr].F.S)] << '\n';
      else cout << b[ind] << '\n';
     }
    }
    
}