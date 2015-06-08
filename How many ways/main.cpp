#include<iostream>
using namespace std;

const int maxN=104;
int board[104][104];
int store[104][104];

int recHowMany(int const x,int const y,const int n,const int m)
{
	if(store[x][y]>=0)
		return store[x][y];
	store[x][y]=0;
	for(int i=y;i<=y+board[x][y]&&i<=m;++i)
		for(int j=x;j<=x+board[x][y]-i+y&&j<=n;++j)
			store[x][y]=(store[x][y]+recHowMany(j,i,n,m))%10000;
	return store[x][y];
}

int howMany(const int n,const int m)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			store[i][j]=-1;
	store[n][m]=1;
	return recHowMany(1,1,n,m);
}

int main()
{
	int T,n,m;
	cin>>T;
	while(T-->0)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>board[i][j];
		cout<<howMany(n,m)<<endl;
	}
	return 0;
}