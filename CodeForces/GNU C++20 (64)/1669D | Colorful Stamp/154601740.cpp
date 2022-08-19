// Problem: D. Colorful Stamp
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/D
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
 
const int N = 100100; 
int n; 
string s; 
vector<int> rep; 
 
bool fn(int st, int en)
{
 if(en - 1 == st) return 1; 
 st ++; 
 en --;
 if(en == st) return 0; 
 
 int bl = 0, rd = 0; 
 
 for(int i = st ; i<=en ; i++)
  bl += s[i] == 'B', 
  rd += s[i] == 'R'; 
  
 return bl && rd; 
}
 
 
void solve()
{
 cin >> n >> s; 
 s = 'W' + s + 'W'; 
 
 rep.clear(); 
 n = s.length(); 
 s = '&' + s; 
 for(int i=1 ; i<=n ;i++) if(s[i] == 'W')
  rep.push_back(i); 
 
  
 bool ans = 1; 
 int m = rep.size(); 
 
 for(int i=0 ; i<m -1 ; i++)
  ans &=  fn(rep[i], rep[i + 1]); 
 
 answer(ans); 
}
 
 
int main()
{
    test
  solve();
}
 
 
 