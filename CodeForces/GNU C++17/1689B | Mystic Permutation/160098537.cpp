// Problem: B. Mystic Permutation
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/B
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
 
 
 
const int N = 1010; 
ll n, a[N], b[N]; 
set<ll> st; 
 
 
void solve( )
{
 st.clear(); 
 cin >> n; 
 for(int i=1 ;i <= n ; i++) cin >> a[i], st.insert(a[i]); 
 
 if(n == 1)
  return void(cout << "-1\n");
 
 
 for(int i=1 ;i <n; i++)
 {
  int retAi = 0; 
  
  if(st.count(a[i]))
  {
   retAi = 1; 
   st.erase(a[i]);
  }
  
  b[i] = *st.begin(); 
  st.erase(st.begin());
  
  if(retAi)
  {
   st.insert(a[i]); 
  }
 }
 
 
 b[n] = *st.begin(); 
 
 if(b[n] == a[n]) 
  swap(b[n], b[n - 1]);
 
 for(int i=1 ;i <=n; i++)
  cout << b[i] << ' '; 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 