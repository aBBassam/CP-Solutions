#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll x, y; 
 
void solve()
{
 cin >> x >> y; 
 if(max(x, y) == 0) cout << "0\n"; 
 else 
 {
  ll undr = x * x + y * y; 
  ll div = sqrt(undr); 
  if(div * div == undr ) cout << "1\n"; 
  else cout << "2\n"; 
 }
}
 
 
int main()
{
    test
  solve();
}
 
 
 