#include<iostream>
using namespace std;
main()
{
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    cout<<p<<endl;
    --x;
    (*p) += x;
    cout<<p<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}
