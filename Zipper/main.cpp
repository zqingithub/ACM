#include<iostream>
#include<string>
using namespace std;

bool recSolu(int ** store,int x, int y,string & s1,string & s2,string & s3)
{

	if(x>0&&s3[x+y-1]==s1[x-1])
	{
		if(store[x-1][y]==0)
		{
			if(recSolu(store,x-1,y,s1,s2,s3))
				store[x-1][y]=1;
			else
				store[x-1][y]=2;
		}
		if(store[x-1][y]==1)
			return true;
	}

	if(y>0&&s3[x+y-1]==s2[y-1])
	{
		if(store[x][y-1]==0)
		{
			if(recSolu(store,x,y-1,s1,s2,s3))
				store[x][y-1]=1;
			else
				store[x][y-1]=2;
		}
		if(store[x][y-1]==1)
			return true;
	}

	return false;
}

bool Solu(string s1,string s2,string s3)
{
	int ** store=new int*[s1.length()+1];
	for(int i=0;i<s1.length()+1;++i)
	{
		store[i]=new int[s2.length()+1];
		for(int k=0;k<s2.length()+1;++k)
			store[i][k]=0;
	}
	store[0][0]=1;
	bool out=recSolu(store,s1.length(),s2.length(),s1,s2,s3);
	for(int i=0;i<s1.length()+1;++i)
		delete [] store[i];
	delete [] store;
	return out;
}

int main()
{
	int n,i;
	cin>>n;
	i=0;
	while(i++<n)
	{
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		cout<<"Data set "<<i<<": ";
		if(Solu(s1,s2,s3))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}