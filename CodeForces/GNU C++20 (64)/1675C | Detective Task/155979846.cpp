// Problem: C. Detective Task
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/C
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
 
string s; 
int n; 
vector<int> occ; 
 
void solve()
{
 cin >> s; 
 s = "1" + s + "0"; 
 n = s.length(); 
 s = '&' + s;  
 occ.clear(); 
 
 for(int i =1 ; i<=n; i++)
  if(s[i] == '0')
   occ.push_back(i); 
 
 
 int ans = 0; 
 for(int i=1 ; i<=n;  i++)
  if(s[i] == '1')
  {
   auto it = upper_bound(all(occ), i); 
   if(it == occ.end()) break;
   
   int ind = *it; 
   ans = ind - i + 1; 
   if(i == 1) ans --;
   if(ind == n) ans --; 
  }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 