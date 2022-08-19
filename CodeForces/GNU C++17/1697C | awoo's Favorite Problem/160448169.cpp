// Problem: C. awoo's Favorite Problem
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/C
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
using namespace std;
 
 
const int N = 100100; 
int n, a, b, c, aa, bb, cc, pre[N][3]; 
string s, t; 
set<int> pos[3]; 
 
 
void solve( )
{
 cin >> n >> s >> t; 
 
 s = "*" + s; 
 t = "*" + t; 
 
 a = b = c = aa =  bb = cc = 0;
 
 for(int i=0 ; i<3 ; i++)
  pos[i].clear();  
 
 for(int i=1 ; i <=n ;i++)
  if(s[i] == 'a') a ++; 
  else if(s[i] == 'b') b ++; 
  else c++; 
  
 for(int i=1 ; i <=n ;i++)
  if(t[i] == 'a') aa ++; 
  else if(t[i] == 'b') bb ++; 
  else cc++; 
 
 if(aa != a || bb != b || cc != c)
  return void(answer(0));  
 
 for(int i=1 ; i<=n; i++) pos[s[i] - 'a'].insert(i); 
 
 
 for(int i=1 ; i<=n ; i++)
  if(t[i] == 'b' && s[i] == 'a')
  {
   
   auto it = pos[1].lower_bound(i); 
   if(it == pos[1].end()) continue; 
   int B_ind = *it; 
   
   // i -> B_ind        no C & no B
   
   int ys = 1; 
   
   it = pos[2].upper_bound(i); 
   if(it != pos[2].end())
   {
    if(*it <= B_ind) ys = 0; 
   }
   
   it = pos[1].upper_bound(i); 
   if(it != pos[1].end())
   {
    if(*it < B_ind) ys = 0; 
   }
   
   
   if(ys)
   { 
    swap(s[B_ind], s[i]); 
    
    pos[0].insert(B_ind); 
    pos[1].insert(i); 
    
    pos[1].erase(B_ind); 
    pos[0].erase(i); 
   }   
  }
  
 
 
 for(int i=n ; i>0 ; i--)
  if(t[i] == 'b' && s[i] == 'c')
  {
   // shift it forward 
   // no As in the way
   
   auto it = pos[1].upper_bound(i); 
   if(it == pos[1].begin()) continue; 
   it --; 
   int B_ind = *it; 
   
   
   
   // B -> i      no A & no B
   
   int ys = 1; 
   
   it = pos[0].upper_bound(B_ind); 
   if(it != pos[0].end())
   {
    if(*it <= i) ys = 0; 
   }
   
   it = pos[1].upper_bound(B_ind); 
   if(it != pos[1].end())
   {
    if(*it < i) ys = 0; 
   }
   
   
   if(ys)
   { 
    swap(s[B_ind], s[i]); 
    
    pos[2].insert(B_ind); 
    pos[1].insert(i); 
    
    pos[1].erase(B_ind); 
    pos[2].erase(i); 
   }
  }
  
 answer(s == t); 
}
 
 
int main()
{
    test
  solve();
}