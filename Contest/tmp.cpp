#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n, m, i, j, k, l;
        cin >> n; // n input
        long long a[43];
        string s; // s input
        for (i = 0; i < 33; i++)
            a[i] = 0;
        cin >> s;
        for (i = 0; i < n; i++)
        {
            a[s[i] - 'a']++; // character frequency
        }
        vector<pair<long long, long long>> v;
        for (i = 0; i < 26; i++)
        {
            v.push_back({a[i], i}); // frequency gula pair e nise
        }
        // for(auto t:v)cout<<t.first<<" "<<t.second<<"\n";
        long long mx = -1, ans = -1, can = 0;
        sort(v.rbegin(), v.rend()); // choto theke boro sort korse
        for (i = 1; i <= 26; i++)
        {
            if (n % i == 0)
            {
                long long nochange = 0;
                can = n / i; // protita character koy bar thakbe
                for (j = 0; j < i; j++)
                {
                    nochange += min(can, v[j].first);
                }
                //	cout<<nochange<<endl;
                if (nochange > mx)
                {
                    mx = nochange;
                    ans = i;
                }
            }
        }
        //	cout<<mx<<endl;
        cout << n - mx << "\n";
        long long cann[44], need[44];
        for (i = 0; i < 26; i++)
            need[i] = 0;
        for (i = 0; i < 26; i++)
            cann[i] = 0;
        for (i = 0; i < ans; i++)
        {
            cann[v[i].second] = min(v[i].first, n / ans);
            need[v[i].second] = max(0ll, (n / ans) - cann[v[i].second]);
        }

        for (i = 0; i < n; i++)
        {
            if (cann[s[i] - 'a'] > 0)
            {
                cout << s[i];
                cann[s[i] - 'a']--;
            }
            else
            {
                for (j = 0; j < 26; j++)
                {
                    if (need[j] > 0)
                    {
                        need[j]--;
                        cout << (char)(j + 'a');
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }
}