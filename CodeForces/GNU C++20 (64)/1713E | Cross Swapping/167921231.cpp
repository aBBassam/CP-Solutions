// Problem: E. Cross Swapping
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/E
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
 
 
const int N = 1010; 
ll n, a[N][N], ans[N][N]; 
map<int, int> Parent; 
 
 
int root(int x)
{
   return (x == Parent[x]) ? x : Parent[x]=root(Parent[x]);
}
 
void merge1(int i, int j)
{
 if(root(-i) == root(j)) return; 
 
 if(root(i) != root(j))
  Parent[root(i)] = root(j); 
  
 if(root(-i) != root(-j))
  Parent[root(-i)] = root(-j); 
}
 
void merge2(int i, int j)
{
 if(root(i) == root(j) || root(-i) == root(-j)) return; 
 
 if(root(-i) != root(j))
  Parent[root(-i)] = root(j); 
 
 if(root(i) != root(-j))
  Parent[root(i)] = root(-j); 
}
 
 
 
 
 
void solve()
{
 Parent.clear(); 
 cin >> n; 
 for(int i=1 ; i <= n; i++)
  for(int j=1 ; j <= n ; j++)
   cin >> a[i][j], ans[i][j] = a[i][j]; 
  
 for(int i= - n - 10; i <= n + 10 ; i++) Parent[i] = i; 
 
 for(int i=1 ; i<=n ;i++)
  for(int j=1 ; j <=n ; j++)
   if(i != j)
   {
    if(a[i][j] < a[j][i]) // i & j same parity : 
     merge1(i, j);  
    else if(a[i][j] > a[j][i]) // i & j different  parity : 
     merge2(i, j);
   }
   
   
 for(int i=1 ; i<=n; i++)
  for(int j=1; j<=n; j++)
   if(root(i) == root(j)) 
    ans[i][j] = a[i][j]; 
   else 
    ans[i][j] = a[j][i]; 
 
 
 for(int i=1 ; i<=n ;i++)
 {
  for(int j=1 ; j <=n ; j++)
   cout << ans[i][j] << ' '; 
  cout << '\n'; 
 }
  
}
 
int main()
{
 test 
  solve(); 
}