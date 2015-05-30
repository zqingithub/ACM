#include<iostream>
using namespace std;

int set[2004];
int state[2004];

int findSet(const int no)
{
	if(set[no]==-1)
		return no;
	if(set[set[no]]==-1)
		return set[no];
	int temp=set[no];
	set[no]=findSet(set[no]);
	if(state[no])
		state[no]=state[temp];
	else
		state[no]=!state[temp];
	return set[no];
}

void unit(const int n1,const int n2)
{
	int set1=findSet(n1);
	int set2=findSet(n2);
	set[set1]=set2;
	if(state[n1]==state[n2])
		state[set1]=false;
	else
		state[set1]=true;
}

bool solu(int const n,int const act)
{
	for(int i=0;i<=n;++i)
	{
		state[i]=true;
		set[i]=-1;
	}
	int n1,n2;
	bool outcome=true;
	for(int i=0;i<act;++i)
	{
		cin>>n1>>n2;
		if(true)
		{
			if(findSet(n1)==findSet(n2))
			{
				if(state[n1]==state[n2])
					outcome=false;
			}
			else
				unit(n1,n2);
		}
	}
	return outcome;
}

int main()
{
	int count,no=0,n,act;
	cin>>count;
	while(no++<count)
	{
		cin>>n>>act;
		cout<<"Scenario #"<<no<<":"<<endl;
		if(solu(n,act))
			cout<<"No suspicious bugs found!\n"<<endl;
		else
			cout<<"Suspicious bugs found!\n"<<endl;
	}
	
	return 0;
}