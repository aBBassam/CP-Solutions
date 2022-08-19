// Problem: A. Lex String
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/0
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
 
 
const int N = 101; 
int n, m, k; 
string a, b;
 
 
 
int main()
{
    test
    {
  string ans = ""; 
  cin >> n >> m >> k; 
  cin >> a >> b;
  
  sort(all(a)), sort(all(b));
  
  
  int aI = 0, bI = 0; 
  int cntA = 0, cntB = 0; 
  
  
  while(1)
  {
   if(aI == n || bI == m) break; 
   
   if(cntA == k)
   {
    cntA = 0; 
    cntB ++; 
    ans += b[bI ++]; 
    continue;
   }
   if(cntB == k)
   {
    cntB = 0; 
    cntA ++; 
    ans += a[aI ++]; 
    continue;
   }
   
   
   if(b[bI] < a[aI])
   {
    cntA = 0; 
    cntB ++; 
    ans += b[bI ++]; 
 
   }
   else 
   {
    cntB = 0; 
    cntA ++; 
    ans += a[aI ++]; 
   }
  }
 
  cout << ans << '\n';
 }
}
 
 
 