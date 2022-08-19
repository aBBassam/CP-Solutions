#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n; 
vector<int> v; 
 
 
int main()
{
    cin >> n; 
    v.resize(n / 2);  
 
    for(auto &it : v) cin >> it; 
 
    sort(all(v)); 
 
    int ind = 1, ans1 = 0, ans2 = 0;
 
    for(int i : v)
        ans1 += abs(i - ind), ind += 2; 
 
    ind = 2; 
    for(int i : v)
        ans2 += abs(i - ind), ind += 2;
 
    cout << min(ans1, ans2);
}   