#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
ll n, sm, k;
multiset<ll, greater<ll>> st, my;  
 
void solve()
{
 st.clear(), my.clear(); 
 cin >> n; 
 sm = 0; 
 for(int i=0 ; i<n ; i++)
  cin >> k, 
  sm += k,
  st.insert(k); 
  
 my.insert(sm);
 
 while(my.size() && *my.begin() >= *st.rbegin() && my.size() <= st.size())
 {
  ll p = *my.begin(); 
  my.erase(my.begin()); 
  
  if(p == 1) 
  {
   my.insert(1);
   break;  
  } 
  if(st.count(p))
   st.erase(st.find(p)); 
  else 
  {
   if(p&1)
    my.insert(p/2), my.insert(p/2 + 1); 
   else
    my.insert(p/2), my.insert(p/2);  
  }  
 }
 
 answer(st == my);
}
 
 
int main()
{
    test
  solve();
}
 
 
 