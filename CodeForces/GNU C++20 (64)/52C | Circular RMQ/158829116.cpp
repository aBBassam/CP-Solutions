#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
#define int long long
using namespace std;
 
struct node
{
 int val;
    node(int x)
    {
     val = x; 
    };
    node()
    {
        val = 1e16;  // neural values
    };
};
 
const int N = 200100;
node seg[4 * N];
int n, q, a[N], lazy[4 * N];
 
 
 
node Merge(node A, node B)
{
 return node(min(A.val, B.val)); 
}
 
 
void chk (int p , int s , int e) 
{
    if(lazy[p])
    {
        seg[p].val += lazy[p];
        if(s!=e)
        {
            lazy[2*p] += lazy[p],
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}
 
void update(int p , int s , int e, int a , int b , int v)
{
    chk(p,s,e);
 
    if(s >= a && e <= b) 
    {
        seg[p].val += v; 
        
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
 
    seg[p] = Merge(seg[2*p] , seg[2*p+1]);
}
 
void build(int p, int s, int e)
{
    chk(p, s, e);
    if (s == e)
        return void(seg[p] = node(a[s]));
    build(2 * p, s, (s + e) / 2);
    build(2 * p + 1, (s + e) / 2 + 1, e);
    seg[p] = Merge(seg[2 * p], seg[2 * p + 1]);
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
 
 
 
int32_t main()
{
 go; 
 cin >> n; 
 for(int i=1 ;i<=n; i++) cin >> a[i]; 
 cin >> q; 
 
 build(1, 1, n); 
        
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l ++, r++;
        
        char c;
        cin.get(c);
        
        
        if(c != ' ')
        {
            if(l<=r)
                cout<<gt(1,1,n,l,r).val<<endl;
            else
                cout<<min(gt(1,1,n,l,n).val,gt(1,1,n,1,r).val)<<endl;
        }
        else
        {
         ll v; cin >> v; 
         
            if(l<=r)
                update(1,1,n,l,r,v);
            else
                update(1,1,n,l,n,v),update(1,1,n,1,r,v);
        }
    }
}
 
 
 