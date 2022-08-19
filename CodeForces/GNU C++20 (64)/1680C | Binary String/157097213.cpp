#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mid ((st + en) / 2)
#define F first
#define S second
using namespace std;
 
 
const int N = 200100; 
int n, pre[N], suf[N];
int zs;  
string s; 
 
int chk(int removeOnes)
{
 int mxZeros = 0; 
 for(int i=0 ; i<= removeOnes ; i++)
  mxZeros = max(mxZeros, pre[i] + suf[removeOnes - i]);
 
 return (zs - mxZeros) <= removeOnes; 
}
 
 
 
void solve()
{
 cin >> s, n = s.length(), s = "*" + s; 
 
 int zeros = 0, ones = 0; 
 for(int i=1 ;i <=n; i++)
 {
  if(s[i] == '1') pre[ones ++] = zeros; 
  else zeros ++; 
 }
 zeros = 0, ones = 0; 
 for(int i=n ;i > 0; i--)
 {
  if(s[i] == '1')suf[ones ++] = zeros; 
  else zeros ++; 
 }
 
 if(ones == 0) return void(cout << "0\n");
 
 zs = zeros; 
 int st = 0, en = ones, ans = 10000000; 
 while(st <= en)
  if(chk(mid)) ans = mid, en = mid - 1; 
  else st = mid + 1; 
 
 cout << ans << '\n';
 for(int i=0 ; i<=n ;i++)
  pre[i] = suf[i] = 0;
}
 
 
int main()
{
    test
  solve();
}