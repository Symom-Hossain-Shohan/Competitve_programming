#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MX = 100010 ; 
int tree[MX] ; 
int n ; 
void update(int idx, int val )
{
    while (idx<=n)
    {
        tree[idx] += val ; 
        idx += (idx & -idx) ; 
    }
}

int query(int idx )
{
    int sum = 0 ; 
    while(idx )
    {
        sum += tree[idx] ; 
        idx -= (idx & -idx) ; 
    }
    return sum ; 
}

void solve()
{
    memset(tree, 0, sizeof tree) ; 
    string s; 
    cin >> s ; 
    n = s.size() +1; 
    int q ;
    cin >> q ;
    while(q--)
    {
        char c ;
        cin >> c ; 
        
        if(c =='I')
        {
            int i, j ;
            cin >> i >>  j ;
            update(i, 1) ; 
            update(j+1, -1) ;
        }
        else 
        {
            int i ; 
            cin >> i ;
            if(query(i)%2)
            {
                if(s[i-1]=='0') cout << "1\n" ; 
                else cout << "0\n" ;
            }
            else cout << s[i-1] << endl ; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t << ":\n" ; 
        solve();
    }
    return 0;
}