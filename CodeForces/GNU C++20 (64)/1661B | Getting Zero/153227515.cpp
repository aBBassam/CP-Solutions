#include <bits/stdc++.h>
#define ll long long
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
using namespace std;
 
const int N = 200100, mod = 32768; 
ll n, ans;
 
ll F(ll n)
{
 ll ret = 0; 
 while(n % 2 == 0 && n) ret ++, n /= 2; 
 return ret; 
}
 
int main()
{
    test
    { 
     cin >> n, ans = 15; 
     for(int i=0 ; i<15 ; i++)
      ans = min(ans, i + max(0ll, 15 - F(n + i)));
      
     cout << (n ? ans : 0) << ' ';
    }
}