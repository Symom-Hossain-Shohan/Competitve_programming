#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb           push_back
#define mp           make_pair
#define in           insert
#define pi           2*acos(0.0)
#define srt(s)       sort(s.begin(),s.end())
#define rsrt(s)      sort(s.rbegin(),s.rend())
#define all(x)       x.begin(),x.end()
#define mem(a, b)    memset(a, b, sizeof(a))
#define c_test       printf("Case %lld: ",t)

const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

//code goes from here...



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> v(4);
        ll a=1,b=2,c=3,d=4;
        ll x;

        cout << "? " << a << ' ' << b << ' ' << c << endl;
        cin  >> x;
        v[0]={x,d};
        cout << "? " << a << ' ' << b << ' ' << d << endl;
        cin >> x;
        v[1]={x,c};
        cout << "? " << a << ' ' << c << ' ' << d << endl;
        cin >> x;
        v[2]={x,b};
        cout << "? " << b << ' ' << c << ' ' << d << endl;
        cin>> x;
        v[3]={x,a};

        srt(v);
        ll tm=v[3].second ;
        if(n%2==0)
        {
            for(int i=5;i<=n-1;i+=2)
            {
                srt(v);
                a=v[0].second,b=v[1].second ,c=i,d=i+1;

                cout << "? " << a << ' ' << b << ' ' << c << endl;
                cin  >> x;
                v[0]={x,d};
                cout << "? " << a << ' ' << b << ' ' << d << endl;
                cin >> x;
                v[1]={x,c};
                cout << "? " << a << ' ' << c << ' ' << d << endl;
                cin >> x;
                v[2]={x,b};
                cout << "? " << b << ' ' << c << ' ' << d << endl;
                cin>> x;
                v[3]={x,a};


            }
            srt(v);
            cout << "! " << v[0].second << ' ' << v[1].second << endl;
        }
        else
        {
            
            for(int i=5;i<=n-2;i+=2)
            {
                srt(v);
                a=v[0].second,b=v[1].second ,c=i,d=i+1;

                cout << "? " << a << ' ' << b << ' ' << c << endl;
                cin  >> x;
                v[0]={x,d};
                cout << "? " << a << ' ' << b << ' ' << d << endl;
                cin >> x;
                v[1]={x,c};
                cout << "? " << a << ' ' << c << ' ' << d << endl;
                cin >> x;
                v[2]={x,b};
                cout << "? " << b << ' ' << c << ' ' << d << endl;
                cin>> x;
                v[3]={x,a};
            }
            srt(v);
            a=v[0].second,b=v[1].second,c=n ,d=tm;
            cout << "? " << a << ' ' << b << ' ' << c << endl;
            cin  >> x;
            v[0]={x,d};
            cout << "? " << a << ' ' << b << ' ' << d << endl;
            cin >> x;
            v[1]={x,c};
            cout << "? " << a << ' ' << c << ' ' << d << endl;
            cin >> x;
            v[2]={x,b};
            cout << "? " << b << ' ' << c << ' ' << d << endl;
            cin>> x;
            v[3]={x,a};
            srt(v);
            cout << "! " << v[0].second << ' ' << v[1].second << endl;
        }
        
 
    }
    
    //---------------------------------
    
    return 0;
}