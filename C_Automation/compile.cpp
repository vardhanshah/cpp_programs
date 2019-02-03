#include<bits/stdc++.h>

using namespace std;

int main(int args,char *argv[])
{
    for(int i=1;i<args;i++)
    {
         int j=0;
         string runName;
         while(argv[i][j]!='.')
            runName+=argv[i][j++];
        string cmd = "g++ -std=c++17 -o " + runName + " " + argv[i];
        system(cmd.c_str());
    }
    return 0;
}
