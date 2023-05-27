#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Trie
{
  public:
    bool endmark;
    Trie *next[26];

    Trie()
    {
        endmark=false;
        for(int i=0;i<25; i++)
        {
            this->next[i]=NULL;
        }
    }

    void Insert(Trie *root,string s);

    bool Search(Trie *root,string s);

    void Delete(Trie *curr);

};

void Trie::Insert(Trie *root,string s)
{
    Trie *temp=root;
    for(int i=0;i<(int)s.size(); i++)
    {
        if(temp->next[s[i]-'a']==NULL)
        {
            temp->next[s[i]-'a']=new Trie();
        }
        temp=temp->next[s[i]-'a'];
    }
    temp->endmark=true;
}

bool Trie::Search(Trie *root,string s)
{
    Trie *temp=root;
    for(int i=0;i<(int)s.size(); i++)
    {
        if(temp->next[s[i]-'a']==NULL)
        {
            return false;
        }
        temp=temp->next[s[i]-'a'];
    }
    return temp->endmark;
}

void Trie::Delete(Trie *curr)
{
    for(int i=0; i<25; i++)
    {
        if(curr->next[i])
        {
            Delete(curr->next[i]);
        }
    }
    delete(curr);
}


void solve()
{
    
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