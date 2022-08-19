// Problem: B. Array Decrements
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/B
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
 
 
const int N = 50010; 
ll n, a[N], b[N]; 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 for(int i=1 ; i<=n; i++) cin >> b[i]; 
 
 ll mnReq = 0; 
 for(int i=1 ;i<=n; i++) if(b[i] == 0)
  mnReq = max(mnReq, a[i]); 
  
 ll dif = -1; 
 for(int i=1 ; i<=n; i++) if(b[i])
 {
  if(a[i] < b[i]) return void(cout << "NO\n");
   
  if(dif == -1) dif = a[i] - b[i]; 
  else
  {
   if(a[i] - b[i] != dif)
    return void(cout << "NO\n");
  }
  
  if(dif < mnReq) return void(cout << "NO\n");
 }
 
 
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 