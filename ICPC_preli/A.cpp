#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    string s[3];
    vector<int>vc(n, 1);
    for(int i = 0; i < 3; i += 1){
        cin >> s[i];
    }
    for(int i = 0; i < n; i += 1){
        if(s[1][i] == 'X') vc[i] = 0;
    }
    
    deque<int>khela;
    for(int i = n - 1; i >= 0; i -= 1){
        if(!vc[i]) continue;
        int curr = 0;
        while(i >= 0 && vc[i]){
            curr += 1; i -= 1;
        }
        khela.push_back(curr);
    }

    int cnt = 0;
    while(!khela.empty()){
        int rem = khela.front(); khela.pop_front();
        bool first = 1, odd = 1;
        //cout << rem << ": ";
        while(rem > 0){
            if(first){
                if(rem >= 3) rem -= 3, cnt += 1, odd = !odd;
                else if(rem == 2) rem -= 2, cnt += 1;
                else rem -= 1;
                first = 0;
            }
            else{
                if(odd){
                    if(rem >= 3) rem -= 3, cnt += 1, odd = !odd;
                    else if(rem){
                        rem = 0; cnt += ((cnt & 1)?1: 0);
                    }
                    else rem = 0;
                }
                else{
                    if(rem >= 2) rem -= 2, cnt += 1, odd = !odd;
                    else if(rem > 1){
                        rem = 0; cnt += ((cnt & 1)?0: 1);
                    }
                    else rem = 0;
                }
            }
            //cout << rem << " ";
        }
        //cout << endl;
    }
    cout << ((cnt & 1)?"Jhinuk\n": "Grandma\n");
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i += 1){
        cout << "Case " << i << ": "; solve();
    }
    
    return 0;
}