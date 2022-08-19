// Problem: B. NIT Destroys the Universe
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/B
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
 
 
const int N = 100100; 
ll n, a[N]; 
 
 
 
void solve( )
{
 ll z = 0; 
 
 cin >> n; 
 for(int i=1 ;i<=n; i++)
  cin >> a[i], z += (a[i] == 0); 
 
 
 if(z == n)
  return void(cout << "0\n");
 
 
 ll ans = 0;  
 
 for(int i=1 ;i <=n; i++) if(a[i])
 {
  ans ++; 
  while(i <= n && a[i])
    i ++; 
  i --;
 }
 
 if(ans > 2) ans = 2; 
 
 cout << ans << '\n';
} 
 
 
int main()
{
    test
  solve();
}
 
 
 