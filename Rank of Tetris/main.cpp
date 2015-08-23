#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int maxN=10004;
const int maxM=20004;
int obj1[maxM];
int obj2[maxM];
char relate[maxM];
int set[maxN];
int countIn[maxN];
vector<int> link[maxN];
int find(const int x)
{
    if(x==set[x])
        return x;
    else
    {
        set[x]=find(set[x]);
        return set[x];
    }
}
void unit(const int x,const int y)
{
    set[find(x)]=find(y);
}
void inti(const int n,const int m)
{
    for(int i=0;i<n;++i)
    {
        set[i]=i;
        link[i].clear();
        countIn[i]=0;
    }
    for(int i=0;i<m;++i)
    {
        if(relate[i]=='=')
        {
            unit(obj1[i], obj2[i]);
        }
    }
    for(int i=0;i<m;++i)
    {
        if(relate[i]=='>')
        {
            link[find(obj1[i])].push_back(find(obj2[i]));
            ++countIn[find(obj2[i])];
        }
        if(relate[i]=='<')
        {
            link[find(obj2[i])].push_back(find(obj1[i]));
            ++countIn[find(obj1[i])];
        }
    }
    
}
string isOk(const int n)
{
    queue<int> myque;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(find(i)==i)
        {
            ++sum;
            if(countIn[i]==0)
                myque.push(i);
        }
    }
    bool isUnique=true;
    while(!myque.empty())
    {
        if(myque.size()>1)
            isUnique=false;
        int front=myque.front();
        myque.pop();
        --sum;
        for(int i=0;i<link[front].size();++i)
        {
            --countIn[link[front][i]];
            if(countIn[link[front][i]]==0)
                myque.push(link[front][i]);
        }
    }
    if(sum==0)
    {
        if(!isUnique)
            return "UNCERTAIN";
        return "OK";
    }
    else
        return "CONFLICT";
}

int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        for(int i=0;i<m;++i)
        {
            cin>>obj1[i]>>relate[i]>>obj2[i];
        }
        inti(n, m);
        cout<<isOk(n)<<endl;
    }
    return 0;
}