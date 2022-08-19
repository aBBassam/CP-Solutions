// Problem: A. Division?
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/A
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
 
 
int a[5] = {1900, 1600, 1400, -5000}; 
 
void solve()
{
 int x; 
 cin >> x; 
 cout << "Division "; 
 
 for(int i=0 ;i <4 ; i++)
 {
  if(x >= a[i])
   return void(cout << i + 1 << '\n'); 
 }
}
 
int main()
{
    test
  solve();
}
 
 
 