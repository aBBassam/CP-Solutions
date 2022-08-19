// Problem: B. Dorms War
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/B
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
int n, k; 
string  ss, s; 
set<char> cs; 
 
void solve()
{
 cs.clear();
 cin >> n >> ss >> k; 
 while(k --  )
 {
  char a; cin >> a; 
  cs.insert(a);
 }
 
 s = ""; 
 for(int i=0 ; i<n ;i++)
  if(cs.count(ss[i]))
   s += "1"; 
  else 
   s += "0"; 
 
 reverse(all(s)); 
 s = "%" + s; 
 
 int ans = 0; 
 
 for(int i=1 ; i<=n; i++)
  if(s[i] == '1')
  {
   int l_ans = 0; 
   int j; 
   
   for(j = i + 1 ; j <= n ; j++)
   {
    l_ans ++; 
    if(s[j] == '1')
    {
     i = j - 1; 
     break;
    }
   }
   
   ans  = max(ans, l_ans);
  }
 
 
 cout << ans << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 