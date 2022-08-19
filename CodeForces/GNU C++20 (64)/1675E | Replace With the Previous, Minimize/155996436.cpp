// Problem: E. Replace With the Previous, Minimize
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
ll n, k; 
string s; 
map<char, char> m; 
 
 
void solve()
{
 // k 26 => aaaaaaaaaaaa
 cin >> n >> k >> s; 
 s = '$' + s; 
 m.clear(); 
 for(int i=1 ; i<=n;  i++)
  m[s[i]] = s[i]; 
 
 char letter = 'a'; 
 int cost = 0; 
 
 char lst; 
 int amount = -1; 
 
 for(int i=1 ;i<=n; i++)
 {
  if(letter >= s[i]) continue; 
  
  int req = s[i] - letter;
  
  if((k - cost) < req) // not enough
  {
   int have = k - cost; 
   lst = s[i]; 
   amount = have; 
   break;
  }
  else 
  {
   letter = s[i]; 
   cost = s[i] - 'a'; 
  }
 }
 
 for(char c = letter ; c >= 'a' ;  c--)
  m[c] = 'a'; 
 
 if(amount != -1)
 {
  char nw = lst - amount;
  for(char c = lst ; c >= 'a' ;  c--)
  {
   m[c] = min(m[c], nw);
  }
 }
   
 for(int i=1 ; i<=n;  i++)
  cout << m[s[i]]; 
 cout << '\n'; 
}
 
 
int main()
{
    test
  solve();
}
 
 
 