// Problem: C. 3SUM Closure
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/C
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
ll n, a[N]; 
 
 
 
bool chk()
{
 map<ll, bool > mp; 
 for(int i=1  ; i<=n; i++) mp[a[i]] =1;
 
 for(int i=1 ; i<=n; i++)
  for(int j=i+1 ; j<=n; j++)
   for(int k=j + 1; k <= n; k++)
    if(!mp[a[i] + a[j] + a[k]])
     return 0; 
 return 1; 
}
 
 
 
void solve( )
{
 ll z= 0; 
 cin >> n; 
 for(int i=1 ;i <=n ;i++) cin >> a[i], z += (a[i] == 0); 
 
 if(n <= 4) return void(answer(chk())); 
 
 sort(a + 1, a + n + 1); 
 if(z >= (n - 1) || ((z == (n - 2)) && (a[1] == (-a[n])))) return void(cout << "YES\n"); 
 cout << "NO\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 