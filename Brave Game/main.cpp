#include<iostream>
using namespace std;

int main()
{
	int time,n,m;
	cin>>time;
	while(time-->0)
	{
		cin>>n>>m;
		if(n%(m+1)==0)
			cout<<"second"<<endl;
		else
			cout<<"first"<<endl;
	}
	return 0;
}