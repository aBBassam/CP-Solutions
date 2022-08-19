 
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
 
int a[10]; 
 
void solve()
{
 cin >> a[1] >> a[2] >> a[3]; 
 sort(a + 1, a + 3 + 1); 
 
 int ans = 0; 
 
 if(a[1]) ans ++, a[1] --; 
 if(a[2]) ans ++, a[2] --; 
 if(a[3]) ans ++, a[3] --; 
 
 
 sort(a + 1, a + 3 + 1); 
 
 if(a[3] >= 1)
 {
  if(a[2] >= 1)
  {
   ans ++; 
   a[3] --; 
   a[2] --; 
  }
 }
 
 if(a[3] >= 1)
 {
  if(a[1] >= 1)
  {
   ans ++; 
   a[3] --; 
   a[1] --; 
  }
 }
 
 
 if(min(a[1], a[2]) >= 1)
 {
  ans ++; 
  a[1] --, a[2] --;
 }
 
 if(min({a[1], a[2], a[3]}) >= 1) ans ++; 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 