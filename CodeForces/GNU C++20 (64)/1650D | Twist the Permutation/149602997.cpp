#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
 
const int N = 3010; 
int n, a[N], pos[N]; 
vector<int> v, temp; 
deque<int> dq; 
 
int main()
{
    test
    {
     dq.clear();
     v.clear();
     cin >> n; 
     for(int i=1 ; i<=n ;i++) 
      cin >> a[i], 
      dq.push_back(a[i]);
     
     for(int i=n ; i>0 ; i--)
     { 
      for(int j=0 ; j<i ; j++)
       pos[dq[j]] = j + 1; 
      
      v.push_back(pos[i] % i); 
      
      for(int j=0 ; j<i - pos[i] ; j++)
       dq.push_front(dq.back()), 
       dq.pop_back();
      
      dq.pop_back();
     }
     
     reverse(all(v));
     for(int i : v) cout << i << ' ';
     cout << '\n'; 
    }   
}
 
 
 