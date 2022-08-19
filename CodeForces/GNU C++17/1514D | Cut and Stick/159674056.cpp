#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}
 
 
const int N = 300100; 
int n, q, a[N]; 
vector<int> adj[N]; 
 
int main()
{
    go; 
    cin >> n >> q; 
    for(int i=1 ; i<=n ;i++) cin >> a[i], adj[a[i]].push_back(i); 
  
    while(q --)
    {
        int l, r, maxRep = 0; cin >> l >> r;
 
        for(int j=0 ;j<30; j++)
        {
            int x = a[rand(l, r)];
            int rep = upper_bound(all(adj[x]), r) - lower_bound(all(adj[x]), l); 
            maxRep = max(maxRep,  rep); 
        }
 
        int len = r - l + 1; 
 
        if(maxRep > ceil(len / 2.0)) 
        {
            maxRep -= len - maxRep + 1; 
            cout << 1 + max(0, maxRep) << '\n'; 
        }
        else cout << 1 << '\n'; 
    }
}