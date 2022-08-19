#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 100100; 
int n, a, b, h;
ll seg[4 * N]; 
vector<pair<int, pair<int, int>>> v; 
set<int> bs; 
map<int, int> compress; 
int cmp; 
 
 
void update(int p , int s , int e , int i , ll v)
{
    if(s == e) return void(seg[p] = max(seg[p], v));
    if(i <= (s+e)/2) update(2*p,s,(s+e)/2,i,v);
    else update(2*p+1,(s+e)/2+1,e,i,v);
    seg[p] = max(seg[2*p] , seg[2*p+1]);
}
ll gt(int p , int s , int e , int a , int  b)
{
    if(s >= a && e <= b)return seg[p];
    if(s>b || e<a) return 0; 
    return max(gt(2*p,s,(s+e)/2,a,b), gt(2*p+1,(s+e)/2+1,e,a,b));
}
 
 
int main()
{
 cin >> n; 
 for(int i=0 ; i<n ; i++)
  cin >> a >> b >> h, 
  v.push_back({b, {a, h}}), 
  bs.insert(b); 
 
 sort(all(v));
 for(int i : bs)
  compress[i] = cmp++; 
 bs.clear();
 
  for(int i=0 ; i<n; i++)
 {
  ll val = v[i].S.S; 
  
  if(bs.upper_bound(v[i].S.F) != bs.end())
   val += gt(1, 0, cmp - 1, compress[*bs.upper_bound(v[i].S.F)], cmp - 1);
  
  bs.insert(v[i].F);
  update(1, 0, cmp -1, compress[v[i].F], val); 
 } 
  
 cout << gt(1, 0, cmp-1, 0, cmp - 1);
}