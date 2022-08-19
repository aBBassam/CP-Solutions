// Problem: C. Unequal Array
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/C
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
int n, a[N], b[N]; 
 
 
int sl()
{
 int ret = 0; 
 
 for(int i=1 ; i<=n; i++)
  b[i] = a[i]; 
  
 int k = 0; 
 for(int i=1 ; i<n ;i++)
  if(a[i] == a[i + 1]) 
   k ++ ; 
   
  
 for(int i=2 ; i<=n ;i++)
 {
  if(k <= 1) break;
  
   if(b[i] == b[i - 1])
  {
   ret ++ ; 
   if(i + 1 <= n)
   {
    k -- ; 
    if(b[i] != b[i + 1]) k ++; 
    if(i + 2 <= n && b[i + 1] == b[i + 2]) k--; 
    
    b[i] = b[i + 1] = -1; 
   }
  }
 }
 
 if(k > 1) return 1e9; 
 return ret; 
}
 
 
void solve()
{ 
 cin >> n; 
 for(int i= 1; i<=n ;i++) cin >> a[i];
 
 int ans1 = sl(); 
 reverse(a + 1, a + n + 1); 
 int ans2 = sl(); 
 
 cout << min(ans1, ans2) << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 