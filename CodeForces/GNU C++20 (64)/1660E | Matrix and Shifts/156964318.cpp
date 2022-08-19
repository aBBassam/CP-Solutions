#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 2010; 
int n; 
string s[N]; 
set<int> rem;
 
 
void solve()
{
 rem.clear();
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> s[i], s[i] = "*" + s[i]; 
 
 int okOnes = 0; 
 int ones = 0; 
 for(int i=1 ; i<=n; i++)
  for(int j=1 ; j<=n ; j++)
   ones += (s[i][j] == '1'); 
   
 for(int st=1 ; st<=n; st++)
 {
  int l_ans = 0;
  int i=st, j = 1; 
  
  while(j <= n)
  {
   if(s[i][j] == '1') l_ans ++; 
   
   j ++, i ++; 
   if(i > n) i = 1; 
  }
  
  okOnes = max(okOnes, l_ans); 
 }
 
 cout << ones - okOnes + (n - okOnes) << '\n'; 
}
 
 
int main()
{
    test
  solve();
}