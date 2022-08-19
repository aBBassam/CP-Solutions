#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
int n, m; 
set<pair<int, int>> black, allBlack; 
vector<pair<pair<int, int>,pair<int, int>>> ans;
char c; 
 
void solve( )
{
 cin >> n >> m; 
 black.clear(), ans.clear();
 allBlack.clear();
 
 for(int i=1 ; i<=n ; i++)
  for(int j=1 ; j<=m ; j++)
  {
   cin >> c; 
   if(c == '1')
    black.insert({-i, -j});
  }
 
 for(auto it : black)
 {
  if(-it.F - 1 > 0 && allBlack.count({-it.F - 1, -it.S}) == 0)
   ans.push_back({{-it.F-1, -it.S}, {-it.F, -it.S}}); 
  else if(-it.S - 1 > 0 && allBlack.count({-it.F, -it.S - 1}) == 0)
   ans.push_back({{-it.F, -it.S-1}, {-it.F, -it.S}});
  else 
   return void(cout << "-1\n"); 
 
  allBlack.insert({-it.F, -it.S}); 
 }
 
  
 cout << ans.size() << '\n'; 
 for(auto it : ans)
  cout << it.F.F << ' ' << it.F.S << ' ' << it.S.F << ' ' << it.S.S << '\n'; 
 
 
}
 
 
int main()
{
    test
  solve();
}
 
 
 