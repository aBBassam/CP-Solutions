// Problem: A. Tokitsukaze and All Zero Sequence
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/0
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
 
 
const int N = 1010; 
int n, a[N]; 
map<int, int> mp; 
 
 
void solve()
{
 mp.clear(); 
 int zero = 0 ; 
 
 cin >> n; 
 for(int i=1 ;i <=n ; i ++)
   cin >> a[i], mp[a[i]] ++; 
 
 int same = 0; 
 
 zero = mp[0]; 
 for(auto it : mp)
  if(it.S > 1) 
   same = 1; 
 
 if(zero > 0) cout << n - zero; 
 else if(same) cout << n; 
 else cout << n + 1; 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 