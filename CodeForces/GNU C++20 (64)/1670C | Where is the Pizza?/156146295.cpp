#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
ll fstPO(ll x, ll y, ll m = 1e9 + 7) {
  ll res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i)
      res = res * x % m;
  return res;
}
 
 
const int N = 200100; 
int n, a[N], b[N], c[N]; 
int vis[N]; 
set<int> locked, nxt[N]; 
 
 
int f(int node)
{
 int ret = 0; 
 vis[node] = 1;   
 for(int k : nxt[node]) if(!vis[k]) ret += 1 + f(k); 
 return ret; 
}
 
void solve()
{
 cin >> n; 
 for(int i =1 ; i<=n; i++) cin >> a[i]; 
 for(int i =1 ; i<=n; i++) cin >> b[i]; 
 for(int i =1 ; i<=n; i++) cin >> c[i]; 
 for(int i =1 ; i<=n; i++) if(a[i] == b[i]) c[i] = a[i]; 
 for(int i =1 ; i<=n; i++) nxt[a[i]].insert(b[i]), nxt[b[i]].insert(a[i]); 
 for(int i =1 ; i<=n; i++) if(c[i]) locked.insert(c[i]); 
 for(int i : locked) if(!vis[i]) f(i); 
 
 
 int ans = 0; 
 
 for(int i=1 ; i<=n ;i++) if(!vis[i])
 {
  int k = 1 + f(i); 
  if(k > 1)
   ans ++; 
  }
 
 cout << fstPO(2, ans) << '\n'; 
 locked.clear(); 
 for(int i=0 ; i<=n ;i ++)
  vis[i] = 0, nxt[i].clear(); 
}
 
 
int main()
{
    test
  solve();
}