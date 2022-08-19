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
 
 
 
const int N = 1000100; 
int n, a[N]; 
map<int, int> compress; 
set<int> st; 
node seg[4 * N][2]; 
 
 
 
node Merge(node A, node B)
{
 return node(A.val + B.val); 
}
void update(int p, int s, int e, int i, int v, int sg)
{
    if (s == e)
        return void(seg[p][sg].val += v);
    if (i <= (s + e) / 2)
        update(2 * p, s, (s + e) / 2, i, v, sg);
    else
        update(2 * p + 1, (s + e) / 2 + 1, e, i, v, sg);
        
    seg[p][sg] = Merge(seg[2 * p][sg], seg[2 * p + 1][sg]);
}
node gt(int p, int s, int e, int a, int b, int sg)
{
    if (s >= a && e <= b)
        return seg[p][sg];
    if (s > b || e < a)
        return node();
    return Merge(gt(2 * p, s, (s + e) / 2, a, b, sg), gt(2 * p + 1, (s + e) / 2 + 1, e, a, b, sg));
}
 
 
 
 
 
int main()
{
        go; 
    cin >> n; 
    for(int i=1 ; i<=n ; i++) cin >> a[i], st.insert(a[i]); 
    
  int comp = 1; 
  for(int I : st)
   compress[I] = comp++;
    
    for(int i=1 ;i <=n; i++) update(1, 1, comp, compress[a[i]], 1, 0); 
    
    
    ll ans = 0; 
    
    for(int i=n ; i>0 ; i--)
    {
     update(1, 1, comp, compress[a[i]], -1, 0); 
     
     if(a[i] != 1e9 && a[i] != 1)
     ans += (gt(1, 1, comp, compress[a[i]] + 1, comp, 0).val) * (gt(1, 1, comp, 0, compress[a[i]] - 1, 1).val); 
     
     
     update(1, 1, comp, compress[a[i]], 1, 1); 
    } 
    
    
    cout << ans; 
}
 
 
 