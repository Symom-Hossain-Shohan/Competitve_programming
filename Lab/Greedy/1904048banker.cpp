#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll Rx, Ry, Rz;
    cout << "Give total resources: "; 
    cin >> Rx >> Ry >> Rz;
    vector<vector<ll>> alloc(3, vector<ll>(3)), currentNeed(3, vector<ll>(3));
    cout << "Enter the allocation table for 3 process\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> alloc[i][j];
    }
    cout << "Enter the current need table for 3 processe:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> currentNeed[i][j];
        }
    }

    ll Ax = Rx, Ay = Ry, Az = Rz;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == 0)
                Ax--;
            else if (j == 1)
                Ay--;
            else
                Az--;
        }
    }

    for (int t = 0; t < 2; t++)
    {
        cout << "Enter process no for request: ";
        ll p;
        cin >> p;
        cout << "Enter Reqx: ";
        ll rx;
        cin >> rx;
        cout << "Enter Reqy: ";
        ll ry;
        cin >> ry;
        cout << "Enter Reqz: ";
        ll rz;
        cin >> rz;

        vector<vector<ll>> alloc1(3, vector<ll>(3)), currentNeed1(3, vector<ll>(3));
        alloc1 = alloc, currentNeed1 = currentNeed;
        ll AAx = Ax, AAy = Ay, AAz = Az;

        if (currentNeed1[p][0] >= rx and currentNeed1[p][1] >= ry and currentNeed1[p][2] >= rz and Ax >= rx and Ay >= ry and Az >= rz)
        {
            alloc1[p][0] += rx, currentNeed1[p][0] -= rx, AAx -= rx;
            alloc1[p][1] += ry, currentNeed1[p][1] -= ry, AAy -= ry;
            alloc1[p][2] += rz, currentNeed1[p][1] -= rz, AAz -= rz;

            vector<ll> ans;
            vector<bool> finish(3, false);
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (currentNeed1[i][0] <= AAx and currentNeed1[i][1] <= AAy and currentNeed1[i][2] <= AAz and finish[i] == false)
                    {
                        ans.push_back(i);
                        AAx += alloc1[i][0], AAy += alloc1[i][1], AAz = alloc1[i][2];
                        finish[i] = true; 
                    }
                }
            }

            for(auto i: ans) cout << i << ' '; 
                cout << endl; 

            if (ans.size() == 3)
            {
                cout << "The safe sequence is: ";
                for (auto i : ans)
                    cout << "P" << i;
                cout << endl;
                alloc = alloc1;
                currentNeed = currentNeed1;
                Ax = AAx, Ay = AAy, Az = AAz;
                
            }
            else
                cout << "The request can't be immediately granted\n";
        }
        else
        {
            cout << "Request can't be granted at this moment!\n";
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}