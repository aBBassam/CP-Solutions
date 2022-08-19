#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n, a[200100], b[200100]; 
map<int, bool> exi;
 
 
int main()
{
    cin >> n;  
 for(int i=1 ; i<=n ;i++) cin >> a[i], exi[a[i]] = 1;
 for(int i=1 ; i<=n ;i++) cin >> b[i];
 
 int on = 1; 
 
 for(int i=1 ; i<=n ;i++)
 {
  int ans = 0; 
  if(!exi[b[i]]) 
  {
   cout << "0 "; 
   continue;
  }
  
  while(a[on] != b[i])
   exi[a[on]] = 0, on ++, ans ++ ;
  
  exi[a[on++]] = 0; 
  cout << ++ans << ' ';
 }
}