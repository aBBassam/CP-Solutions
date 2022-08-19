// Problem: B. Shoe Shuffling
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/B
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
 
 
const int  N = 100100; 
ll n,  a[N]; 
map<ll, ll> rep; 
 
void solve( )
{
 rep.clear(); 
 cin >> n; 
 for(int i=1 ; i<=n;  i++) cin >> a[i], rep[a[i]]++; 
 
 for(auto it : rep)
  if(it.S == 1)
   return void(cout << "-1\n"); 
 
 for(int i=1 ;i <=n; i++)
 {
  ll val = a[i]; 
  int fr = i; 
  
  while(i<=n && a[i] == val)
   i++; 
  
  i --; 
  
  for(int j=fr + 1 ; j<=i ; j++)
   cout << j << ' ';
  cout << fr << ' ';
 }
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 