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
string s; 
ll n, p, sm; 
int rem[N]; 
set<pair<int, int>> stt; 
 
bool chk(int del)
{
 ll deleted = 0; 
 
 for(auto it : stt)
 {
  if(!del) break;
  deleted += it.F; 
  del --; 
 } 
 
 return (deleted + sm <= p);
}
 
 
void solve( )
{
 stt.clear();
 sm = 0; 
 cin >> s >> p; 
 n = s.length(); 
 s = "&" + s; 
 
 
 for(int i=1 ;i <=n;i++)
  rem[i] = 0, 
  sm += (s[i] - 'a'), 
  stt.insert({-((s[i] - 'a') + 1), i}); 
 
 sm += n;
  
 
  ll  st = 0, en = n, ans = n; 
 while(st <= en)
 {
  ll mid = (st + en) / 2; 
  if(chk(mid)) en = mid  -1, ans = mid; 
  else st = mid + 1; 
 }
 
 
 for(auto it : stt)
 {
  if(!ans) break;
  rem[it.S] = 1; 
  ans -- ;
 }
 
 
 for(int i=1 ;i <=n; i++)
  if(!rem[i])
   cout << s[i]; 
   
 cout << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 