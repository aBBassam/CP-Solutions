// Problem: B. Stone Age Problem
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
ll n, q; 
map<int, ll> val; 
 
 
 
 
int main()
{
 ll sm = 0; 
 cin >> n >> q; 
 for(int i=1 ;i <=n; i++)
 {
  ll nm; cin >>nm; 
  sm += nm; 
  val[i] = nm; 
 }
 
 ll al = 0; 
 while(q--)
 {
  ll t; cin >> t; 
  if(t == 1)
  {
   ll ind, value; cin >> ind >> value; 
   
   if(val.count(ind) != 0)
   {
    sm += value - val[ind]; 
    val[ind] = value; 
   }
   else 
   {
    sm += value - al;
    val[ind] = value; 
   }
  }
  else 
  {
   ll value; cin >> value; 
   val.clear(); 
   sm = n * value; 
   al = value; 
  }
  
  cout << sm << '\n'; 
 }
}
 
 
 