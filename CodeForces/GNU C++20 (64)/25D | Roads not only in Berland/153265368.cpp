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
int n, Parent[N]; 
vector<pair<int, int>> rem;
 
int root(int x)
{
   return  (x == Parent[x]) ? x : Parent[x]=root(Parent[x]);
}
void merge (int x,int y)
{
    if(root(x) != root(y))
        Parent[root(x)]=root(y);
}
 
int main()
{
 cin >> n; 
   for(int i=1 ;i<=n; i++) Parent[i] = i; 
   
   for(int i=2, u, v ; i<=n; i++)
   {
    cin >> u >> v; 
    if(root(u) == root(v)) rem.push_back({u, v}); 
    else merge(u, v); 
   }
   
   vector<int> nodes; 
   for(int i=1 ; i<=n; i++) if(Parent[i] == i)
    nodes.push_back(i); 
    
    
   cout << nodes.size() - 1 << '\n';
    
   int remI = 0; 
   for(int i=1, n = nodes.size() ; i<n; i++)
    cout << rem[remI].F << ' ' << rem[remI].S << ' ', 
    remI ++,
    cout << nodes[i] << ' ' << nodes[i - 1] << '\n';
}