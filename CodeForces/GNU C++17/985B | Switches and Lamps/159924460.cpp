#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 2010; 
int n, m, a[N];
vector<string> v; 
 
 
int main()
{   
    cin >> n >> m; 
    for(int i=0 ; i<n; i++)
    {
        string s; cin >> s; 
 
        for(int j=0 ; j<m ;j ++)
            if(s[j] == '1') a[j] ++ ; 
        
        v.push_back(s);
    }
 
    int ys = 0; 
 
    for(int i=0 ; i<n ;i++)
    {
        int allRem = 1; 
 
 
        for(int j=0 ; j<m ; j++)
            if(v[i][j] == '1') a[j] --; 
        
        for(int j=0 ; j<m ;j++)
            allRem &= a[j] > 0; 
        
        for(int j=0 ; j<m ; j++)
            if(v[i][j] == '1') a[j] ++;
 
         ys |= allRem;
    }
 
    answer(ys); 
}