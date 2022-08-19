// Problem: B. All Distinct
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/B
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
ll n, a[N]; 
map<int, int> cnt; 
 
 
void solve( )
{
 cnt.clear(); 
 cin >> n; 
 for(int i=1 ;i <= n; i++)
  cin >> a[i], 
  cnt[a[i]] ++ ; 
 
 int rem = 0; 
 for(auto it : cnt)
  if(it.S % 2 == 0) rem ++; 
 
 cout << cnt.size() - (rem & 1) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 