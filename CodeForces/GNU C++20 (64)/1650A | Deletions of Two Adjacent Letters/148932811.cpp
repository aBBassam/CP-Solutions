#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n;
char c; 
string s; 
 
 
 
void solve( )
{
 cin >> s >> c; 
 n = s.length();
 int ind = 0, rep = 0; 
 
 for(int i=0 ; i<n ;i++) 
  if(s[i] == c && (n - 1 - i) % 2 == 0 && i % 2 == 0) 
   return void(cout << "YES\n");
 
 cout << "NO\n"; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 