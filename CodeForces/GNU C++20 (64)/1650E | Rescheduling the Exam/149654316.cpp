#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
 
int n, ai, d; 
set<int> st, s; 
 
 
bool tryy(int remv, ll df)
{
 s = st; 
 s.erase(remv); 
 
 int mn = 1e9 + 7, mx = 0, lst = 0; 
 for(int i : s) if(i && i != d + 1)
  mn = min(mn, i - lst - 1),
  mx = max(mx, i - lst - 1),
  lst = i; 
 
 mx = max(mx, d - lst);
 
 
 return mn >= df && (mx - 1 >= df * 2 || d - lst - 1 >= df); 
}
 
 
bool chk(ll df)
{
 s = st; 
 int lst = 0, remv = 0, remv2 = 0; 
 
 for(int i : s) if(i && i != d + 1)
 {
  if(i - lst - 1 < df && !remv)
  { 
   remv = i; 
   if(lst)
    remv2 = lst;  
  }
  lst = i; 
 }
 
 bool ret = remv == 0;
 if(remv) ret |= tryy(remv, df); 
 if(remv2) ret |= tryy(remv2, df);
 
 return ret; 
}
 
int main()
{
 test
 {
  st.clear();
  cin >> n >> d; 
  for(int i=0 ; i<n ; i++) 
   cin >> ai, 
   st.insert(ai);
  
  st.insert(0), st.insert(d + 1); 
 
  ll st = 1, en = 1e9, ans = 0; 
  while(st <= en)
  {
   ll mid = (st + en) / 2; 
   if(chk(mid)) ans = mid, st = mid + 1; 
   else en = mid - 1; 
  }
  
  cout << ans << '\n';
 }
}