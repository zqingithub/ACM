#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int Size=21;
int map[Size][Size];
bool state[Size][Size];

struct pos
{
	int x;
	int y;
	pos(){}
	pos(const int x,const int y):x(x),y(y)
	{
	}
};

int Count(const int W,const int H,const int x,const int y)
{
	for(int i=0;i<H;++i)
		for(int k=0;k<W;++k)
			state[i][k]=true;
	int Sum=0;
	queue<pos> myque;
	myque.push(pos(x,y));
	state[x][y]=false;
	while(!myque.empty())
	{
		++Sum;
		pos temp=myque.front();
		myque.pop();
		if(temp.x-1>=0&&state[temp.x-1][temp.y]&&1==map[temp.x-1][temp.y])
		{
			myque.push(pos(temp.x-1,temp.y));
			state[temp.x-1][temp.y]=false;
		}
		if(temp.x+1<H&&state[temp.x+1][temp.y]&&1==map[temp.x+1][temp.y])
		{
			myque.push(pos(temp.x+1,temp.y));
			state[temp.x+1][temp.y]=false;
		}
		if(temp.y-1>=0&&state[temp.x][temp.y-1]&&1==map[temp.x][temp.y-1])
		{
			myque.push(pos(temp.x,temp.y-1));
			state[temp.x][temp.y-1]=false;
		}
		if(temp.y+1<W&&state[temp.x][temp.y+1]&&1==map[temp.x][temp.y+1])
		{
			myque.push(pos(temp.x,temp.y+1));
			state[temp.x][temp.y+1]=false;
		}
	}
	return Sum;
}

int main()
{
	int W,H,x,y;
	string temp;
	while(cin>>W>>H,W>0)
	{
		for(int i=0;i<H;++i)
		{
			cin>>temp;
			for(int k=0;k<W;++k)
			{
				if('.'==temp[k])
					map[i][k]=1;
				if('#'==temp[k])
					map[i][k]=0;
				if('@'==temp[k])
				{
					x=i;
					y=k;
				}
			}
		}
		cout<<Count(W,H,x,y)<<endl;
	}
	return 0;
}