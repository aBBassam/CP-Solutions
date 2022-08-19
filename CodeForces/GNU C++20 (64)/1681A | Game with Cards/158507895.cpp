#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 100;
vector<int> a, b; 
int n, m;  
int k; 
 
 
void solve( )
{
 a.clear(), b.clear(); 
 cin >> n; 
 for(int i=1 ;i <=n; i++) 
  cin >> k, 
  a.push_back(k);
 
 cin >> m; 
 for(int i=1 ;i<=m; i++)
  cin >> k, 
  b.push_back(k); 
 
 a.push_back(-1), b.push_back(-1); 
 
 sort(all(a)), sort(all(b)); 
 
 
 string ans1, ans2; 
 
 if(a.back() > b.back())
  ans1 = "Alice", ans2 = "Alice";
 else if(a.back() < b.back())
  ans1 = "Bob", ans2 = "Bob";  
 else 
  ans1 = "Alice", ans2 = "Bob";
 
 cout << ans1 << '\n' << ans2 << '\n'; 
 
}
 
 
int main()
{
    test
  solve();
}
 
 
 