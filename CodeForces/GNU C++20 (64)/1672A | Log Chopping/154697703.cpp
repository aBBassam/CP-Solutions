// Problem: A. Log Chopping
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/A
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
 
 
const int N = 100; 
int n;
multiset<int> lgs; 
 
 
void solve()
{
 cin >> n; 
 int t = 0; 
 lgs.clear(); 
 
 for(int i=0 ; i<n; i++)
 {
  int a; cin >> a; 
  lgs.insert(a);
 }
 
 
 while(*lgs.rbegin() > 1)
 {
  t ++ ; 
  int val = *lgs.rbegin(); 
  lgs.erase(--lgs.end());
  
  lgs.insert(ceil(val / 2.0)); 
  lgs.insert(val / 2);  
 }
 
 cout << (t%2 == 1 ? "errorgorn" : "maomao90") << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 