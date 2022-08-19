// Problem: C. Tree Infection
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/C
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
int n;  
vector<int> adj[N]; 
vector<int> groups; 
multiset<int, greater<int>> st; 
 
 
void solve( )
{
 cin >> n; 
 for(int i=0 ; i<=n ; i++) adj[i].clear(); 
 groups.clear(), st.clear(); 
 
 
 
 for(int i=2 ,anc; i<=n ; i++)
  cin >> anc,  adj[anc].push_back(i); 
  
 for(int i=1 ; i<=n ;i++)
  if(adj[i].size() > 0) groups.push_back(adj[i].size()); 
 groups.push_back(1);
 sort(all(groups)); 
 
 int m = groups.size(); 
 int ans = m;
 
 for(int i=0 ; i<m ;i++) groups[i] -= i + 1;
 for(int i=0 ; i<m ; i++) if(groups[i] > 0) st.insert(groups[i]); 
 
 int rem = 0; 
 while(st.size() > 0 && (*st.begin()) - rem > 0)
 {
  rem ++, ans ++; 
  int nm = *st.begin();  
  st.erase(st.begin()); 
  
  if(nm - 1 > 0) st.insert(nm - 1);
 }
 
 cout << ans << '\n'; 
}
 
 
int main()
{
    test
  solve();
}