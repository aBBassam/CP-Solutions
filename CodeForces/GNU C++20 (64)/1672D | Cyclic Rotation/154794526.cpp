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
int n, a[N], b[N], skipA[N]; 
multiset<ll> st; 
 
 
void solve()
{
 st.clear(); 
 cin >> n; 
 for(int i=1 ; i<=n; i++) cin >> a[i]; 
 for(int i=1 ; i<=n; i++) cin >> b[i]; 
 
 int aI = 1; 
 for(int i = 1; i<=n; i++) // i on B
 { 
  while(aI <= n && a[aI] != b[i]) st.insert(a[aI ++]); 
  if(aI > n) break;
  
  if(st.count(a[aI])) st.erase(st.find(a[aI]));
  else aI++; 
 }
 
 if(st.size() != 0) cout << "NO\n";
 else cout << "YES\n"; 
}
 
int main()
{
    test
  solve();
}