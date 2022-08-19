// Problem: A. Everyone Loves to Sleep
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/0
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
 
int n, m, h; 
vector<pair<int, int>> v; 
 
void f(int min)
{
 int hs = min / 60;  
 cout << hs << ' '; 
 min -= hs * 60;  
 cout << min << '\n'; 
}
 
 
void solve()
{
 cin >> n >> h >> m; 
 v.resize(n); 
 for(auto &it : v)
  cin >> it.F >> it.S; 
 
 sort(all(v)); 
 
 for(auto it : v)
  if(it.F > h || (it.F == h && it.S >= m))
  {
   int ans = 0; 
   ans += it.F - h; 
   ans *= 60; 
   
   if(it.S >= m)
    ans += it.S - m; 
   else
    ans -= 60, 
    ans += it.S + 60 - m; 
   
   return f(ans);
  }
 
 for(auto it : v)
  if((it.F + 24) > h || ((it.F + 24) == h && it.S >= m))
  {
   int fr = it.F + 24; 
   int sc = it.S; 
   
   int ans = 0; 
   ans += fr - h; 
   ans *= 60; 
   
   if(sc >= m)
    ans += sc - m; 
   else
    ans -= 60, 
    ans += sc + 60 - m; 
   
   return f(ans);
  }
}
 
 
int main()
{
 test 
  solve(); 
}
 
 