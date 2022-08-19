// Problem: B. Triple
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/B
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
 
 
 
 
map<ll, ll>rep ; 
 
void solve()
{
 rep.clear();
 ll a, n; 
 cin >> n; 
 for(int i=1 ; i<=n ;i++) 
  cin >> a, 
  rep[a] ++;
  
 for(auto it : rep)
  if(it.S >= 3)
   return void(cout << it.F << '\n'); ;
 cout << "-1\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 