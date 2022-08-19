// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 17; 
ll n; 
vector<ll> v[2]; 
 
 
ll solve(ll a, ll b)
{
 cout << "? " << a << " " << b << endl;
 ll ans; cin >> ans; 
 
 if(ans == 0) return -1; 
 else return ans == 1 ? a : b; 
}
 
ll solve(ll a[4])
{
 ll fr = solve(a[0], a[2]); ;
 if(fr == -1) return solve(a[1], a[3]); 
 else if(fr == a[0]) return solve(a[0], a[3]); 
 else return solve(a[1], a[2]);  
}
 
 
int main()
{
 int T; cin >> T; 
 while(T --)
 {
  
  cin >> n, v[0].resize((1ll << n)), v[1].clear(); 
  for(int i=1 ;i <= (1ll << n) ; i++)  v[0][i - 1] = i;
  
  int theMain = 0; 
  while(v[theMain].size() > 2)
  {
   while(v[theMain].size() >= 4)
   {
    ll a[4]; 
    for(int i=0; i < 4 ; i++)
     a[i] = v[theMain].back(), v[theMain].pop_back();
   
    v[!theMain].push_back(solve(a));
   }
   
   theMain = !theMain;  
  }
 
 
  
  ll ans = v[theMain][0]; 
  if(v[theMain].size() == 2) ans = solve(v[theMain][0], v[theMain][1]); 
  cout << "! " << ans << endl;
 }
}
 
 