#include<iostream>
using namespace std;

int store[14];
long long gcd(long long a,long long b)
{
    long temp;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

long long minCount(const long long n,const int m,int index)
{
    int sum=0;
    long long multi=1;
    for(int i=0;i<m;++i)
    {
        if(index&1)
        {
            ++sum;
            multi=lcm(multi,store[i]);
        }
        index>>=1;
    }
    if(sum&1)
        return (n-1)/multi;
    else
        return -((n-1)/multi);
}
long long count(const int n,const int m)
{
    long long total=0;
    for(int i=1;i<(1<<m);++i)
    {
        total+=minCount(n, m, i);
    }
    return total;
}

int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        int temp=0;
        for(int i=0;i<m;++i)
        {
            cin>>store[temp];
            if(store[temp]!=0)
                ++temp;
        }
        cout<<count(n,temp)<<endl;
    }
    return 0;
}
