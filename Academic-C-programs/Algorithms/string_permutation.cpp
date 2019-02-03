#include<bits/stdc++.h>
#include<time.h>
using namespace std;
void recpermutation(string sofar,string rest)
{
    if(rest == "")
        cout << sofar << endl;
    else
    {
        for(int i=0;i<rest.length();i++)
        {
            string next = sofar + rest[i];
            string remaining = rest.substr(0,i) + rest.substr(i+1);
            recpermutation(next,remaining);
        }
    }
}



int main()
{
    clock_t t;
    string a;
    string s = "ABCDE";
    t=clock();
    recpermutation(a,s);
    t=clock();
    cout << "It took me " << ((float)t/CLOCKS_PER_SEC);
}
