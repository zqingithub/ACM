#include<iostream>
using namespace std;

unsigned int store[1000004];

int countWin(const int n)
{
	unsigned int temp=0;
	for(int i=0;i<n;++i)
		temp^=store[i];
	if(temp==0)
		return 0;
	int highest=0;
	while(temp!=0)
	{
		++highest;
		temp>>=1;
	}
	unsigned int max=1;
	while(--highest>0)
		max<<=1;
	int count=0;
	for(int i=0;i<n;++i)
		if((store[i]&max)!=0)
			++count;
	return count;
}

int main()
{
	int n;
	while(cin>>n,n!=0)
	{
		for(int i=0;i<n;++i)
			cin>>store[i];
		cout<<countWin(n)<<endl;
	}
	return 0;
}