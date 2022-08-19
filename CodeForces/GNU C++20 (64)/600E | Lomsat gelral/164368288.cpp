#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define F first
#define S second
using namespace std;
 
const int N = 100100; 
int n, a[N], ans[N]; 
vector<int> adj[N];
 
 
struct Node
{
 
 
 
 
 // info needed for each node : 
    map<ll,ll> colors;
    ll biggestRepetition = 0; 
    ll smOfDoms = 0;
};
 
 
Node* Merge(Node* bigNode, Node* smallNode)
{
 if(bigNode->colors.size() < smallNode->colors.size()) swap(bigNode, smallNode);
 
 auto temp = bigNode; // copy big node with O(1) because we are using pointers
 
 for(auto it : smallNode->colors)
 {
 
  temp->colors[it.F] += it.S; 
  int newRep = temp->colors[it.F];
  if(newRep > temp->biggestRepetition)
   temp->biggestRepetition = newRep, 
   temp->smOfDoms = it.F;
  else if(newRep == temp->biggestRepetition)  
   temp->smOfDoms += it.F;
 }
 
 
 return temp; 
}
 
 
 
Node* GetNode(int node)
{
 
 
 
 
 
 
  // initilize a node : 
 auto nw = new struct Node;
 
 nw->colors[a[node]] ++; 
 nw->biggestRepetition = 1; 
 nw->smOfDoms = a[node]; 
 
 return nw; 
}
 
 
Node* Dfs(int node, int par)
{
 auto bigNode = GetNode(node); 
 for(auto nd : adj[node]) if(nd != par)
  bigNode = Merge(bigNode, Dfs(nd, node));
 
 
 
 
 
 ans[node] = bigNode->smOfDoms; // merged -> do your buisness
 
 return bigNode; 
}
 
 
 
 
 
 
 
int32_t main()
{
 cin >> n; 
 for(int i=1 ;i <=n; i++) cin >> a[i]; 
 
 for(int i=1, a, b ; i<n; i++)
  cin >> a >> b, 
  adj[a].push_back(b), 
  adj[b].push_back(a); 
 
 Dfs(1, 0);
 
 for(int i=1 ;i <=n; i ++)
  cout << ans[i] << ' ';
}
 
 
 