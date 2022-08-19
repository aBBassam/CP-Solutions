#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll n; 
vector<ll> ans; 
 
 
 
void solve( )
{
 ans.clear(); 
 cin >> n; 
 
 ll nm = 1; 
 for(int i=1 ;i <=n ;i++)
 { 
  if(nm > 1e9) 
   return void(cout << "NO\n"); 
 
  ans.push_back(nm); 
  nm += 2 * nm; 
 }
 
 
 
 cout << "YES\n"; 
 for(ll nm : ans)
  cout << nm << ' '; 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 