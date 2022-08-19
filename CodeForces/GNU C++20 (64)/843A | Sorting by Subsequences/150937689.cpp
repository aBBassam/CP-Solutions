#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 100100; 
int n, a[N], b[N]; 
map<int, int> reall, tmm; 
vector<vector<int>> ans; 
vector<int> ret; 
 
void dfs(int ind)
{
 tmm[ind] = 1; 
 ret.push_back(ind); 
 
 if(!tmm[reall[a[ind]]])
  dfs(reall[a[ind]]);
}
 
int main()
{
 cin >> n; 
 for(int  i=0 ; i<n; i++) cin >> a[i],  b[i] = a[i];
 sort(b, b + n);
 for(int i=0 ; i<n; i++) reall[b[i]] = i; 
 
 for(int i=0 ; i<n ; i++) if(!tmm[i])
 {
  ret.clear();
  dfs(i);
  ans.push_back(ret);
 }
 
 
 cout << ans.size() << '\n'; 
 for(auto it : ans) 
 {
  cout << it.size() << ' '; 
  for(int i : it) cout << i + 1 << ' '; 
  cout << '\n';
 }
}