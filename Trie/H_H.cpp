#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;


class Node{
public:
    char data; 
    int freq; 
    unordered_map<char, Node*> children; 
    bool terminal; 

    Node(char d)
    {
        data = d; 
        freq = 1; 
        terminal = false; 
    }
};


class Trie{
public: 
    Node* root; 

    Trie()
    {
        root = new Node('\0'); 
    }

    void insert(string &s)
    {
        Node* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(temp->children.count(s[i])) temp = temp->children[s[i]], temp->freq++; 
            else 
            {
                Node* n = new Node(s[i]); 
                temp->children[s[i]] = n; 
                temp = n; 
            }
        }
        temp->terminal = true; 
    }

    void find(string &s)
    {
        Node* temp = root; 
        string ans; 
        bool ok = false; 
        for(int i=0;i<(int)s.size(); i++)
        {
            temp = temp->children[s[i]]; 
            ans.push_back(s[i]);
            if(temp->freq==1) 
            {
                ok = true; 
                break;
            }
        }
        cout << s << ' ' << ans << endl;  
    }
    
    void del(Node* root)
    {
        Node* temp = root; 
        for(char ch = 'a'; ch<='z'; ch++)
        {
            if(temp->children.count(ch)) 
            {
                root = temp->children[ch];
                del(root);
            }
        }
        delete(temp);
    }
};


void solve()
{
    vector<string> v; 
    Trie tr; 
    string s; 
    while(cin >> s)
    {
        v.push_back(s); 
        tr.insert(s);
    }

    for(auto i: v) tr.find(i); 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}