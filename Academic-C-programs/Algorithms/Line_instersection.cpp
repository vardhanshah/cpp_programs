#include<bits/stdc++.h>
using namespace std;

struct point{
    int x;int y;
    point(){}
    point(int a,int b)
    {
        x=a;y=b;
    }
    void input()
    {
        cin >> x >> y;
    }
};

bool OnTheSegment(point p,point q,point r)
{
    if(q.x<=max(p.x,r.x)&&q.x>=min(p.x,r.x)&&q.y>=max(p.y,r.y)&&q.y<=max(p.y,r.y))
        return true;
    return false;
}
int orientation(point p,point q,point r)
{
    int val=(q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);
    if(val==0)
        return 0;
    if(val>0)
        return 1;
    return 2;
}

bool isIntersection(point p1,point q1,point p2,point q2)
{
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);

    if(o1!=o2&&o3!=o4)
        return true;
    if(o1==0&&OnTheSegment(p1,p2,q1))
        return true;
    if(o2==0&&OnTheSegment(p1,q2,q1))
        return true;
    if(o3==0&&OnTheSegment(p2,p1,q2))
        return true;
    if(o4==0&&OnTheSegment(p2,q1,q2))
        return true;
    return false;
}

int main()
{
    //freopen("input","r",stdin);
    point p1,p2,q1,q2;
    p1.input();q1.input();p2.input();q2.input();
    if(isIntersection(p1,q1,p2,q2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
