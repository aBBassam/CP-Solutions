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
 
 
int N;
string s; 
map<int, vector<int>> pos; 
vector<int> a; 
vector<pair<int, int>> v;  // len -> beginning 
 
 
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
    int Base,Mod,Inv;
    vector <int> Po,Pre;
    Hash(vector<int> s,int base,int mod)
    {
        Mod=mod;
        Base=base;
        Po.reserve(s.size() + 1);
        Pre.reserve(s.size() + 1);
        Po.pb(1);
        Pre.pb(0);
        Inv=inv(base,Mod);
        for(int i=1; i<=N; i++)
            Add(s[i-1]);
    }
    void Add(int c)
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
 
 
int main()
{
 go; 
 cin >> N; 
 a.resize(N); 
 for(int i=0 ;i <N; i++) cin >> a[i], pos[a[i]].pb(i);
  
 Hash h1(a, 1337, 1e9 + 7); 
 Hash h2(a, 1007, 1e9 + 9);
 
 
 for(auto it : pos)
 {
  int n = it.S.size(); 
  for(int i=0 ; i< n; i++)
   for(int j=i+1 ; j< n; j++) // j is bigger : 
    v.push_back({it.S[j] - it.S[i], it.S[i]});
 }
 
 sort(all(v)); 
 int mx = -1; 
 
 for(auto it : v) if(it.S > mx)
 {
  int bef = it.S;
  int me = it.S + it.F; 
  int len = me - bef; 
  
  if(me + len - 1 >= N) continue;
  if( h1.G(bef, bef + len - 1) == h1.G(me, me + len - 1) && h2.G(bef, bef + len - 1) == h2.G(me, me + len - 1))
   mx = me  - 1;
 }
 
 cout << (mx != -1 ?  N - mx - 1 : N) << '\n';
 for(int i= mx + 1; i<N ; i++) cout << a[i] << ' ';
}