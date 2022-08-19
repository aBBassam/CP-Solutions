// Problem: D. Double Strings
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/D
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
 
 
const int N = 100100; 
map<string, int> rep; 
int n; 
string s[N];
 
 
void solve()
{
 rep.clear();
 cin >> n;
 for(int i=1 ; i<=n; i++)
  cin >> s[i], rep[s[i]] ++; 
 
 for(int i=1 ; i<=n; i++)
 {
  rep[s[i]] ++ ; 
  int ans = 0; 
  
  int k = s[i].length();
  for(int j=1 ; j < k ; j++)
   ans |= (rep.find(s[i].substr(0, j)) != rep.end()) && (rep.find(s[i].substr(j, k - j)) != rep.end());
  
  cout << ans;
 }
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 