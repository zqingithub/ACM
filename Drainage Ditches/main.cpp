#include<iostream>
#include<set>
#include<queue>
using namespace std;

int Solu(int ** fig,const int V)
{
	int Max=0;
	int flow=0;
	set<int> isVis;
	vector<int> store(V);
	do
	{
		queue<int> BFS;
		isVis.insert(0);
		BFS.push(0);
		int index=0;
		while(!BFS.empty())
		{
			int temp=BFS.front();
			for(int i=0;i<V;++i)
			{
				if(fig[temp][i]==0||isVis.find(i)!=isVis.end())
					continue;
				isVis.insert(i);
				store[i]=temp;
				if(i==V-1)
				{
					index=V-1;
					break;
				}
				else
					BFS.push(i);
			}
			BFS.pop();
			if(index>0)
				break;

		}
		if(index==0)
			flow=0;
		else
		{
			int min_value=10000002;
			int temp=index;
			while(temp>0)
			{
				int front=store[temp];
				if(fig[front][temp]<min_value)
					min_value=fig[front][temp];
				temp=front;
			}
			flow=min_value;
			temp=index;
			while(temp>0)
			{
				int front=store[temp];
				fig[front][temp]-=flow;
				fig[temp][front]+=flow;
				temp=front;
			}
		}
		isVis.clear();
		Max+=flow;
	}while(flow>0);
	return Max;
}

int main()
{
	int E,V;
	while(cin>>E)
	{
		cin>>V;
		int ** fig=new int*[V];
		for(int i=0;i<V;++i)
		{
			fig[i]=new int[V];
			for(int k=0;k<V;++k)
				fig[i][k]=0;
		}
		int s,e,c;
		for(int i=0;i<E;++i)
		{
			cin>>s>>e>>c;
			fig[s-1][e-1]+=c;
		}
		cout<<Solu(fig,V)<<endl;
		for(int i=0;i<V;++i)
			delete [] fig[i];
		delete [] fig;
	}
	return 0;
}