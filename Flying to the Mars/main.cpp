#include<iostream>
#include<map>
using namespace std;

int solu(const int n)
{
	map<int,int> count;
	int temp;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&temp);
		count[temp]+=1;
	}
	map<int,int>::iterator ite=count.begin();
	int max=1;
	while(ite!=count.end())
	{
		if(ite->second>max)
			max=ite->second;
		++ite;
	}
	return max;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<solu(n)<<endl;
	}
	return 0;
}