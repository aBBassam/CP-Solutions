#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 10010; 
ll n, m, a[N]; 
 
 
void solve( )
{
 ll other = 0; 
 cin >> n >> m;  
 ll fr; cin >> fr; 
 
 
 for(int i=2 ; i<=n; i++)
 {
  ll k;cin >> k; 
  other += k; 
 }
 
 cout << fr + min(other, m - fr) << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 