#include<iostream>
using namespace std;
main()
{
    int a = 1, b = 2;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    *p1 = *p2;
    *p2 = 10;
    cout<<"results"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<*p1<<endl;
    cout<<p2<<endl;
    cout<<*p2<<endl;
    cout<<&p2<<endl;
}
