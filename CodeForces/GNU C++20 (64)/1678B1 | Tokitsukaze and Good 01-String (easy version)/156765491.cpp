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
ll n, dp[N][2][2][3], dpp[N][2][2][3]; 
string s; 
 
 
ll solve(int i, int zeroRem, int oneRem, int last)
{
 oneRem %= 2, zeroRem %= 2; 
 if(i > n) return max(zeroRem, oneRem) > 0 ? 1e9 : 0; 
 ll &ret = dp[i][zeroRem][oneRem][last]; 
 if(ret + 1) return ret; 
 ret = 1e9; 
 
 // can flip it to 0 or 1
 if(!max(zeroRem, oneRem)) 
 {
  // flip to one
  ret = min(ret, (s[i] == '0') + solve(i + 1, 0, 1, 1));
  
  // flip to zero
  ret = min(ret, (s[i] == '1') + solve(i + 1, 1, 0, 0));
 }
 
 if(oneRem)
  ret = min(ret, (s[i] == '0') + solve(i + 1, 0, 0, 1));
 
 if(zeroRem)
  ret = min(ret, (s[i] == '1') + solve(i + 1, 0, 0, 0));
 
 return ret;
} 
 
 
int main()
{
 test
 {
  cin >> n >> s, s = "&" + s; 
  for(int i=0 ; i<=n; i++)
   for(int j=0 ; j<2 ; j++)
    for(int k=0 ; k<2 ; k++)
     for(int m=0 ; m<3; m++)
      dp[i][j][k][m] = dpp[i][j][k][m] = -1; 
  
  cout << solve(1, 0, 0, 2) <<  '\n'; 
 }
}
 
 
 