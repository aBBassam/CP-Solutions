#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll n, m, nm, sm1, sm2, a[300100], b[300100]; 
 
int main()
{
 go;
    cin >> n; 
    for(int i=0 ; i<n; i++)
     cin >> a[i], 
     sm1 += a[i];
    
    cin >> m; 
    for(int i=0 ; i<m ; i++)
     cin >> b[i],
     sm2 += b[i];
     
    if(sm1 != sm2) 
     return cout << -1, 0; 
    
    int aI = 0, bI = 0, ans = 0; 
    sm1 = sm2 = 0; 
    
    while(aI < n)
    {
  ans ++;
  sm1 += a[aI++]; 
  
  while(sm1 != sm2)
   if(sm1 < sm2 || bI == m) sm1 += a[aI++]; 
   else sm2 += b[bI++];
 }
  
  cout << ans;    
}