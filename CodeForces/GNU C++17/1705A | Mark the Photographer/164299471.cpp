// Problem: A. Mark the Photographer
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/A
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
 
ll n, x, a[N]; 
multiset<ll> st; 
 
void solve( )
{
 st.clear(); 
 
 cin >> n >> x; 
 
 for(int i=1 ; i<= 2 * n; i++)
  cin >> a[i], 
  st.insert(a[i]); 
 
 sort(a + 1, a + 2 * n + 1);
 
 for(int i=n ;i >= 1; i--) if(st.count(a[i]))
 {
  st.erase(st.find(a[i]));  
  auto it = st.lower_bound(a[i] + x); 
  if(it ==  st.end()) return void(cout << "NO\n"); 
  st.erase(it);
 }
 
 cout << "YES\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 