#include<iostream>
#include<iomanip>
using namespace std;

double graph[1004][1004];
void safe(const int N)
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			for(int k=1;k<=N;++k)
				if(graph[j][k]<graph[j][i]*graph[i][k])
					graph[j][k]=graph[j][i]*graph[i][k];
}

int main()
{
	int N,T,s,e;
	cout<<setprecision(3)<<fixed;
	while(cin>>N)
	{
		for(int i=1;i<=N;++i)
			for(int k=1;k<=N;++k)
				scanf("%lf",&graph[i][k]);
		safe(N);
		cin>>T;
		while(T-->0)
		{
			cin>>s>>e;
			if(graph[s][e]>0)
				cout<<graph[s][e]<<endl;
			else
				cout<<"What a pity!"<<endl;
		}
	} 
	return 0;
}