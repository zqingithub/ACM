#include<iostream>  
#define LL long long  
using namespace std;  
LL Solu(LL * store,int n)
{
	LL  * left=new LL [n];
	LL  * right=new LL [n];
	left[0]=0;
	for(int i=1;i<n;++i)
	{
		int temp=i;
		while(temp>0&&store[temp-1]>=store[i])
			temp=left[temp-1];
		left[i]=temp;
	}
	right[n-1]=n-1;
	for(int i=n-2;i>=0;--i)
	{
		int temp=i;
		while(temp<n-1&&store[temp+1]>=store[i])
			temp=right[temp+1];
		right[i]=temp;
	}
	LL max=0;
	for(int i=0;i<n;++i)
	{
		LL temp=store[i]*(right[i]-left[i]+1);
		if(temp>max)
			max=temp;
	}
	return max;
}

int main()
{
	int n;
	while(cin>>n,n>0)
	{
		LL * store=new LL[n];
		for(int i=0;i<n;++i)
			cin>>store[i];
		cout<<Solu(store,n)<<endl;
		delete [] store;
	}
	return 0;
}