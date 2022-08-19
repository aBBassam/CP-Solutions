#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 200100, mod = 1e9 + 7; 
ll n, a[N], ind[N]; 
 
int main()
{
 test
 {
  cin >> n;
  for(int i=1 ;i<=n; i++) cin >> a[i], ind[a[i]] = i; 
  
  ll ans = 1; 
  int st = ind[0], en = ind[0], mex = 1; 
  
  while(mex <= (n - 1))
  {
   if(ind[mex] <= en && ind[mex] >= st)
   {
    ans *= (en - st + 1 - mex); 
    ans %= mod; 
   }
   else if(ind[mex] >= en) en = ind[mex]; 
   else st = ind[mex]; 
 
   mex ++ ;
  }
  
  cout << ans << '\n'; 
 }
}