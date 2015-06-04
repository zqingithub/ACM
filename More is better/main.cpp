#include<iostream>
using namespace std;

const int totalN=10000004;
int set[totalN];

void init()
{
	for(int i=0;i<totalN;++i)
		set[i]=-1;
}

int getSet(const int index)
{
	if(set[index]<0)
		return index;
	set[index]=getSet(set[index]);
	return set[index];
}

void unitSet(const int n1,const int n2)
{
	int setID1=getSet(n1),setID2=getSet(n2);
	if(setID1!=setID2)
	{
		set[setID1]+=set[setID2];
	    set[setID2]=setID1;
	}
}

int findMax(const int MaxID)
{
	int Max=1;
	for(int i=0;i<=MaxID;++i)
		if(set[i]<0&&-set[i]>Max)
			Max=-set[i];
	return Max;
}

int main()
{
	int count,MaxID,n1,n2;
	while(cin>>count)
	{
		init();
		MaxID=0;
		while(count-->0)
		{
			cin>>n1>>n2;
			if(n1>MaxID) MaxID=n1;
			if(n2>MaxID) MaxID=n2;
			unitSet(n1,n2);
		}
		cout<<findMax(MaxID)<<endl;
	}
	return 0;
}