#include<iostream>
using namespace std;

int solu(const int m,const int n,const int *gender)
{
	int sum=0;
	int store=1;
	int count=0;
	while(count<n&&count<m&&gender[count]==0)++count;
	if(count<m)
		++count;
	for(;count<n;++count)
	{
		sum+=store;
		store<<=1;
	}
	return sum;
}

int main()
{
	int T,m,n,temp;
	int gender[34];
	cin>>T;
	while(T-->0)
	{
		cin>>m>>n;
		for(int i=0;i<n;++i)
			cin>>gender[i];
		temp=solu(m,n,gender);
		if(temp==0)
			cout<<0<<" RMB"<<endl;
		else
			cout<<temp<<"0000 RMB"<<endl;
	}
	return 0;
}