#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int op, cl, n, ans; 
queue<char> s; 
char c; 
 
void solve( )
{
 ans = op = cl = 0; 
 while(s.size())s.pop();
 
 cin >> n; 
 for(int i=0 ; i<n ;i++)
  cin >> c,
  (c == '(') ? op ++ : cl ++, 
  s.push(c);
 
 
 while(s.size() > 1)
 {
  if(s.front() == ')')
  {
   if(cl < 2) break;
   ans ++ ; 
   cl -- ; 
   s.pop(); 
   
   while(s.front() != ')')
    s.pop(), op --; 
   
   cl -- ; 
   s.pop();
  }
  else 
  {
   ans ++ ; 
   s.pop(); 
   op -- ; 
   (s.front() == ')') ? cl -- : op --;
   s.pop();
  }
 }
 
 cout << ans << ' ' << s.size() << '\n';
}
 
 
int main()
{
    test
  solve();
}
 
 
 