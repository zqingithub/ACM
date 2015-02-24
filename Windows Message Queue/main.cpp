#include<iostream>
#include<string>
#include<list>
#include<queue>
using namespace std;

class Task
{
public:
	string msg;
	int para;
	int prior;
	int order;
	Task(string msg,int para,int prior,int order):msg(msg),para(para),prior(prior),order(order)
	{
	}
	class cmp
	{
	public:
		bool operator ()(const Task& A,const Task& B)
		{
			if(A.prior==B.prior)
				return A.order>B.order;
			return A.prior>B.prior;
		}
	};
};

int main()
{
	priority_queue<Task,vector<Task>,Task::cmp> TaskQueue;
	string com;
	string msg;
	int para;
	int prior;
	int order=0;
	while(cin>>com)
	{
		if(com=="GET")
		{
			if(TaskQueue.empty())
				cout<<"EMPTY QUEUE!"<<endl;
			else
			{
				cout<<TaskQueue.top().msg<<" "<<TaskQueue.top().para<<endl;
				TaskQueue.pop();
			}
		}
		if(com=="PUT")
		{
			cin>>msg>>para>>prior;
			TaskQueue.push(Task(msg,para,prior,order++));
			TaskQueue.empty();
		}
	}
	return 0;
}