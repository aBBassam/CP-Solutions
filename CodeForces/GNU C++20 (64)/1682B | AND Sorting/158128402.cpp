// Problem: B. AND Sorting
// Contest: Codeforces - Codeforces Round #793 (Div. 2)
// URL: https://codeforces.com/contest/1682/problem/B
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
ll a[N], b[N], n;
vector<ll> v; 
 
 
void solve()
{
 cin >> n; 
 for(int i=1 ;i<=n; i++) cin >> a[i], b[i] = a[i]; 
 sort(a + 1, a + n + 1); 
 // a is sorted 
 
 v.clear(); 
 for(int i=1 ; i<=n; i++)
  if(a[i] != b[i])
   v.push_back(a[i]);
 
 ll andd = v[0]; 
 for(ll i : v)
  andd &= i; 
 
 cout << andd << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 