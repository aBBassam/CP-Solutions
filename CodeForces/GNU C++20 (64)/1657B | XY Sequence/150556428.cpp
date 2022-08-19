#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll n, B, x, y; 
 
 
void solve( )
{
 cin >> n >> B >> x >> y; 
 
 ll sm = 0; 
 ll nm = 0; 
 
 for(int i=0 ; i<=n ;i++)
 {
  sm += nm; 
  nm += x; 
  if(nm > B) nm -= x + y; 
 }
 
 cout << sm << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 