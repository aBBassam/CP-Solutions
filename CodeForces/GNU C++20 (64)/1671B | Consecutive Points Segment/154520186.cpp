// Problem: B. Consecutive Points Segment
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/B
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
ll n, a[N], b[N]; 
 
bool solve(int ad)
{
 for(int i= 0 ; i<n ; i++)
  b[i] = a[i]; 
  
 b[0] += ad; 
 
 for(int i=1 ; i<n ;i++)
 {
  if(b[i] == b[i - 1])
   b[i] ++ ; 
  else if(b[i] > b[i - 1])
  {
   if(b[i] - b[i - 1] > 2) return 0; 
   if(b[i] - b[i - 1] == 2) b[i] --; 
  }
  else 
  {
   if(b[i - 1] - b[i] > 2) return 0; 
   if(b[i - 1] - b[i] == 2) b[i] ++; 
  }
 } 
 return 1; 
}
 
 
int main()
{
    test
 {
  cin >> n; 
  for(int i=0 ; i<n ;i++) cin >> a[i]; 
  answer(solve(1) || solve(-1) || solve(0));
 }
}
 
 
 