#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb(x) push_back(x)
#define F first
#define S second
using namespace std;
 
 
int mul(int x,int y,int mod)
{
    return (ll) x*y %mod;
}
int sum(int x,int y,int mod)
{
    return (x+y) %mod;
}
int sub(int x,int y,int mod)
{
    return sum((x-y)%mod,mod,mod);
}
int po(int x,int y,int mod)
{
    if(!y) return 1;
    if(y&1) return mul(x,po(x,y-1,mod),mod);
    int z=po(x,y/2,mod);
    return mul(z,z,mod);
}
int inv(int x,int mod)
{
    return po(x,mod-2,mod);
}
struct Hash
{
    int n,Base,Mod,Inv;
    vector <int> Po,Pre;
    Hash(string &s,int base,int mod)
    {
        Mod=mod;
        Base=base;
        Po.reserve(s.size() + 1);
        Pre.reserve(s.size() + 1);
        Po.pb(1);
        Pre.pb(0);
        Inv=inv(base,Mod);
        for(int i=1; i<=(int)s.size(); i++)
            Add(s[i-1]);
    }
    void Add(char c)
    {
        Po.pb(mul(Base,Po.back(),Mod));
        Pre.pb(sum(mul(Pre.back(),Base,Mod),c,Mod));
    }
    int G(int L,int R)
    {
        R++;
        return sub(Pre[R], mul(Pre[L],Po[R-L],Mod), Mod);
    }
};
 
vector<int> prefix_function(string s) {
    int n = (int)s.size();
    vector<int> pi(n , 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
const int N = 1000100; 
string s; 
int n;
set<int> hset[2];  
 
int main()
{
 go;
 
 cin >> s; 
 n = s.length(); 
 
 if(n <= 2)
  return cout << "Just a legend", 0; 
 
 
 Hash s1(s, 1337, 1e9 + 7); 
 Hash s2(s, 1007, 1e9 + 9); 
 
 
 
 auto KMP = prefix_function(s);
 int mx = 0; 
 for(int i = 1; i<n - 1; i++)
  mx = max(mx, KMP[i]);
 
 int ans = -1; 
 
 for(int i=0 ; i<mx ;i ++)
  if(s1.G(0, i) == s1.G(n - 1 - i, n - 1) && s2.G(0, i) == s2.G(n - 1 - i, n - 1))
   ans = i;
 
 if(ans == -1) cout << "Just a legend";
 else for(int i=0 ; i<=ans; i++)
   cout << s[i];
}
 
 
 