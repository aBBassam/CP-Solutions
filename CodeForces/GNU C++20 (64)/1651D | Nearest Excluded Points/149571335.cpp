#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
 
const int N = 200100; 
queue<pair<int, int>> q; 
map<int, pair<int, int>> indx, ans[N];
set<int> gvn[N], checked[N];
int xx[] = {0, 0, 1, -1}, yy[] = {1, -1, 0, 0}, n, x, y;
 
int main()
{
 cin >> n; 
 for(int i=1 ; i<=n; i++)
  cin >> x >> y, 
  indx[i] = {x, y},
  gvn[x].insert(y);
 
 for(int i=1 ; i<N ;i++)
  for(int j : gvn[i])
   for(int k=0 ; k<4 ; k++)
    if(!gvn[i + xx[k]].count(j + yy[k]) && !checked[i].count(j)) 
     ans[i][j] = {i + xx[k], j + yy[k]}, 
     q.push({i, j}), 
     checked[i].insert(j);
 
 while(!q.empty())
 {
  pair<int, int> father = q.front();
  q.pop();
  
        for(int k=0 ; k<4 ; k++)
        {
         pair<int, int> nearMe = {father.F + xx[k], father.S + yy[k]}; 
         
   if(gvn[nearMe.F].count(nearMe.S) && !checked[nearMe.F].count(nearMe.S))
   {    
    q.push(nearMe); 
    ans[nearMe.F][nearMe.S] = ans[father.F][father.S];
    checked[nearMe.F].insert(nearMe.S);
   } 
  }
 }
  
  
 for(int i=1 ;i<=n ;i++)
  cout << ans[indx[i].F][indx[i].S].F << ' ' << ans[indx[i].F][indx[i].S].S << '\n';
}
 
 
 