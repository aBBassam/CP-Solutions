// Problem: B. Dictionary
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/B
// Memory Limit: 512 MB
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
 
 
set<string> st; 
string s; 
map<string, int> m; 
 
 
int main()
{
 for(char c = 'a' ;  c <= 'z' ; c++)
  for(char cc = 'a' ;  cc <= 'z' ; cc++) 
   if(cc != c)
  {
   string s ="";
   s.push_back(c);
   s.push_back(cc);
   
   st.insert(s);
  }
  
 int ind = 1; 
 for(string s : st)
  m[s] = ind ++; 
 
 
    test
 {
  string ss; cin >> ss; 
  cout << m[ss] << '\n';
 }
}
 
 
 