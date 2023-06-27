    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    const ll N = 2e5 + 5;

    ll ar[N];
    ll mintree[4 * N + 5];
    ll maxtree[4 * N + 5];

    void buildMinTree(ll s, ll e, ll index)
    {
        if(s==e)
        {
            mintree[index] = ar[s];
            return; 
        }

        ll mid = (s+e)/2; 

        buildMinTree(s, mid, 2*index); 
        buildMinTree(mid+1, e, 2*index+1); 

        mintree[index] = min(mintree[2*index], mintree[2*index+1]); 
        return; 
    }

    ll minquery(ll s, ll e, ll l, ll r, ll index)
    {
        if(s>=l and e <=r)
        {
            return mintree[index]; 
        }
        if(s>r or e<l) return INT_MAX; 

        ll mid = (s+e)/2; 

        ll left = minquery(s, mid, l, r, 2*index); 
        ll right = minquery(mid+1, e, l, r, 2*index+1); 
        return min(left, right);
    }

    void buildMaxTree(ll s, ll e, ll index)
    {
        if(s==e)
        {
            maxtree[index] = ar[s];
            return; 
        }

        ll mid = (s+e)/2; 

        buildMaxTree(s, mid, 2*index); 
        buildMaxTree(mid+1, e, 2*index+1); 

        maxtree[index] = max(maxtree[2*index], maxtree[2*index+1]); 

        return; 
    }


    ll maxquery(ll s, ll e, ll l, ll r, ll index)
    {
        if(s>=l and e <=r)
        {
            return maxtree[index]; 
        }
        if(s>r or e<l) return INT_MIN; 

        ll mid = (s+e)/2; 

        ll left = maxquery(s, mid, l, r, 2*index); 
        ll right = maxquery(mid+1, e, l, r, 2*index+1); 
        return max(left, right);
    }


    void solve()
    {
        ll n, k;
        cin >> n >> k;
        memset(mintree, 0, sizeof(mintree)); 
        memset(maxtree, 0, sizeof(maxtree)); 
        for (int i = 1; i <= n; i++)
            cin >> ar[i];
        
        buildMinTree(1, n, 1); 
        buildMaxTree(1, n, 1); 
        ll ans = 0; 

        for(int i=1;i<=n; i++)
        {
            ll l = minquery(1, n, i, min(i+k-1, n), 1); 
            ll r = maxquery(1, n, i, min(i+k-1, n), 1); 

            ans = max(ans, r-l) ; 
        }

        cout << ans << endl; 
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll tc = 1;
        cin >> tc;
        for (ll t = 1; t <= tc; t++)
        {
            cout << "Case " << t << ": "; 
            solve();
        }
        return 0;
    }