#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
ll n, a[100100], z; 
 
int main()
{
 test
 {
  cin >> n, z = 0; 
  for(int i=0 ; i<n; i++)
   cin >> a[i], 
   z += a[i] == 0; 
  
  sort(a, a + n); 
  
  ll sm = 0; 
  for(int i=0 ; i<n-1 ; i++)
   sm += a[i];
  
  ll mx = a[n-1];
  
  if(z == n) cout << "0\n"; 
  else if(mx > sm) cout << mx - sm << '\n'; 
  else cout << "1\n";
 }
}