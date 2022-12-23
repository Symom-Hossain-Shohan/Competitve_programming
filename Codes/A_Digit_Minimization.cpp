    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    void solve()
    {
        string s ;
        cin >> s ;
        if(s.size()==2) cout << s[1] << endl; 
        else 
        {
            sort(s.begin(), s.end());
            cout << s[0] << endl; 
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        ll tc=1;
        cin >> tc;
        for(ll t=1;t<=tc;t++)
        {
            solve();
        }
        return 0;
    }