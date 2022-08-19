// Problem: B. Patchouli's Magical Talisman
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.com/contest/1688/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
 
const int N = 200100; 
ll n, a[N]; 
 
 
 
void solve()
{
 ll od = 0, ev = 0; 
 
 cin >> n;
 for(int i=1 ; i<= n; i++)
 {
  cin >> a[i]; 
  if(a[i] & 1) od ++ ; 
  else ev ++; 
 }
 
 if(od)
  return void(cout << ev << '\n'); 
  
 ll mn = 1e10;
 
 for(int i=1 ; i<=n  ; i++) if(a[i] % 2 == 0)
 {
   ll val; 
   
   for(ll j=0 ; ; j++)
    if((a[i] & (1ll << j)) != 0)
    {
     val = j; 
     break;
    }
 
   mn = min(mn, val); 
 }
 
 
 cout << mn + (ev - 1) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 