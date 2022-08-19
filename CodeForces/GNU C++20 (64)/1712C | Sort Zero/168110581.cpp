// Problem: C. Sort Zero
// Contest: Codeforces - Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/C
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
ll n, a[N], lst[N],suf[N]; 
set<ll> st;  
 
 
 
void solve()
{
 st.clear(); 
 cin >> n; 
 for(int i=1 ;i<=n; i++)
  cin >> a[i], lst[a[i]] = i;
  
  
 suf[n] = 1; 
 for(int i=n-1 ; i>0 ; i--)
  suf[i] = suf[i + 1] & (a[i] <= a[i + 1]); 
 
  
 ll ans = n, bgrThan = 0; 
 
 
 for(int i=1 ;i <=n;i++)
 {
  if(suf[i])
  {
   if(i >= bgrThan)
   {
    ans =  st.size(); 
    break;
   }
   else 
   {
    st.insert(a[i]); 
    bgrThan = max(bgrThan, lst[a[i]]); 
   }
  }
  else  
  {
   st.insert(a[i]); 
   bgrThan = max(bgrThan, lst[a[i]]);  
  } 
 }
 
 
 
 cout << ans << '\n'; 
 for(int i=1 ;i <=n; i ++)
  lst[i] = 0; 
}
 
 
int main()
{
 test 
  solve(); 
}
 
 