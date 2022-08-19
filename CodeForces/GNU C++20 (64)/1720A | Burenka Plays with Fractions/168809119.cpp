// Problem: A. Burenka Plays with Fractions
// Contest: Codeforces - Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/contest/1720/problem/0
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
 
 
ll gcd(ll a , ll b)
{
   return b == 0 ? a : gcd(b, a % b);
}
 
 
ll a, b, c, d;  
 
void solve()
{
 cin >> a >> b >> c >> d;  
 
 if(a * d == b * c) cout << 0; 
 else if((c * b) && ((a * d) % (c * b) == 0)) cout << 1; 
 else if((a * d) && ((c * b) % (a * d) == 0)) cout << 1; 
 else cout << 2; 
 
 cout << '\n'; 
}
 
 
int main()
{
 test 
  solve(); 
}
 
 