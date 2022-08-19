#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
int n, a[110]; 
 
int main()
{ 
 test
 {
  cin >> n; 
  for(int i=0 ; i<n; i++) cin >> a[i];
  
  int st = 0; 
  while(a[st + 1] == 1 && st + 1 < n) st ++ ; 
  
  int en = n-1; 
  while(a[en - 1] == 1 && en - 1 >= 0) en --; 
  
  cout << max(0, en - st) << '\n';
 }
}