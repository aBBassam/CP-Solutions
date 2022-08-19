// Problem: D. Rorororobot
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1709/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
#define int long long
using namespace std;
 
 
template<typename T, class F = function<T(const T&, const T&)>>
class SparseTable
{
public :
    int n;
    vector<vector<T>> st;
    F func;
 
    SparseTable(const vector<T>& a, const F& f) : func(f)
    {
        n = (int) a.size();
        int maxlg = 32 - __builtin_clz(n);
        st.resize(maxlg);
        st[0] = a;
        for (int i = 1; i < maxlg; i++)
        {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < n - (1 << i) + 1; j++)
            {
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
 
    T get(int l, int r) const
    {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 32 - __builtin_clz(r - l + 1) - 1;
        return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
    }
};
 
 
const int N = 200100, M = 200100; 
 
 
int32_t main()
{
 go; 
 int n, m; cin >> n >> m;
 
 vector<int> v; 
 v.push_back(0);
 for(int i=1, k ;i <= m; i++)
  cin >> k, v.push_back(k); 
 
    SparseTable<int> A(v, [&] (int x, int y)
    {
        return max(x, y);
    });
    
    
    int q; cin >> q; 
    while(q --)
    {
     int x1, y1, x2, y2, k; 
     cin >> x1 >> y1 >> x2 >> y2 >> k; 
     
     int up = (n - x1) / k; 
     x1 += up * k;
     
     
     answer(A.get(min(y1, y2), max(y1, y2)) < x1 && (abs(y2 - y1) % k) == 0 && (abs(x2 - x1) % k) == 0);
    }
}
 
 