#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 5010; 
ll n, a[N], dp[N], pre[N], suf[N]; 
 
 
ll solve(ll i)
{
 if(i == n) return 1; 
 
 ll &ret = dp[i]; 
 if(ret + 1) return ret; 
 ret = -1e15; 
 
 if(((n - i) % 2 == 0 ) && suf[i + 1] <= (n - i) / 2) ret = 1;
 
 ll mxRep = 0; 
 ll myReps = 0; 
 vector<ll> rept(n + 1, 0);
 
 for(int j=i + 1 ; j <= n; j ++) 
 {
  if(a[i] == a[j])
  { 
   ll cnt = j - i - 1; 
  
    if(2 * mxRep <= cnt && (cnt % 2 == 0))
    ret = max(ret, 1 + solve(j));
    
   myReps ++;
  }
 
  mxRep = max(mxRep, ++rept[a[j]]); 
 }
 
 return ret; 
}
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ;i <=n; i++) cin >> a[i], dp[i] = -1; 
 
 map<ll, ll> rept; 
 for(int i=1 ;i <=n; i++)
  pre[i] = max(pre[i - 1], ++rept[a[i]]); 
 
 suf[n + 1]  = 0; 
 rept.clear(); 
 for(int i=n ; i>0 ; i--)
   suf[i] = max(suf[i + 1], ++rept[a[i]]); 
 
 ll mx = 0; 
 for(int i=1 ;i <=n ;i++) if((i - 1) % 2 == 0 && pre[i - 1] <= ((i - 1) / 2))
  mx = max(mx, solve(i));
 
 cout << mx << '\n'; 
}
 
 
int main()
{
    test
  solve();
}