#include<iostream>
using namespace std;

typedef long long doubleLong;
#define ABS(x) (x)>0?(x):-(x)
doubleLong L[4];
doubleLong cost[4];
const doubleLong inf=1e18;
doubleLong map[107][107];
doubleLong x[107];
doubleLong getCost(const doubleLong distance)
{
    if(distance<=L[0])
        return cost[0];
    if(distance<=L[1])
        return cost[1];
    if(distance<=L[2])
        return cost[2];
    if(distance<=L[3])
        return cost[3];
    return inf;
}

void floyd(const int n)
{
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
        }
    }
}

int main()
{
    int caseN,n,m;
    cin>>caseN;
    for(int i=1;i<=caseN;++i)
    {
        for(int j=0;j<4;++j)
        {
            cin>>L[j];
        }
        for(int j=0;j<4;++j)
        {
            cin>>cost[j];
        }
        cin>>n>>m;
        for(int j=0;j<n;++j)
        {
            cin>>x[j];
            map[j][j]=0;
            for(int k=0;k<j;++k)
            {
                map[j][k]=map[k][j]=getCost(ABS(x[k]-x[j]));
            }
        }
        floyd(n);
        cout<<"Case "<<i<<":"<<endl;
        for(int j=0;j<m;++j)
        {
            int s1,s2;
            cin>>s1>>s2;
            if(map[s1-1][s2-1]!=inf)
            {
                cout<<"The minimum cost between station "<<s1<<" and station "<<s2<<" is "<<map[s1-1][s2-1]<<"."<<endl;
            }
            else
            {
                cout<<"Station "<<s1<<" and station "<<s2<<" are not attainable."<<endl;
            }
        }
    }
    return 0;
}
