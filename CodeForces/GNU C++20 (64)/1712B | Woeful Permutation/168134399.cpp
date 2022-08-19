// Problem: B. Woeful Permutation
// Contest: Codeforces - Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/B
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
 
 
ll gcd(ll a , ll b)
{
   return b == 0 ? a : gcd(b, a % b);
}
 
ll lcm(ll a , ll b)
{
   return (a*b)/gcd(a, b);
}
 
 
const int N = 200100; 
ll n, a[N]; 
    
    
void solve()
{
 cin >> n; 
 for(int i=1 ;i  <=n;i++)
  a[i] = i; 
  
  
 if(n%2 == 0)
 {
  for(int i=2 ;i <=n; i+=2)
   swap(a[i],  a[i - 1]); 
 }
 else 
 {
  for(int i=3 ;i <=n; i+=2)
   swap(a[i],  a[i - 1]); 
 }
    
 for(int i=1 ;i  <=n;i++)cout << a[i] << ' '; 
    
    
 cout << '\n'; 
}
 
 
int main()
{
 test 
  solve(); 
}
 
 