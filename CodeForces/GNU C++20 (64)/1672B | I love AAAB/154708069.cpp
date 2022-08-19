// Problem: B. I love AAAB
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/B
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
int n;
string s; 
 
 
 
void solve()
{
 cin >> s; 
 int n = s.length(); 
 reverse(s.begin(), s.end()); 
 s = '^' + s; 
 
 
 if(s[1] != 'B') return void(cout << "NO\n");
 
 int bs = 0 ; 
 
 for(int i=1 ; i<=n; i++)
 {
  if(s[i] == 'B')
  {
   bs ++ ; 
  }
  else 
   bs = max(0, bs - 1);
 }
 
 if(bs)cout << "NO\n"; 
 else cout << "YES\n"; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 