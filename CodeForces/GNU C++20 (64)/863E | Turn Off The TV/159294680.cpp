#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
 
const int N = 12 * 1e5; 
int n, sum[N], begs[N], endss[N]; 
 
set<int> endsForBeg[N], points;
 
vector<pair<int, int>> v;  
vector<int> ones;
 
map<int, int> compress;
map<pair<int, int>, int> id;  
 
 
 
 
 
 
int32_t main()
{
    go;
    cin >> n; 
    v.resize(n);
    for(auto &it : v)   
    {
        cin >> it.F >> it.S, 
        points.insert(it.F), 
        points.insert(it.S), 
        points.insert(it.F + 1), 
        points.insert(it.S + 1); 
 
        if(it.S)    
            points.insert(it.S - 1); 
        
        if(it.F)
            points.insert(it.F - 1); 
    }
 
    int cmp = 1; 
    for(int p : points)
        compress[p] = cmp ++; 
 
    int ID = 1; 
    for(auto &it : v)
        it.F = compress[it.F], it.S = compress[it.S], 
        endsForBeg[it.F].insert(it.S), 
        id[{it.F, it.S}] = ID++,
        begs[it.F] ++, 
        endss[it.S] ++; 
    
    int k = 0; 
    for(int i=1 ; i<=cmp ; i++)
    {
        k += begs[i]; 
        sum[i] = k;
        k -= endss[i]; 
    }
 
    for(int i=1 ; i<=cmp ; i++) if(sum[i] <= 1) ones.push_back(i); 
 
    for(int i=1 ;i <=cmp ; i++) if(sum[i] > 1 && !endsForBeg[i].empty())
    {
        int nxt = *upper_bound(all(ones), i);   
        if(*endsForBeg[i].begin() < nxt)
            return cout << id[{i, *endsForBeg[i].begin()}], 0;  
    }
 
    cout << -1; 
}