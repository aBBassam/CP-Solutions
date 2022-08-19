#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const ll MOD = 1e9 + 7; 
ll n, k, d, dp[110][2]; 
 
 
int main()
{
 cin >> n >> k >> d; 
 
 dp[0][0] = 1; 
 for(int sm = 1 ; sm <= n ; sm ++)
  for(int i = 1 ; i <= k ; i++)
   for(int has :{0, 1})
    if(sm - i >= 0)
    {
     if(has) dp[sm][1] += dp[sm - i][1] + (i >= d ? dp[sm - i][0] : 0), dp[sm][1] %= MOD; 
     else if(i < d) dp[sm][0] += dp[sm - i][0], dp[sm][0] %= MOD;
    }
 
 cout << dp[n][1];
}