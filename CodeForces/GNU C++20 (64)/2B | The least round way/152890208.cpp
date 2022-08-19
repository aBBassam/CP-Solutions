#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
using namespace std;
 
const int N = 1010;
ll n, a[N][N], five[N][N], two[N][N], dp[N][N], dp2[N][N]; 
int xz, yz, zero; 
 
ll solve(int i, int j) // min path for 2
{
 if(i == n && j == n) return two[n][n];
 if(max(i, j) > n) return 1e9; 
 
 ll &ret = dp[i][j]; 
 if(ret + 1) return ret; 
 ret = two[i][j]; 
 ret += min(solve(i + 1, j), solve(i, j + 1)); 
 return ret; 
}
 
ll solve2(int i, int j) // min path for 5 if 2 done
{
 if(i == n && j == n) return five[n][n];
 if(max(i, j) > n) return 1e9; 
 
 ll &ret = dp2[i][j]; 
 if(ret + 1) return ret; 
 ret = five[i][j]; 
 
 ll fr = 1e9, sc = 1e9;  
 
 if(solve(i + 1, j) + two[i][j] == solve(i, j))
  fr = solve2(i+1, j); 
  
 if(solve(i, j + 1) + two[i][j] == solve(i, j))
  sc = solve2(i, j+1);
 
 return ret = ret + min(fr, sc); 
}
 
 
void path1(int i, int j)
{
 if(i == n && j == n) return; 
 
 if(solve(i + 1, j) + two[i][j] == solve(i, j) && solve2(i, j) - five[i][j] == solve2(i + 1, j))
  cout << 'D', path1(i + 1, j);
 else 
  cout << 'R', path1(i, j + 1); 
}
 
 
 
ll solve3(int i, int j) // min path for 5
{
 if(i == n && j == n) return five[n][n];
 if(max(i, j) > n) return 1e9; 
 
 ll &ret = dp[i][j]; 
 if(ret + 1) return ret; 
 ret = five[i][j]; 
 ret += min(solve3(i + 1, j), solve3(i, j + 1)); 
 return ret; 
}
 
ll solve4(int i, int j) // min path for 2 if 5 done
{
 if(i == n && j == n) return two[n][n];
 if(max(i, j) > n) return 1e9; 
 
 ll &ret = dp2[i][j]; 
 if(ret + 1) return ret; 
 ret = two[i][j]; 
 
 ll fr = 1e9, sc = 1e9;  
 
 if(solve3(i + 1, j) + five[i][j] == solve3(i, j))
  fr = solve4(i+1, j); 
  
 if(solve3(i, j + 1) + five[i][j] == solve3(i, j))
  sc = solve4(i, j+1);
 
 return ret = ret + min(fr, sc); 
}
 
 
void path2(int i, int j)
{
 if(i == n && j == n) return;  
 
 if(solve3(i + 1, j) + five[i][j] == solve3(i, j) && solve4(i, j) - two[i][j] == solve4(i + 1, j))
  cout << 'D', path2(i + 1, j);
 else 
  cout << 'R', path2(i, j + 1); 
}
 
 
int main()
{
 cin >> n; 
 
 for(int i=1 ; i<=n ; i++)
  for(int j=1 ; j<=n; j++)
  {
   cin >> a[i][j]; 
   
   if(!a[i][j]) zero = 1, xz = i, yz = j; 
   
   ll nm = a[i][j]; 
   while(nm && nm % 2 == 0) two[i][j] ++, nm /= 2; 
   while(nm && nm % 5 == 0) five[i][j] ++, nm /= 5; 
  }
  
 
  
 memset(dp, -1, sizeof dp); 
 memset(dp2, -1, sizeof dp2); 
 ll fr = min(solve(1, 1), solve2(1, 1)); 
 
 memset(dp, -1, sizeof dp); 
 memset(dp2, -1, sizeof dp2);  
 ll sc = min(solve3(1, 1), solve4(1, 1));  
 
 
 if(zero && min(fr, sc) != 0)
 {
  cout << "1\n";
  for(int i=1 ; i<xz ; i++) cout << 'D';
  for(int i=1 ; i<yz ; i++) cout << 'R';
  
  while(xz < n) cout << 'D', xz++; 
  while(yz < n) cout << 'R', yz++;
  
  return 0;  
 }
 
 cout << min(fr, sc) << '\n';
 
 memset(dp, -1, sizeof dp); 
 memset(dp2, -1, sizeof dp2); 
 
 if(fr < sc)
  solve(1, 1), solve2(1, 1), path1(1, 1);
 else 
  solve3(1, 1), solve4(1, 1), path2(1, 1);  
}