// Problem: B. Vlad and Candies
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/B
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
int n, a[N]; 
 
void solve( )
{
 cin >> n; 
 for(int i=1 ; i<=n ; i++) cin >> a[i]; 
 sort(a + 1, a + n + 1); 
 if(n == 1) answer(a[n] == 1); 
 else answer(abs(a[n] - a[n-1]) <= 1);
}
 
 
int main()
{
    test
  solve();
}
 
 
 