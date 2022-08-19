// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/F
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
int n;
int seg[4 * N + 10], a[N];
set<ll> nms; 
map<int, int> compress; 
 
 
int Merge(int A, int B)
{
    return A + B; 
}
void update(int p, int s, int e, int i, int v)
{
    if (s == e)
        return void(seg[p] += v);
    if (i <= (s + e) / 2)
        update(2 * p, s, (s + e) / 2, i, v);
    else
        update(2 * p + 1, (s + e) / 2 + 1, e, i, v);
        
    seg[p] = Merge(seg[2 * p], seg[2 * p + 1]);
}
int gt(int p, int s, int e, int a, int b)
{
    if (s >= a && e <= b)
        return seg[p];
    if (s > b || e < a)
        return 0; 
    return Merge(gt(2 * p, s, (s + e) / 2, a, b), gt(2 * p + 1, (s + e) / 2 + 1, e, a, b));
}
 
 
 
 
void solve( )
{ 
 nms.clear(); 
 compress.clear();
 
 cin >> n; 
 for(int i=1 ;i <=n; i++) cin>> a[i], nms.insert(a[i]); 
 for(int i =1 ; i <= 4 * n ; i++) seg[i] = 0;
 
 int cmp = 1; 
 for(int i : nms)
  compress[i] = cmp ++ ; 
 
 for(int i=1 ; i <= n  ;i ++) if(i > a[i])
  update(1, 1, cmp, compress[a[i]], +1);
 
 
  
 ll ans = 0; 
 for(int i=1 ; i <= n  ;i ++) if(i > a[i])
 {
  update(1, 1, cmp, compress[a[i]], -1);
  
  auto it = nms.upper_bound(i); 
  if(it != nms.end())
  {
   int from = *it; 
   ll get = gt(1, 1, cmp, compress[from], cmp); 
   ans += get;
  }
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 