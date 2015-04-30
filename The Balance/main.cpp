#include<iostream>
#include<cmath>
using namespace std;

int weight[104];
bool store1[10004];
bool store2[10004];

int solu(const int N,int &sum)
{
	sum=0;
	for(int i=1;i<=N;++i)
		sum+=weight[i];
	for(int i=1;i<=sum;++i)
		store1[i]=store2[i]=false;
	for(int i=1;i<=N;++i)
	{
		store2[weight[i]]=true;
		for(int j=1;j<=sum;++j)
			if(store1[j])
				store2[j]=store2[j+weight[i]]=store2[abs(j-weight[i])]=true;
		for(int j=1;j<=sum;++j)
		{
			store1[j]=store2[j];
			store2[j]=false;
		}
	}
	int count=0;
	for(int i=1;i<=sum;++i)
		if(!store1[i])
			++count;
	return count;
}

int main()
{
	int N,count,sum;
	while(cin>>N)
	{
		for(int i=1;i<=N;++i)
			cin>>weight[i];
		count=solu(N,sum);
		cout<<count<<endl;
		if(count>0)
		{
			for(int i=1;i<=sum;++i)
				if(!store1[i])
				{
					cout<<i;
					if(count-->1)
						cout<<" ";
				}
			cout<<endl;
		}
	}
	return 0;
}