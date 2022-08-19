// Problem: F. 3SUM
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/F
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
ll n, a[N], rem[100]; 
 
 
void solve()
{
 cin >> n; 
 for(int i=0 ;i<=9 ; i++)rem[i] = 0; 
 for(int i=1 ;i<=n ; i++)
  cin >> a[i], 
  rem[a[i] % 10] ++;
 
 int ans = 0; 
   
 for(int i=0 ;i<=9 ; i++)
  for(int j=i + 1 ;j<=9 ; j++)
   for(int k=j + 1 ;k<=9 ; k++)
    if(rem[i] && rem[j] && rem[k])
    {
     int sm = i + j + k;
     ans |= ((sm % 10) == 3);
    }
    
 for(int i=0 ;i<=9 ; i++) if(rem[i] > 1)
 {
  int sm = i * 2; 
  sm %= 10; 
  
  if(sm <= 3)
  {
   if((3 - sm) == i)
   {
    if(rem[i] > 2)
     ans |= rem[3 - sm];
   }
   else 
    ans |= rem[3 - sm];
  }
  else 
  {
   if((13 - sm) == i)
   {
    if(rem[i] > 2)
     ans |= rem[13 - sm];
   }
   else 
    ans |= rem[13 - sm];
  }
 }
 
 answer(ans || (rem[1] >= 3));
}
 
 
int main()
{
    test
  solve();
}
 
 
 