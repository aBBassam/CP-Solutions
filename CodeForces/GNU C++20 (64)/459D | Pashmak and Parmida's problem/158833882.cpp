#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 1000100; 
int n, a[N]; 
map<int, int> reps, reps2; 
 
struct node
{
   int sum;
 
   int s, e;
   node *left_child, *right_child;
 
   node(int a, int b, int k = 0)
   {
       sum = k;
 
       left_child = right_child = nullptr;
       s = a, e = b;
   }
 
   void update(int i, int add)
   {
       if (s == e)
           return void(sum += add);
 
       int mid = (s + e) / 2;
 
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
 
 
   int getKth(int k)
   {
       if (s == e)
           return e;
 
       if (left_child != nullptr && left_child->sum >= k)
           return left_child->getKth(k);
       else
       {
           if (left_child != nullptr)
               k -= left_child->sum;
           return right_child->getKth(k);
       }
   }
 
 
   int getSum(int a, int b)
   {
       if (a > b)
           return 0;
           
       if (s == a && e == b)
           return sum;
 
       int mid = (s + e) / 2;
       int fr = 0, sc = 0;
 
       if (left_child != nullptr)
           fr = left_child->getSum(a, min(mid, b));
       if (right_child != nullptr)
           sc = right_child->getSum(max(mid + 1, a), b);
 
       return fr + sc;
   }
};
 
 
 
int main()
{
 go; 
 
 node *seg = new node(0, 1e9); 
 
 cin >> n; 
 for(int i=1 ; i<=n; i++) 
  cin >> a[i], reps[a[i]] ++, seg->update(reps[a[i]], 1);
  
 ll ans = 0;  
 
 
 for(int i=1 ; i<= n;i ++)
 {
  seg->update(reps[a[i]], -1); 
  reps[a[i]] --; 
  
  reps2[a[i]] ++; 
  ans += seg->getSum(0, reps2[a[i]] - 1);
 }
 
 
 cout << ans; 
}