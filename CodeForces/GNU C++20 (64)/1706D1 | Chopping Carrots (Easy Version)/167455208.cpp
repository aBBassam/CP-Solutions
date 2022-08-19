// Problem: D1. Chopping Carrots (Easy Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1706/D1
// Memory Limit: 64 MB
// Time Limit: 4000 ms
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
 
const int N = 3010; 
ll n, k, a[N]; 
ll mn, mx; 
 
 
void solve()
{
 cin >> n >> k; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 
 ll ans = 1e18;
 
 for(int i=1 ; i<=N ;i++)
 { 
  mn = 1e18, mx = -1e18; 
  
  bool takeAns = 1;
  
  for(int j=1 ; j <= n ; j++)
  {  
   ll st = 1, en = k, anss = a[j] / k; 
    
   while(st <= en)
   {
    ll mid = (st + en) / 2; 
    if((a[j] / mid) <= i)  anss = a[j] / mid, en = mid - 1;
    else st = mid + 1; 
   }
   
   mn = min(mn, anss); 
   mx = max(mx, anss); 
   if(anss > i) takeAns = 0; 
  }
  
  if(takeAns)
   ans = min(ans, mx - mn);
 }
 
 
 cout << ans << '\n';
}
 
 
int main()
{
 test 
  solve(); 
}
 
 