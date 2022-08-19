#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
multiset<ll>  factorization (ll n)
{
    multiset<ll> primes;
    for(ll i=2 ; i*i <= n ; i++)
        while(n%i==0)
            primes.insert(i),n /= i;
    if(n > 1) primes.insert(n);
    if(primes.count(1))
     primes.erase(1);
    return primes;
}
 
ll n, d; 
multiset<ll> dPrms; 
 
void solve( )
{ 
 cin >> n >> d; 
 
 dPrms = factorization(d);
 
 int cnt = 0; 
 while(n % d == 0)
  cnt ++, n /= d;  
 
 if(cnt == 1) cout << "NO\n";
 else if(factorization(n).size() > 1) cout << "YES\n";  
 else if(dPrms.size() == 1 || cnt <= 2) cout << "NO\n";
 else if(cnt > 3 || n * n != d) cout << "YES\n";
 else cout << "NO\n";
}
 
 
int main()
{
    test
  solve();
}
 
 
 