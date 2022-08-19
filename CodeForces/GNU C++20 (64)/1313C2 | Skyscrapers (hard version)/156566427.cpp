#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 500100; 
ll n, a[N], b[N], toR[N], toL[N], x;  
stack<pair<ll, int>> st;  // to find first number smaller than me 
 
int main()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i];
 
 for(int i=n ; i>0 ; i--)
 {
  while(!st.empty() && a[i] <= st.top().F) st.pop(); 
  
  if(st.empty()) toR[i] = (n - i + 1) * a[i];// there is no smaller than you 
  else toR[i] = toR[st.top().S] + (st.top().S - i) * a[i];
  
  st.push({a[i], i});
 } 
 
 while(!st.empty()) st.pop(); 
 
 for(int i=1 ; i<=n ; i++)
 {
  while(!st.empty() && a[i] <= st.top().F) st.pop(); 
  
  if(st.empty()) toL[i] = i * a[i];// there is no smaller than you 
  else toL[i] = toL[st.top().S] + (i -  st.top().S) * a[i];
  
  st.push({a[i], i});
 } 
 
 
 ll ans = -1, ind;
 for(int i=1 ;i <=n; i++)
 {
  ll l_ans = toR[i] + toL[i] - a[i]; 
  if(l_ans > ans)
   ans = l_ans, ind = i; 
 }
 
 // print the answer if the f(ind) is maximal possible : 
 b[ind] = a[ind]; 
 ll x = a[ind]; 
 for(ll i=ind + 1; i<=n; i++)
 {
  x = min(x, a[i]); 
  b[i] = x;  
 }
 
 x = a[ind];
 for(ll i=ind - 1; i>0; i--)
 {
  x = min(x, a[i]); 
  b[i] = x; 
 }
 
 for(ll i=1 ;i <=n; i++) cout << b[i] << ' ';  
}