#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 5010; 
int n; 
string s; 
set<pair<string, int>>  st; 
 
void solve( )
{
 st.clear();
 cin >> n >> s;
 s = "&" + s;
 st.insert({s, 1}); 
 
 for(int k=2 ; k<=n; k++)
 {
  string ss = "&" + s.substr(k, n - (k - 1)); 
  string sss = s.substr(1, k - 1);
  
  if((n - k)%2==0) reverse(all(sss));
  st.insert({ss + sss, k});
 }
 
 reverse(s.begin() + 1, s.end());
 st.insert({s, n});
 
 
 auto it = st.begin(); 
 string ans = it->F; 
 
 for(int i=1 ; i<=n; i++) cout << ans[i];
 cout << '\n';
 cout << it->S << '\n';
}
 
 
int main()
{
    test
  solve();
}