#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 300100; 
ll n, k, a[N], sub[N]; 
 
 
int main()
{
    cin >> n >> k; 
    for(int i=1 ;i <=n ;i++) cin >> a[i]; 
  
    ll sm = 0, tkn = 0, ans = 0;
    for(int i=n ; i>=1 ; i--)
 {
  sm -= tkn; 
  tkn -= sub[i]; 
 
  if(sm < a[i])
  {
   ll df = a[i] - sm ;
   ll K = (i - k > 0 ? k : i); 
   ll take = df / K + (df % K != 0); 
   
   if(i - k > 0) sub[i - k] += take;
   
   tkn += take, ans += take, sm += take * K;
  }
    }
   
 cout << ans; 
}
 
 
 