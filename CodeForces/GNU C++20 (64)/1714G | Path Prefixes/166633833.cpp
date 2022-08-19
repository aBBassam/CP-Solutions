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
ll n, A[N], B[N], ans[N]; 
vector<int> adj[N]; 
vector<ll> v; 
 
 
 
void dfs(int node, ll smOfB = 0, ll smOfA = 0,ll h = 0)
{
 smOfA += A[node]; 
 smOfB += B[node]; 
 v.push_back(smOfA); 
 
 
 int n = v.size(), st = 0, en = n - 1; 
 int anss = 0; 
 
 while(st <= en)
 {
  int mid = (st + en) / 2; 
  if(v[mid] <= smOfB) ans[node] = mid , st = mid + 1; 
  else en = mid - 1; 
 }
 
 for(int nd : adj[node])
  dfs(nd, smOfB, smOfA, h + 1); 
 
 v.pop_back(); 
}
 
 
 
void solve()
{
 v.clear(); 
 cin >> n; 
 for(int i=2, p ;i <=n; i++)
  cin >> p >> B[i] >> A[i], 
  adj[p].push_back(i); 
 
 dfs(1);  
 
 
 for(int i=2  ;i <=n; i++) cout << ans[i] << ' ', adj[i].clear(), ans[i] = 0; 
 adj[1].clear();
 cout << '\n';
}
 
 
int main()
{
 test 
  solve(); 
}
 
 