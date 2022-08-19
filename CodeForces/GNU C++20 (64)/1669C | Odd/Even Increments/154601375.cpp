// Problem: C. Odd/Even Increments
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/C
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
 
 
const int N = 100; 
int n, a[N]; 
 
void solve()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 
 for(int i=3 ; i<=n ;i++)
  if((a[i] % 2) != (a[i - 2] % 2))
   return void(cout << "NO\n");
    
 for(int i=4 ; i<=n ;i++)
  if((a[i] % 2) != (a[i - 2] % 2))
   return void(cout << "NO\n"); 
   
 cout << "YES\n";
} 
 
 
int main()
{
    test
  solve();
}
 
 
 