// Problem: A. Red Versus Blue
// Contest: Codeforces - Codeforces Round #782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/0
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
 
 
int n, r, b; 
string ans; 
int ar[100];
 
 
void solve()
{ 
 
 
 ans = ""; 
 cin >> n >> r >> b; 
 
 int k = b + 1;
 
 
 for(int i=0 ; i<k ; i++)
  ar[i] = 0; 
  
 while(r)
 {
  for(int i=0 ; i<k ; i++) if(r)
   r--, ar[i] ++; 
 } 
 
 for(int i=0 ; i<k ;i ++)
 {
  for(int j=0 ; j<ar[i] ; j++)
   cout << 'R'; 
  
  if(b)
   b--, cout << 'B';
 }
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 