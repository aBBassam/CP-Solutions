#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const ll INF = 2e15; 
 
struct node
{
   ll sum;
 
   ll s, e;
   node *left_child, *right_child;
 
   node(ll a, ll b, ll k = 0)
   {
       sum = k;
 
       left_child = right_child = nullptr;
       s = a, e = b;
   }
 
   void update(ll i, ll add)
   {
       if (s == e)
           return void(sum += add);
 
       ll mid = (s + e) / 2;
 
       if (i <= mid)
       {
           if (left_child == nullptr)
               left_child = new node(s, mid);
           left_child->update(i, add);
       }
       else
       {
           if (right_child == nullptr)
               right_child = new node(mid + 1, e);
           right_child->update(i, add);
       }
 
       sum = 0;
       if (left_child)
           sum += left_child->sum;
       if (right_child)
           sum += right_child->sum;
   }
 
   ll getSum(ll a, ll b)
   {
       if (a > b)
           return 0;
       if (s == a && e == b)
           return sum;
 
       ll mid = (s + e) / 2;
       ll fr = 0, sc = 0;
 
       if (left_child != nullptr)
           fr = left_child->getSum(a, min(mid, b));
       if (right_child != nullptr)
           sc = right_child->getSum(max(mid + 1, a), b);
 
       return fr + sc;
   }
};
 
 
const int N = 200100; 
ll n, k, sum, ans;
int a[N];
 
 
int main()
{
    go;
    cin >> n >> k; 
    for(int i=1; i<=n;i++) cin >> a[i]; 
    node *seg = new node(0, 2 * INF); 
    k += INF; 
 
    for(int i=1 ;i<=n;i++) sum += a[i], seg->update(sum + INF, 1); 
 
    sum = INF; 
    for(int i=1 ; i<=n; i++)
    {
        ans += seg->getSum(0, k - 1); 
 
        k += a[i];
        sum += a[i]; 
 
        seg->update(sum, -1); 
    }
 
    cout << ans;
}