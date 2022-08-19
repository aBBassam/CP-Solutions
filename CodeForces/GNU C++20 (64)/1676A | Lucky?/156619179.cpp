// Problem: A. Lucky?
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/0
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
 
 
string s; 
int n; 
 
void solve( )
{
 cin >> s;
 int a = 0 , b = 0;  
 for(int i=0 ; i<3 ; i++) a += s[i]; 
 for(int i=3 ; i<6 ; i++)    b += s[i]; 
 
 answer(a == b);
}
 
 
int main()
{
    test
  solve();
}
 
 
 