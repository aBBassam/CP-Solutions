// Problem: B. ICPC Balloons
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/B
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
 
 
 
set<char> st; 
 
 
void solve( )
{
st.clear(); 
 
string s; 
int n; 
cin >> n >> s; 
int ans = 0; 
for(int i=0 ; i<n ; i++)
{
 ans += 1 + (st.count(s[i]) == 0);
 st.insert(s[i]);
}
 
 cout << ans << '\n';
 
 
}
 
 
int main()
{
    test
  solve();
}
 
 
 