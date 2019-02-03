#include <bits/stdc++.h>
using namespace std;
#define ford(i,s,e) for(int i=s;i<e;i++)

struct node{
    int cnt;
    node *next[26];
    bool end;
};

node *construct()
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->cnt=0;
    tmp->end=0;
    ford(i,0,26)
        tmp->next[i]=NULL;
    return tmp;
}

void add(string s,node **head_rf)
{
    node *ndum = *head_rf;
    int numb;
    ford(i,0,s.length())
    {
        numb = s[i]-'a';
        if(ndum->next[numb]==NULL)
            ndum->next[numb]=construct();
        ndum=ndum->next[numb];
    }
    ndum->end=1;
    ndum->cnt++;
    //cout << s << " " << ndum->cnt << endl;
}
int search(string s,node *head)
{
    int numb;
    ford(i,0,s.length())
    {
        numb=s[i]-'a';
        if(head->next[numb]==NULL)
            return 0;
        head=head->next[numb];
    }
    if(head->end==1)
        return head->cnt;
    return 0;
}
bool to_low(string &p)
{
    bool f=0;
    ford(i,0,p.length())
    {
        if(p[i]<'a')
        {
            p[i]=p[i]-'A'+'a';
            if(!(p[i]>='a'&&p[i]<='z'))
                p[i]='a';
            f=1;
        }
    }
    return f;
}
int main()
{
    string s;
    ifstream in("words.txt"); // your data file
    node *head = (node *)malloc(sizeof(node));
    while(in >> s)
    {
        to_low(s);
        add(s,&head);
    }
    while(1)
    {
        string s;
        int cnt=-1;
        cin >> s;
        if(to_low(s))
            cout << "Your input is updated to:  " << s << endl;
        if(s=="quit")
            break;
        ((cnt=search(s,head))>=1) ? (cout << "exists: " << cnt << " times" << endl) : (cout << "not exists" << endl);    
    }
    return 0;
}
