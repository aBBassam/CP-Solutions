// Problem: C. Double Sort
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/C
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
 
 
const int N = 1000; 
ll n, nm; 
pair<ll, ll> a[N], b[N]; 
vector<pair<ll, ll>> ans; 
 
 
void solve()
{
 ans.clear(); 
 
 cin >> n; 
 for(int i=1 ;i <=n; i++)
  cin >> nm, 
  a[i].F = b[i].F = nm;  
 
 for(int i=1 ;i <=n; i++)
  cin >> nm, 
  a[i].S = b[i].S = nm;  
 
  
 sort(a + 1, a + n + 1); 
 for(int i=2 ; i<=n; i++)
  if(a[i].S < a[i - 1].S)
   return void(cout << "-1\n"); 
 
 
 
 while(1)
 {
  int sorted = 1; 
  for(int i=2 ; i<=n; i++)
   if(b[i].F < b[i - 1].F)
   {
    swap(b[i], b[i - 1]); 
    ans.push_back({i, i - 1});
    sorted = 0; 
    break;
   }
   
  if(sorted) break;
 }
 
 while(1)
 {
  int sorted = 1; 
  for(int i=2 ; i<=n; i++)
   if(b[i].S < b[i - 1].S && b[i].F >= b[i - 1].F)
   {
    swap(b[i], b[i - 1]); 
    ans.push_back({i, i - 1});
    sorted = 0; 
    break;
   }
   
  if(sorted) break;
 }
 cout << ans.size() << '\n'; 
 for(auto it : ans) cout << it.F << ' ' << it.S << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 
 
 