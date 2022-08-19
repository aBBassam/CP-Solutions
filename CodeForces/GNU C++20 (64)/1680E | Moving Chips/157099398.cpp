#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 200100, INF = 5e5; 
int n, dp[N][2][2], ind; 
string s[4]; 
 
 
int solve(int i, int floor, int tookOther)
{
 if(i > ind) return 0; 
 
 int &ret = dp[i][floor][tookOther];
 if(ret + 1) return ret; 
 ret = INF; 
 
 if(!tookOther) ret = min(ret, 1 + solve(i, !floor, 1)); 
 
 if(s[!floor][i] == '.' || tookOther) ret = min(ret, 1 + solve(i + 1, floor, 0));
 else ret = min(ret, 2 + solve(i + 1, floor, 0));
 
 return ret; 
}
 
int main()
{
 test
 {
  cin >> n >> s[0] >> s[1]; 
  s[0] = "*" + s[0]; 
  s[1] = "*" + s[1]; 
  
  for(int i=0 ; i<=n; i++)
   for(int j=0 ; j<2; j++)
    for(int k=0 ; k<2 ; k++)
     dp[i][j][k] = -1; 
  
  for(int i=1 ; i<=n; i++)
   if(s[0][i] == '*' || s[1][i] == '*')
    ind = i; 
  
  for(int i=1 ; i<=n; i++)
   if(s[0][i] == '*' || s[1][i] == '*')
   {
    cout << min(solve(i, 0, 0), solve(i, 1, 0)) - 1 << '\n'; 
    break;
   }
 }
}