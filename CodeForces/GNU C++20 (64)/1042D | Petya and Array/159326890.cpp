#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const ll INF = 1e15; 
 
struct node
{
   int sum;
   node *left_child, *right_child;
 
   node()
   {
       sum = 0; 
       left_child = right_child = 0;
   }
 
   void update(ll i, int add, int bit = 60)
   {
       if (bit == -1)
           return;
 
       sum += add;
       if (i & (1LL << bit))
       {
           if (!right_child) right_child = new node(); 
           right_child->update(i, add, bit - 1);
       }
       else
       {
           if (!left_child) left_child = new node();
           left_child->update(i, add, bit - 1);
       }
   }
 
    ll getSum(ll beforeI, int bit = 60)
    {
        if( beforeI&(1LL<<bit) )
        {
            if(!right_child && !left_child) return 0;
    
            if(!right_child)
                return (left_child->sum);
    
            if(!left_child)
                return right_child->getSum(beforeI, bit - 1);
 
            return right_child->getSum(beforeI, bit - 1) + left_child->sum; 
        }
        else
        {
            if(!left_child) return 0;
            return left_child->getSum(beforeI, bit - 1);
        }
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
    node *seg = new node(); 
 
    for(int i=1 ;i<=n;i++) sum += a[i], seg->update(sum * 2 + INF, 1);
 
    sum = 0; 
    for(int i=1 ; i<=n; i++)
    {
        ans += seg->getSum(k * 2+ INF);
 
        sum += a[i]; 
        k += a[i]; 
 
        seg->update(sum * 2 + INF, -1); 
    }
 
    cout << ans;
}