#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n; 
string s; 
 
int chk(int nas)
{
 int mx = 0; 
 
 for(int i=0 ; i<=n; i++)
 {
  mx = max(mx, nas);
  
  if(nas < 0) return -1; 
  if(i == n) return mx; 
   
  (s[i] == '+') ? nas ++ : nas -- ;
 }
}
 
 
int main()
{
 cin >> s, n = s.length(); 
 
  for(int nas = 0 ; nas <= n + 10 ; nas ++)
  if(chk(nas) != -1) return cout << chk(nas), 0; 
}