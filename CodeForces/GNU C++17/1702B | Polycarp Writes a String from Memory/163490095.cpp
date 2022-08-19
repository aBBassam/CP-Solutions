// Problem: B. Polycarp Writes a String from Memory
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/B
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
 
 
const int N = 200100; 
int n; 
string s; 
 
 
 
void solve( )
{
 cin >> s; 
 n = s.length(); 
 s = "*" + s; 
 
 set<char> st; 
 int ans = 0;
 
  
 for(int i=1 ; i<=n; i++)
 {
  if(!st.count(s[i]))
  {
   if(st.size() < 3)
   {
    st.insert(s[i]);
   }
   else 
   {
    st.clear(); 
    
    st.insert(s[i]);
    ans ++;
   }
  } 
 }
 
 
 cout << ans + (!st.empty())  << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 