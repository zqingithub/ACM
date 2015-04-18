#include<iostream>
#include<queue>
using namespace std;

struct floor
{
	int up;
	int down;
	static const int no;
	floor():up(no),down(no)
	{}
};
const int floor::no=-1;
floor graph[202];
bool state[202];

int minStep(const int start,const int end,const int n)
{
	if(start<1||end>n)
		return -1;
	for(int i=1;i<=n;++i)
		state[i]=false;
	int min=0;
	queue<int> myque;
	myque.push(start);
	myque.push(floor::no);
	state[start]=true;
	while(!myque.empty())
	{
		int temp=myque.front();
		myque.pop();
		if(floor::no==temp)
		{
			if(!myque.empty())
			{
				++min;
				myque.push(floor::no);
			}
		}
		else
		{
			if(end==temp)
				return min;
			if(floor::no!=graph[temp].up&&!state[graph[temp].up])
			{
				myque.push(graph[temp].up);
				state[graph[temp].up]=true;
			}
			if(floor::no!=graph[temp].down&&!state[graph[temp].down])
			{
				myque.push(graph[temp].down);
				state[graph[temp].down]=true;
			}
		}
	}
	return -1;


}

int main()
{
	int n,start,end,temp;
	while(cin>>n,n>0)
	{
		cin>>start>>end;
		for(int i=1;i<=n;++i)
		{
			cin>>temp;
			graph[i].up=i+temp>n?floor::no:i+temp;
			graph[i].down=i-temp<1?floor::no:i-temp;
		}
		cout<<minStep(start,end,n)<<endl;
	}
	return 0;
}



