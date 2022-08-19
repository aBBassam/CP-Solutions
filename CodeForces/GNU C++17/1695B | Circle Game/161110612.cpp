// Problem: B. Circle Game
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "Mike\n" : "Joe\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
ll n, a[100]; 
 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) 
 cin >> a[i]; 
 
 if(n % 2 == 0)
 {
  ll  mn = 1e18; 
  for(int i=1 ;i<=n; i++)
   mn = min(mn, a[i]); 
  
  for(int i=1 ;i <= n; i++)if(a[i] == mn)
  {
   if(i&1)
   {
    cout << "Joe\n"; 
   }
   else 
   {
    cout << "Mike\n"; 
   }
   break;
  }
 }
 else
 {
  cout << "Mike\n";
 } 
}
 
 
int main()
{
    test
  solve();
}
 
 
 