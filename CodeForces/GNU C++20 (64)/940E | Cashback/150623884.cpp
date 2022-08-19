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
ll n, c, a[N], dp[N], pre[N]; 
multiset<ll> st; 
 
int main()
{
 cin >> n >> c; 
 for(int i=1 ; i<=n ;i++) cin >> a[i];
 for(int i=1 ; i<=n ;i++) pre[i] = pre[i - 1] + a[i];
 
 for(int i=1 ; i<=n; i++)
  if(i >= c)
  {
   if(i > c)
    st.erase(st.find(a[i - c]));
    
   st.insert(a[i]);
   dp[i] = min(dp[i - 1] + a[i], pre[i] - pre[i - c] + dp[i - c] - *st.begin());
  }
  else 
  {
   dp[i] = dp[i - 1] + a[i];
   st.insert(a[i]); 
  }
 
 cout << dp[n];
}