#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    cout << "Enter the number of processes: ";
    ll totalProcess;
    cin >> totalProcess;
    cout << "Enter total instances of resource A: ";
    ll R1;
    cin >> R1;
    cout << "Enter total instances of resource B: ";
    ll R2;
    cin >> R2;
    cout << "Enter total instances of resource C: ";
    ll R3;
    cin >> R3;
    ll allocation[totalProcess][3], maxNeed[totalProcess][3], currentNeed[totalProcess][3], availabeR1, availabeR2, availabeR3;
    cout << "Enter the allocation table: \n";
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> allocation[i][j];
    }

    cout << "Enter the max need table: \n";
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> maxNeed[i][j];
            currentNeed[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    availabeR1 = R1, availabeR2 = R2, availabeR3 = R3;
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                availabeR1 -= allocation[i][j];
            else if (j == 1)
                availabeR2 -= allocation[i][j];
            else
                availabeR3 -= allocation[i][j];
        }
    }

    // cout << availabeR1 << ' '  << availabeR2 << ' ' << availabeR3 << endl;
    // cout << R1 << ' ' << R2 << ' ' << R3 << endl;

    cout << "Enter number of request: ";
    ll tc;
    cin >> tc;
    while (tc--)
    {
        cout << "Enter the requested process number: ";
        ll p;
        cin >> p;
        cout << "Enter Ra: ";
        ll Ra;
        cin >> Ra;
        cout << "Enter Rb: ";
        ll Rb;
        cin >> Rb;
        cout << "Enter Rc: ";
        ll Rc;
        cin >> Rc;

        if ((Ra <= currentNeed[p][0] and Rb <= currentNeed[p][1] and Rc <= currentNeed[p][2]) and (Ra <= availabeR1 and Rb <= availabeR2 and Rc <= availabeR3))
        {
            ll dummyAllocation[totalProcess][3], dummyMaxNeed[totalProcess][3], dummyCurrentNeed[totalProcess][3], dummyAvailabeR1, dummyAvailabeR2, dummyAvailabeR3;
            for (int i = 0; i < totalProcess; i++)
            {
                for (int j = 0; j < 3; j++)
                    dummyAllocation[i][j] = allocation[i][j], dummyMaxNeed[i][j] = maxNeed[i][j], dummyCurrentNeed[i][j] = currentNeed[i][j];
            }

            dummyAvailabeR1 = availabeR1 - Ra, dummyAvailabeR2 = availabeR2 - Rb, dummyAvailabeR3 = availabeR3 - Rc;

            dummyAllocation[p][0] += Ra, dummyCurrentNeed[p][0] -= Ra;
            dummyAllocation[p][1] += Rb, dummyCurrentNeed[p][1] -= Rb;
            dummyAllocation[p][2] += Rc, dummyCurrentNeed[p][2] -= Rc;

            vector<ll> safesequence;
            vector<bool> isSafe(totalProcess, false);
            for (int i = 0; i < totalProcess; i++)
            {
                for (int j = 0; j < totalProcess; j++)
                {
                    if (isSafe[j] == false)
                    {
                        if (dummyAvailabeR1 >= dummyCurrentNeed[j][0] and dummyAvailabeR2 >= dummyCurrentNeed[j][1] and dummyAvailabeR3 >= dummyCurrentNeed[j][2])
                        {
                            dummyAvailabeR1 += dummyAllocation[j][0];
                            dummyAvailabeR2 += dummyAllocation[j][1];
                            dummyAvailabeR3 += dummyAllocation[j][2];
                            isSafe[j] = true;
                            safesequence.push_back(j);
                        }
                    }
                }
            }

            if (count(isSafe.begin(), isSafe.end(), true) == totalProcess)
            {
                for (auto i : safesequence)
                    cout << "P" << i << ' ';
                cout << endl;

                for (int i = 0; i < totalProcess; i++)
                {
                    for (int j = 0; j < 3; j++)
                        allocation[i][j] = dummyAllocation[i][j], currentNeed[i][j] = dummyCurrentNeed[i][j];
                }
                availabeR1 -= Ra, availabeR2 -= Rb, availabeR3 -= Rc;
            }
            else
                cout << "Request Cannot be granted immediately.\n";
            cout << endl;
        }
        else
        {
            cout << "Request can't be granted!\n";
        }
    }
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