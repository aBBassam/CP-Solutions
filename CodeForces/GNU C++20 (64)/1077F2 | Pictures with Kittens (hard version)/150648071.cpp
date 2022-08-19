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
ll n, k, x, a[N], dp[N][N];
deque<pair<ll, ll>> dq;  
 
 
int main()
{
 go;
 cin >> n >> k >> x;
 for(int i=1 ; i<=n ;i++) cin >> a[i];
 
 ll clearTo = max(k, n);
 for(int i=0 ; i<=clearTo ; i++)
  for(int j=0 ; j<=clearTo ; j++)
   dp[i][j] = -1e15;
 
 for(int i=1 ; i<=k ; i++)
  dp[1][i] = a[i];
 
 for(int take=2 ; take <= x ; take ++)
 {
  dq.clear();
  dp[take][1] = a[1];
  
  for(int i=2 ; i <= n ;i++)
  {
   // adding dp[take-1][i-1] value to the dequeue and removing unwanted values
   while(!dq.empty() && dq.back().F <= dp[take-1][i-1]) dq.pop_back();
   dq.push_back({dp[take-1][i-1], i - 1}); 
   while(!dq.empty() && dq.front().S < i - k) dq.pop_front();
  
   dp[take][i] = a[i] + dq.front().F;  
  }
 }
 
 
 ll ans = -1; 
 for(int i=n ; i>n-k ; i--) 
  ans = max(ans, dp[x][i]); 
  
 cout << ans;   
}