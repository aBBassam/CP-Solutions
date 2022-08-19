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
ll n;
multiset<ll> as; 
 
 
ll f(ll n)
{
 while(n % 2 == 0) n /= 2; 
 return n; 
}
 
 
 
void solve()
{
 as.clear(); 
 cin >> n; 
 for(int i=1, k; i<=n;i++) cin >> k, as.insert(f(k)); 
 for(int i=1, k; i<=n;i++)
 {
  cin >> k;
  while(k)
  {
   if(as.find(k) != as.end())
   {
    as.erase(as.find(k)); 
    break;
   }
   k /= 2; 
  }
 }
 
 answer(as.size() == 0);
}
 
 
 
 
 
int main()
{
    test
  solve();
}