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
ll n, s, l, dp[N], a[N]; 
multiset<ll> st; 
 
int main()
{
 cin >> n >> s >> l; 
 for(int i=1 ; i<=n ;i++) cin >> a[i], dp[i] = 1e12;  
 
 
 ll lf = 1, ri = 1; 
 st.insert(a[1]);
 
 while(ri <= n)
 {
  while(ri - lf + 1 < l)
  {
   if(ri == n) return cout << -1, 0; 
   st.insert(a[++ri]);
  }
  if(*st.rbegin() - *st.begin() > s || dp[lf - 1] == 1e12)
  {
   st.erase(st.find(a[lf++]));
   continue;
  }
  
  dp[ri] = dp[lf - 1] + 1;
  st.insert(a[++ri]);
 }
 
 cout << dp[n];
}