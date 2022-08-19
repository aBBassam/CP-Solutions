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
map<char, int> rep; 
 
void solve()
{
 rep.clear(); 
 cin >> s; 
 
 for(char c : s)
  rep[c] ++; 
 
 int n = s.length();
 int i = 0;
 for( ; i<n ; i++)
 {
  if(rep[s[i]] == 1) break;
  rep[s[i]] --; 
 }
 
 for( ; i<n ;i++)
  cout << s[i];
  
 cout << '\n';
}
 
 
int main()






