// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/C
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
 
 
const int N =  100100; 
ll n, a[N]; 
 
ll sl1()
{
 ll ret = 0; 
 for(int i = 2 ; i<= n ; i+= 2)
 {
  ll sm = max(a[i - 1], a[i + 1]); 
  if(sm >= a[i])
   ret += sm - a[i] + 1; 
 }
 return ret; 
}
 
 
 
 
ll dp[N][2]; 
 
 
 
ll sl(int i, int used)
{
 if(i >= n) return 0; 
 ll &ret = dp[i][used]; 
 if(ret + 1) return ret;   
 
 ll costHere = 0; 
 ll k = max(a[i - 1], a[i + 1]); 
 if(k >= a[i])
  costHere = k - a[i] + 1; 
  
 ret = costHere + sl(i + 2, used); 
 if(!used)
  ret = min(ret, sl(i + 1, 1));
  
 return ret; 
}
 
 
void solve( )
{
 cin >> n; 
 for(int i =1 ;i <=n; i++)
  cin >> a[i], 
  dp[i][0] = dp[i][1] = -1; 
 
 if(n&1) cout << sl1() << '\n';  
  else cout << sl(2, 0) << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 