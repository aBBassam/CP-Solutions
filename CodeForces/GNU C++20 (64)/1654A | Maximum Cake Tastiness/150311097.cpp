#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
int n; 
multiset<ll, greater<ll>>st; 
 
void solve( )
{
 st.clear();
 cin >> n ;
 for(ll i=0,k ; i<n; i++)
  cin >> k,
  st.insert(k); 
  
 ll ans = *st.begin(); 
 st.erase(st.begin());
 cout << ans + *st.begin() << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 