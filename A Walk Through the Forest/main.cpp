#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Max=1000001;
vector<int> findShort(const vector<vector<int> > & forest)
{
	bool *state=new bool[forest.size()];
	int * store=new int[forest.size()];
	for(int i=0;i<forest.size();++i)
	{
		state[i]=false;
		store[i]=forest[i][1];
	}
	state[1]=true;
	for(int i=1;i<forest.size()-1;++i)
	{
		int index=0;
		while(state[index++]);
		--index;
		for(int k=index+1;k<forest.size();++k)
			if(!state[k]&&store[k]<store[index])
				index=k;
		state[index]=true;
		for(int k=0;k<forest.size();++k)
			if(store[index]+forest[index][k]<store[k])
				store[k]=store[index]+forest[index][k];
	}
	vector<int> out(store,store+forest.size());
	out[1]=0;
	delete [] store;
	delete [] state;
	return out;
}

int findAllPath(const vector<vector<int> >& forest,vector<bool> & state,const vector<int> & record,vector<int> & sum,int index)
{
	if(index==1)
		return 1;
	if(sum[index]>=0)
		return sum[index];
	int Sum=0;
	state[index]=true;
	for(int i=0;i<forest.size();++i)
	{
		if(!state[i]&&forest[index][i]<Max&&record[i]<record[index])
			Sum+=findAllPath(forest,state,record,sum,i);
	}
	state[index]=false;
	sum[index]=Sum;
	return Sum;
}

int main()
{
	int N,M;
	while(cin>>N,N!=0)
	{
		cin>>M;
		vector<vector<int> >forest;
		for(int i=0;i<N;++i)
		{
			forest.push_back(vector<int>());
			for(int k=0;k<N;++k)
				forest[i].push_back(Max);
		}
		int x,y,d;
		while(M-->0)
		{
			cin>>x>>y>>d;
			forest[x-1][y-1]=forest[y-1][x-1]=d;
		}
		vector<int> record=findShort(forest);
		vector<bool> state;
		vector<int> sum;
		for(int i=0;i<N;++i)
		{
			state.push_back(false);
			sum.push_back(-1);
		}
		cout<<findAllPath(forest,state,record,sum,0)<<endl;
	}
	return 0;
}