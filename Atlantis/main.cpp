#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int N=204;
struct Node
{
	int l;
	int r;
	int sign;
	double sum;
};
struct line
{
	double l;
	double r;
	double y;
	int sign;
	bool operator<(const line &obj) const
	{
		return y<obj.y;
	}
};

double X[N];
Node Tree[N*3];
line store[N];
void create(const int l,const int r,const int root)
{
	Tree[root].l=l;
	Tree[root].r=r;
	Tree[root].sign=0;
	Tree[root].sum=0;
	if(l+1<r)
	{
		int mid=(l+r)/2;
		create(l,mid,root*2);
		create(mid,r,root*2+1);
	}
}

void insert(const int root,const line &L)
{
	if(X[Tree[root].l]==L.l&&X[Tree[root].r]==L.r)
		Tree[root].sign+=L.sign;
	else
	{
		int mid=(Tree[root].l+Tree[root].r)/2;
		line temp=L;
		if(X[mid]>=L.r)
			insert(root*2,temp);
		if(X[mid]<=L.l)
			insert(root*2+1,temp);
		if(X[mid]<L.r&&X[mid]>L.l)
		{
			temp.r=X[mid];
			insert(root*2,temp);
			temp.l=X[mid];
			temp.r=L.r;
			insert(root*2+1,temp);
		}
	}
	if(Tree[root].sign==0)
	{
		if(Tree[root].l+1==Tree[root].r)
			Tree[root].sum=0;
		else
			Tree[root].sum=Tree[root*2].sum+Tree[root*2+1].sum;
	}
	else
		Tree[root].sum=X[Tree[root].r]-X[Tree[root].l];
}

int main()
{
	int n,count,No=0;
	double x1,y1,x2,y2;
	while(cin>>n,n>0)
	{
		++No;
		count=1;
		while(n-->0)
		{
			cin>>x1>>y1>>x2>>y2;
			X[count]=x1;
			store[count].l=x1;
			store[count].r=x2;
			store[count].y=y2;
			store[count].sign=-1;
			++count;
			X[count]=x2;
			store[count].l=x1;
			store[count].r=x2;
			store[count].y=y1;
			store[count].sign=1;
			++count;
		}
		sort(X+1,X+count);
		sort(store+1,store+count);
		--count;
		create(1,count,1);
		insert(1,store[1]);
		double sum=0;
		for(int i=2;i<=count;++i)
		{
			sum+=(store[i].y-store[i-1].y)*Tree[1].sum;
			insert(1,store[i]);
		}
		cout<<"Test case #"<<No<<endl;
        cout<<"Total explored area: "<<fixed<<setprecision(2)<<sum<<endl<<endl;

	}
	return 0;
}