#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=100004;
vector<int> storePrime[N];
void createPrime()
{
    bool isPrime[N];
    for(int i=0;i<N;++i)
        isPrime[i]=true;
    for(int i=2;i<N;++i)
    {
        if(isPrime[i])
        {
            for(int j=i;j<N;j+=i)
            {
                storePrime[j].push_back(i);
                isPrime[j]=false;
            }
        }
    }
}

long long getPart(const int target,const int which,const int Max)
{
    int time=-1;
    long long multi=1;
    for(int i=0;i<storePrime[target].size();++i)
    {
        if(((1<<i)&which)!=0)
        {
            time*=-1;
            multi*=storePrime[target][i];
        }
    }
    return Max/multi*time;
}

long long count(const int target,const int Max)
{
    long long outcome=0;
    int up=pow(2, storePrime[target].size());
    for(int i=1;i<up;++i)
    {
        outcome+=getPart(target, i, Max);
    }
    return outcome;
}

long long countAll(int a,int b)
{
    long long outcome=0;
    if(a>b)
        swap(a, b);
    for(int i=1;i<=b;++i)
    {
        outcome+=(min(i,a)-count(i,min(i,a)));
    }
    return outcome+1;
}

int main()
{
    createPrime();
    int n,a,b,k;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>a>>b>>b>>k;
        if(k!=0)
        {
            printf("Case %d: %I64d\n",i,countAll(a/k, b/k)-1);
        }
        else
        {
            cout<<"Case "<<i<<": "<<0<<endl;
        }
    }
    return 0;
}