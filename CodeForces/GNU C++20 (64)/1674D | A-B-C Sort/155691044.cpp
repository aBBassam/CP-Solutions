// Problem: D. A-B-C Sort
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/D
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
int n, a[N];
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ;i<=n; i++) cin >> a[i]; 
 
 for(int i=n-1 ; i>0; i-=2)
  if(a[i] > a[i + 1]) 
   swap(a[i], a[i + 1]);  
 
 for(int i=2 ; i<=n;  i++)
  if(a[i] < a[i - 1]) 
   return void(cout << "NO\n");
    
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 