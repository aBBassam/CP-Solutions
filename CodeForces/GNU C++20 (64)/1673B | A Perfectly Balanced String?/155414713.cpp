// Problem: B. A Perfectly Balanced String?
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/B
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
int  n; 
string s; 
ll pre[50][N];
vector<int> pos[50];  
set<char> cs; 
 
void solve()
{
 cin >> s; 
 n = s.length(); 
 s = '&' + s; 
 
 cs.clear();
 for(int i=0 ; i<50 ; i++) 
  pos[i].clear(); 
 for(int i=1 ; i<=n; i++)
  pos[s[i] - 'a'].push_back(i), 
  cs.insert(s[i]);
  
 for(char c = 'a' ; c <= 'z' ; c++)
  for(int i=1 ; i<=n; i++)
   pre[c - 'a'][i] = pre[c - 'a'][i - 1] + (s[i] == c);
 
 for(char c = 'a' ; c <= 'z' ; c++) if(pos[c - 'a'].size() > 1)
 {
  int m = pos[c - 'a'].size(); 
  for(int i=0 ; i<m - 1 ; i++)
  {
   int s = pos[c - 'a'][i]; 
   int e = pos[c - 'a'][i + 1]; 
  
   for(char cr : cs) if(cr != c)
   {
    if(pre[cr - 'a'][e] - pre[cr - 'a'][s - 1] == 0)
     return void(cout << "NO\n");
   } 
  }
 }
 
 
 
 cout << "YES\n"; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 