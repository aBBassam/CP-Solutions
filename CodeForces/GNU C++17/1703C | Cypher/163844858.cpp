// Problem: C. Cypher
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/C
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
 
 
const int N = 110; 
int n, a[N];
 
 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ;i <=n;i++)
  cin >> a[i]; 
 
 
 for(int i=1 ; i <= n; i++)
 {
  int k; cin >> k;
  string s;cin  >> s;
  
  int x = 0; 
  
  for(int j=0 ; j<k ;j++)
  {
   if(s[j] == 'U') 
   {
    x ++ ; 
    if(x == 10) x = 0;
   }
   else 
   {
    x --; 
    if(x == -1)
     x= 9; 
   }
  }
  
  int res = a[i] - x; 
  while(res < 0)
   res += 10; 
   
  while(res > 9)
   res -= 10; 
   
  cout << res << " ";
 }
 
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 