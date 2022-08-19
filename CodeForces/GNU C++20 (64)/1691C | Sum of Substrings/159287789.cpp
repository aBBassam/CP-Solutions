#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
int n, k; 
string s; 
 
int main()
{
    test
    {
        cin >> n >> k >> s; 
 
        for(int i=n-1 ; i>=0 ; i--)
            if(s[i] == '1' && k >= (n - 1 -i))
            {
                k -= (n - 1 - i); 
                swap(s[n - 1], s[i]); 
                break;
            }
 
        for(int i=0 ; i <n-1; i++)
            if(s[i] == '1' && k >= i)
            {
                k -= i; 
                swap(s[0], s[i]); 
                break;
            }
            
        ll ans = 0; 
        for(int i=1 ;i<n; i++)
        {
            int sm = 0; 
            if(s[i - 1] == '1')  sm += 10; 
            if(s[i] == '1') sm += 1; 
 
            ans += sm; 
        }
        cout << ans << '\n'; 
    }
}