#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(vector<pair<double, pair<ll, double>>> vp)
{
    vector<double> execution;
    double sum = 0;
    for (auto i : vp)
        execution.push_back(i.second.second), sum += i.second.second;
    double mean = sum / (vp.size());
    double median;
    if (vp.size() % 2)
    {
        median = execution[vp.size() / 2];
    }
    else
        median = (execution[vp.size() / 2] + execution[vp.size() / 2 - 1]) / 2.0;
    return (ll)round(sqrt((median * mean) / 2.0));
}

void solve()
{
    ll n;
    cout << "Number of Input: ";
    cin >> n;
    vector<pair<double, pair<ll, double>>> vp, dp;
    for (int i = 0; i < n; i++)
    {
        ll p, a, e;
        cout << "Process :";
        cin >> p;
        cout << "Arrival :";
        // ll a;
        cin >> a;
        cout << "Execution time :";
        // ll e;
        cin >> e;
        vp.push_back({a, {p, e}});
    }
    dp = vp;

    ll tq = fun(vp);

    sort(vp.begin(), vp.end());
    ll t = vp[0].first;
    cout << t << ' ';
    // 3double waiting

    double finalEx[n + 1];

    while (1)
    {
        for (int i = 0; i < (int)vp.size(); i++)
        {
            double x = min(double(tq), vp[i].second.second);
            cout << "P" << vp[i].second.first << ' ' << t + x << ' ';
            finalEx[vp[i].second.first] = t + x;
            vp[i].second.second = max(double(0), vp[i].second.second - tq);
            if (vp[i].second.second == 0)
                vp.erase(vp.begin() + i);
            t += x;
        }

        if (vp.empty())
        {
            break;
        }
        sort(vp.begin(), vp.end());
        tq = fun(vp);
    }
    double waiting[n + 1] = {0}, turnaroun[n + 1] = {0};
    for (auto i : dp)
        waiting[i.second.first] = finalEx[i.second.first] - i.second.second - i.first, turnaroun[i.second.first] = finalEx[i.second.first] - i.second.first;

    double w = 0, tt = 0;
    cout << endl;
    for (int i = 1; i <= n; i++)
        w += waiting[i], tt += turnaroun[i];
    
    cout << "Average waiting time :" << w / n << endl;
    cout << "Average turnaround time :" << tt / n << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}