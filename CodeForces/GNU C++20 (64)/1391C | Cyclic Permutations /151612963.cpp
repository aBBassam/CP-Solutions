#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 2001000; 
const int Mod = 1e9 + 7;
 
int Inv[N];
int Fact[N];
int iFact[N];
 
void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}
 
int add(int x, int y)
{
    return add_self(x, y), x;
}
 
void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += Mod;
}
 
int sub(int x, int y)
{
    return sub_self(x, y), x;
}
 
int mul(int x, int y)
{
    return (long long) x * y % Mod;
}
 
int C(int n, int r)
{
    if(n < 0 || r < 0 || n < r) return 0;
    return mul(Fact[n], mul(iFact[r], iFact[n - r]));
}
int fp(int x, int y)
{
    int Res = 1;
    for( ; y > 0; y >>= 1, x = mul(x, x))
        if(y & 1)
            Res = mul(Res, x);
    return Res;
}
void PreCalcMod()
{
    Inv[1] = 1;
    for(int i = 2; i < N; i++)  Inv[i] = sub(0, mul(Mod / i, Inv[Mod % i]));
 
    Fact[0] = iFact[0] = 1;
    for(int i = 1; i < N; i++)  Fact[i] = mul(i, Fact[i - 1]);
    for(int i = 1; i < N; i++)  iFact[i] = mul(Inv[i], iFact[i - 1]);
}
 
 
 
int main()
{
 PreCalcMod(); 
 int n; cin >> n; 
 cout << sub(Fact[n], fp(2, n - 1));
}