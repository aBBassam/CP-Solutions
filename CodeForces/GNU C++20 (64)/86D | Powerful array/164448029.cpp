#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 200200, SQRT = 440, M = 1e6 + 10; 
ll n, q, cnt[M],a[N];
ll ans[N];
 
 
struct Query
{
   int L, R, idx;
   Query(){ L = R = idx = 0; }
 
   bool operator<(const Query &tmp) const{
       if (L/SQRT != tmp.L/SQRT)
           return L < tmp.L;
       return R < tmp.R;
   }
} Q[N];
ll answer = 0;
 
 
void add(int num)
{
   answer -= cnt[num]*cnt[num]*num;
   cnt[num]++;
   answer += cnt[num]*cnt[num]*num;
}
void del(int num)
{
   answer -= cnt[num]*cnt[num]*num;
   cnt[num]--;
   answer += cnt[num]*cnt[num]*num;
}
 
 
int main()
{
 go; 
 cin >> n >> q;
 for(int i=1 ;i <=n;i ++) cin >> a[i]; 
 
 for(int i=1, l, r ;i <= q ; i++)
  cin >> l >> r, 
  Q[i].L = l, Q[i].R = r, Q[i].idx = i; 
 
 sort(Q + 1, Q + q + 1); 
 
    int left = 0,right = 0;
    for(int i = 1;i<=q;i++)
    {
        while(right < Q[i].R)
            add(a[++right]);
        while(right > Q[i].R)
            del(a[right--]);
        while(left > Q[i].L)
            add(a[--left]);
        while(left < Q[i].L)
            del(a[left++]);
        ans[Q[i].idx] = answer;
    }
 
 for(int i=1 ;i <=q; i++)
  cout << ans[i] << '\n'; 
}