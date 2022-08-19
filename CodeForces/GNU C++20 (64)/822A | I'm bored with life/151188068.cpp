#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int main()
{
 ll a, b, ans = 1; 
 cin >> a >> b; 
 
 for(int i=1 ; i<=min(a, b); i++)
  ans *= i; 
 cout << ans; 
}