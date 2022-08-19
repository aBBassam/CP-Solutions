#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const double PI = acos(-1.0); 
const ll N = 100100; 
ll n, a[N], b[N], valNum[N], seg[5 * N];
set<pair<ll, ll>> st; 
 
 
void update(int p , int s , int e , int i , ll v)
{
    if(s == e) return void(seg[p] = max(seg[p], v));
    if(i <= (s+e)/2) update(2*p,s,(s+e)/2,i,v);
    else update(2*p+1,(s+e)/2+1,e,i,v);
    seg[p] = max(seg[2*p],seg[2*p+1]);
}
ll gt(int p , int s , int e , int a , int  b)
{
    if(s >= a && e <= b) return seg[p];
    if(s>b || e<a) return 0; 
    return max(gt(2*p,s,(s+e)/2,a,b) , gt(2*p+1,(s+e)/2+1,e,a,b));
}
 
 
int main()
{
    go; 
    cin >> n ;
    for(int i=0 ; i<n ; i++) cin >> a[i] >> b[i];
    for(int i=0 ; i<n; i++) a[i] *= a[i] * b[i], st.insert({a[i], i});
    
    ll i=-1, lst = -1; 
 
    for(auto it : st) 
     i += (it.F != lst),
        valNum[it.S] = i,
     lst = it.F;
 
    for(int i=0 ; i<n ; i++)
     update(1, 0, n - 1, valNum[i], a[i] +  gt(1, 0, n - 1, 0, valNum[i] - 1));
    
 
    cout << fixed << setprecision(15) << gt(1, 0, n-1, 0, n - 1) * PI;
}