#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i,n) for(int i=0;i<n;i++)
#define si size()
#define deb(n) cout<<#n<<" : "<<n<<endl;
#define deba(a,n) cout<<#a<<" : "<<endl; forn(i,n)cout<<a[i]<<" "; cout<<endl;
#define chk(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define go ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
    go;
    ll tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        set<ll>b,c,a;
        forn(i,n)
        {
            if(s[i]=='b')
                b.insert(i);
            else if (s[i]=='c')
                c.insert(i);
            else
                a.insert(i);
        }
 
        bool ans=1;
        forn(i,n)
        {
            if(s[i]!=t[i])
            {
                if(s[i]=='a'&&t[i]=='b')
                {
                    if(b.upper_bound(i)!=b.end()&&
                            (c.upper_bound(i)==c.end()||
                             *b.upper_bound(i)<*c.upper_bound(i)))
                    {
                        s[*b.upper_bound(i)]='a';
                        s[i]='b';
                        b.erase(b.find(*b.upper_bound(i)));
                    }
                    else ans=0;
                }
                else if(s[i]=='b'&&t[i]=='c')
                {
                    if(c.upper_bound(i)!=c.end()&&
                            (a.upper_bound(i)==a.end()||
                             *c.upper_bound(i)<*a.upper_bound(i)))
                    {
                        s[*c.upper_bound(i)]='b';
                        s[i]='c';
                        c.erase(c.find(*c.upper_bound(i)));
                    }
                    else ans=0;
 
                }
                else ans=0;
            }
        }
 
        chk(ans);
    }
    return 0;
}