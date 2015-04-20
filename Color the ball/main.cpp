#include<iostream>
using namespace std;
struct Node
{
	int l;
	int r;
	int sum;
};

Node Tree[100004*3];
int Time[100004];

void create(const int l,const int r,const int root)
{
	Tree[root].l=l;
	Tree[root].r=r;
	Tree[root].sum=0;
	if(l!=r)
	{
		int mid=(l+r)/2;
		create(l,mid,root*2);
		create(mid+1,r,root*2+1);
	}
}

void insert(const int l,const int r,const int root)
{
	if(Tree[root].l==l&&Tree[root].r==r)
		Tree[root].sum+=1;
	else
	{
		int mid=(Tree[root].l+Tree[root].r)/2;
		if(r<=mid)
			insert(l,r,root*2);
		if(mid<l)
			insert(l,r,root*2+1);
		if(l<=mid&&mid<r)
		{
			insert(l,mid,root*2);
			insert(mid+1,r,root*2+1);
		}
	}
}

void out(const int root,int sum)
{
	if(Tree[root].l==Tree[root].r)
		Time[Tree[root].l]=sum+Tree[root].sum;
	else
	{
		sum+=Tree[root].sum;
		out(root*2,sum);
		out(root*2+1,sum);
	}
}

int main()
{
	int N,r,l;
	while(cin>>N,N>0)
	{
		create(1,N,1);
		for(int i=0;i<N;++i)
		{
			cin>>l>>r;
			insert(l,r,1);
		}
		out(1,0);
		cout<<Time[1];
		for(int i=2;i<=N;++i)
		{
			cout<<" "<<Time[i];
		}
		cout<<endl;
	}
	return 0;
}