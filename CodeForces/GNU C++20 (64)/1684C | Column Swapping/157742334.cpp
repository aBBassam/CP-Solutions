// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/C
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
int n, m; 
int ind1, ind2, a, b; 
vector<vector<int>> v, correct; 
 
 
bool failed()
{
 for(int i=1 ;i <=n; i++)
  swap(v[i][ind1], v[i][ind2]); 
 
 int ret = 0; 
 for(int i=1 ; i<=n; i++)
  for(int j=2 ; j<=m ;j ++)
   if(v[i][j] < v[i][j - 1])
    ret = 1; 
  
 for(int i=1 ;i <=n; i++)
  swap(v[i][ind1], v[i][ind2]); 
    
 return ret; 
}
 
void solve( )
{
 v.clear(); 
 cin >> n >> m ; 
 v.resize(n + 1);
 correct.resize(n + 1);
  
 for(int i=1 ;i <=n ;i++) v[i].resize(m + 1),  correct[i].resize(m + 1);
 for(int i=1 ;i<=n; i++)
  for(int j=1 ; j<=m ;j ++)
   cin >> v[i][j], correct[i][j] = v[i][j];
   
 for(int i=1 ;i <=n ; i++) sort(all(correct[i])); 
 
 
 for(int i=1 ;i <=n; i++)
 {
  vector<int> inds; 
  for(int j=1 ; j<=m ; j++)
   if(correct[i][j] != v[i][j])
    inds.push_back(j); 
    
  if(!inds.empty())
  {
   ind2 = inds.back(); 
   ind1 = inds[0]; 
   
   if(failed()) return void(cout << "-1\n"); 
   else return void(cout << ind1 << " " << ind2 << '\n');
  }
 }
 cout << "1 1\n";
}
 
 
int main()
{
    test
  solve();
}