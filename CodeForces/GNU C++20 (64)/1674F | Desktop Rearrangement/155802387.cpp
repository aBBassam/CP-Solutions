#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 1010; 
int n , m, q , a[N] , seg[4 * N][1 + N], ons; 
string s[N]; 
map<pair<int, int>, bool> on; 
 
void update(int p , int s , int e , int i , int v, int id)
{
    if(s == e) 
    {
        seg[p][id] += v; 
        return;
    }
    if(i <= (s+e)/2) update(2*p,s,(s+e)/2,i,v, id);
    else update(2*p+1,(s+e)/2+1,e,i,v, id);
 
    seg[p][id] = seg[2*p][id] + seg[2*p+1][id];
}
int gt(int p , int s , int e , int a , int  b, int id)
{
    if(s >= a && e <= b)  return seg[p][id];
    if(s>b || e<a) return 0; 
    return gt(2*p,s,(s+e)/2,a,b, id) + gt(2*p+1,(s+e)/2+1,e,a,b, id);
}
 
 
 
 
int main()
{
 cin >> n >> m >> q; 
 for(int i=1 ; i<=n; i++) cin >> s[i], s[i] = "d" + s[i];
 
 for(int i=1 ;i <=n; i++)
  for(int j=1 ; j<=m ; j++)
   if(s[i][j] == '*')
    on[{i, j}] = 1, 
    update(1, 1, n, i, 1, j), 
    update(1, 1, m, j, 1, m + 1),
    ons ++; 
 
 while(q--)
 {
  int i, j; 
  cin >> i >> j; 
  if(on[{i, j}])
   update(1, 1, n, i, -1, j), 
   update(1, 1, m, j, -1, m + 1),
   on[{i, j}] = 0,
   ons --; 
  else 
   update(1, 1, n, i, 1, j), 
   update(1, 1, m, j, 1, m + 1),
   on[{i, j}] = 1,
   ons ++; 
  
  int k = ons / n; 
  int ans = gt(1, 1, m, 1, k,m + 1);
  if(ons % n != 0) ans += gt(1, 1, n, 1, ons % n, k + 1);
  
  cout << ons - ans << '\n';
 }
}