// Problem: C. Recover an RBS
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/C
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
set<int> st;
 
 
bool chk(string s)
{
 int dif = 0;
 for(int i=1 ; i<=n; i++)
  if(s[i] == '(') dif ++ ; 
  else 
  {
   dif -- ; 
   if(dif < 0) return 0; 
  }
  
 return dif == 0;
} 
 
 
void solve( )
{
 cin >> s; 
 n = s.length(); 
 s = "*" + s; 
 st.clear(); 
 int fr = -1, sc = -1; 
 
 
 int openToPut = n / 2 - count(s.begin(), s.end(), '('); 
 int dif = 0; 
 
 for(int i=1 ; i<=n ; i++)
 {
  if(s[i] == '(') dif ++; 
  else if(s[i] == ')') dif -- ; 
  else
  {
   st.insert(i); 
   if(openToPut) openToPut --, s[*st.begin()] = '(', st.erase(st.begin()), dif ++, fr = i; 
   else  s[*st.begin()] = ')', st.erase(st.begin()), dif --, sc = (sc == -1 ? i : sc); 
  }
 }
 
 if(fr != -1 && sc != -1 && fr != sc)
 {
  swap(s[fr], s[sc]); 
  if(chk(s)) return void(cout << "NO\n");  
 }cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}