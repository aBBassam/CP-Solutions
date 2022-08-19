#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int N = 100100; 
int v, k;
int n, q, col[N], ans[N]; 
vector<int> adj[N];
map<int, vector<pair<int, int>>> m; 
 
o_set<pair<int, int>> stt; 
 
 
 
struct Node
{
    o_set<pair<ll, ll>> st; 
    map<ll,ll> colors;
};
 
 
Node* Merge(Node* bigNode, Node* smallNode)
{
    if(bigNode->colors.size() < smallNode->colors.size()) swap(bigNode, smallNode);
    
    auto temp = bigNode; // copy big node with O(1) because we are using pointers
    
    for(auto it : smallNode->colors)
    {
  temp->st.erase({temp->colors[it.F], it.F});
        temp->colors[it.F] += it.S; 
        temp->st.insert({temp->colors[it.F], it.F});
    }
    
    
    return temp; 
}
 
 
 
Node* GetNode(int node)
{
    auto nw = new struct Node;
    
    nw->colors[col[node]] = 1; 
    nw->st.insert({1, col[node]});
    
    return nw; 
}
 
 
Node* Dfs(int node, int par)
{
    auto bigNode = GetNode(node); 
    for(auto nd : adj[node]) if(nd != par)
        bigNode = Merge(bigNode, Dfs(nd, node));
    
 
    for(auto it : m[node])
     ans[it.S] = bigNode->colors.size() - (bigNode->st.lower_bound({it.F, -1}) == bigNode->st.end() ? bigNode->colors.size() : bigNode->st.order_of_key(*bigNode->st.lower_bound({it.F, -1})));
        
    return bigNode; 
}
 
 
 
 
 
 
 
int main()
{
 go; 
 // input
 cin >> n >> q; 
 for(int i=1 ;i<=n;i ++) cin >> col[i]; 
   for(int i=2, a, b; i<=n;i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
   for(int i=1 ;i <=q; i++) cin >> v >> k, m[v].push_back({k, i});
    
   Dfs(1, 0);
   
   for(int i=1 ; i <= q ; i++) cout << ans[i] << '\n';
}