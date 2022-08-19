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
string s; 
map<char, int> rp;
char fr, sc; 
string RGB = "RGB";
set<char> ans; 
 
int main()
{
    cin >> n >> s; 
    for(char c : s)
     rp[c] ++ ; 
     
    if(rp.size() == 3) return cout << "BGR", 0; // yes
    if(rp.size() == 1) return cout << s[0], 0; // yes
    
    // two letters left : 
 if(n == 2)
 {
  for(char c : RGB)
   if(rp[c] == 0)
    cout << c; 
    
  return 0;
 }
 
 // n >= 3 AND two letters - third one is in the answer
 
 
 int mn = 5000; 
 for(auto it : rp)
  mn = min(mn, it.S);
 
 if(mn > 1) return cout << "BGR", 0; 
 
 
 
 for(char c : RGB)
  if(rp[c] <= 1)
   ans.insert(c);
  
  
 for(char c : ans) cout << c;
}
 
 
 