// Problem: B. Optimal Reduction
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/B
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
 
const int N =  200100; 
ll n, a[N]; 
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ;i <= n; i++) cin >> a[i]; 
 
 
 int inc = 1; 
 
 
 for(int i = 2 ; i <= n; i++) 
 {
  if(inc)
  {
   if(a[i] < a[i - 1]) inc = 0; 
  }
  else
  {
   if(a[i] > a[i - 1])
   {
    return void(cout << "NO\n");
   }
  }
 }
 
 cout << "YES\n"; 
}
 
 
int main()
{
 test 
  solve(); 
}
 
 