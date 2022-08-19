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
ll n, k, a[N], pre[N]; 
 
 
 
void solve()
{
 cin >> n >> k;
 for(int i=1 ;i <=n; i++) cin >> a[i], pre[i] = a[i] + pre[i - 1];
 
 
 if(k <= n)
 {
  ll ans = 0; 
  // maximum subarray of length k
  for(int i=1 ; i<=n; i++)
  {
   int en = i + k - 1; 
   if(en > n) break;
   
   ans = max(ans, pre[en] - pre[i - 1]); 
  }
 
  k --; 
  
  cout << ans + ( k * (k + 1) / 2 )<< '\n'; 
 }
 else
 {
  if(n == 1)
   return void(cout << a[1] + k - 1 << '\n');
   
  // start from the beginning : 
  ll ans = pre[n]; 
  
  ll K = ((n * (n - 1)) / 2) ; 
  ans += K;
  k -= n; 
  
  ans += k * n;
  
  
  cout << ans << '\n';
 }
}
 
 
int main()
{
    test
  solve();
}
 
 
 