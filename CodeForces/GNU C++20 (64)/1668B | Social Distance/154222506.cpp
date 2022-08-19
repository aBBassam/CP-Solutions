#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 100100; 
ll  n, m, a[N]; 
 
 
void solve()
{
 cin >> n >> m; 
 for(int i=1 ; i<=n ;i++) cin >> a[i]; 
 sort(a + 1, a + n + 1); 
 ll ans = 0; 
 
 for(int i=1 ; i<=n ;i++)
 {
  ll lft = a[i]; 
  ll rit = a[i]; 
 
  if(i != 1) lft = a[i] - a[i - 1]; 
  else rit = 0;
  
  ans += rit + lft + 1; 
 }
 
 answer(ans <= m); 
}
 
 
int main()
{
    test
  solve();
}