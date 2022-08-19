#include <bits/stdc++.h>
#define ll long long
#define test int t; cin >> t; while(t--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n , k , d , dp[110][2] , mod = 1e9+7;
 
 
ll solve(ll weight =0, int dToken =0)
{
    if(weight == n)
        return !!dToken;
 
    if(weight > n)
        return 0;
 
    ll &ret = dp[weight][dToken];
    if(ret +1) return ret;
    ret = 0;
 
    for(int i=1 ; i <= k ; i++)
        ret = (ret + solve(weight + i, dToken || i >= d )) %mod;
 
    return ret;
}
 
int main ()
{
    go
    memset(dp,-1,sizeof dp);
    cin >> n >> k >> d;
    cout << solve();
}