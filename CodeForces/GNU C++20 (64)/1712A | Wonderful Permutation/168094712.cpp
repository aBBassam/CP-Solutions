// Problem: A. Wonderful Permutation
// Contest: Codeforces - Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/0
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
 
 
const int N = 1010; 
ll n, a[N], b[N], k; 
set<ll> st; 
 
 
void solve()
{
 st.clear(); 
 cin >> n >> k; 
 for(int i=1 ;i<=n; i++) cin >> a[i], b[i] = a[i]; 
 
 sort(b + 1, b + n + 1); 
 
 for(int i=1 ;i <=k; i++)st.insert(b[i]); 
 
 int ans = 0;
 
 for(int i=k+1 ;i <=n; i++)
  if(st.count(a[i])) 
   ans ++; 
  
 
 cout << ans << '\n';
}
 
 
int main()
{
 test 
  solve(); 
}
 
 