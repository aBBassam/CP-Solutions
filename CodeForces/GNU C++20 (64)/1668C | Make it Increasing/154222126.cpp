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
ll n, a[N]; 
 
 
ll solve(int ind)
{
 ll prev = 0, ret = 0; 
 
 for(int i=ind + 1; i<=n ;i++)
 {
  if(a[i] > prev)
  {
   ret ++; 
   prev = a[i]; 
  }
  else 
  {
   ll take = prev / a[i] + 1; 
   prev = take * a[i]; 
   ret += take;
  }
 }
 
 prev = 0; 
 for(int i=ind - 1; i>0 ;i--)
 {
  if(a[i] > prev)
  {
   ret ++; 
   prev = a[i]; 
  }
  else 
  {
   ll take = prev / a[i] + 1; 
   prev = take * a[i]; 
   ret += take;
  }
 }
 
 return ret;  
}
 
 
int main()
{
 cin >> n; 
 for(int i=1 ; i<=n ;i++) cin >> a[i];
 
 ll ans = 1e18; 
 for(int i=1 ; i<=n ; i++) ans = min(ans, solve(i)); 
 cout << ans; 
}