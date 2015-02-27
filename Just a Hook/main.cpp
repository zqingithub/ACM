#include<iostream>
using namespace std;
class unit
{
public:
	int l;
	int r;
	int val;
	bool same;
	unit(){};
	unit(int l,int r,int val,bool same):
	l(l),r(r),val(val),same(same)
	{}
};

void build(unit * Tree,int k,int l,int r)
{
    Tree[k]=unit(l,r,1,true);
	if(l!=r)
	{
		int mid=(r+l)/2;
		build(Tree,k*2+1,l,mid);
		build(Tree,k*2+2,mid+1,r);
	}

}

void add(unit * Tree,int k,int l,int r,int val)
{
	int TL=Tree[k].l;
	int TR=Tree[k].r;
	int mid=(TL+TR)/2;
	if(TL==l&&TR==r)
	{
		Tree[k].same=true;
		Tree[k].val=val;
		return;
	}
	if(Tree[k].same&&Tree[k].val==val)
		return;
	if(Tree[k].same)
	{
		Tree[k].same=false;
		add(Tree,k*2+1,TL,mid,Tree[k].val);
		add(Tree,k*2+2,mid+1,TR,Tree[k].val);
	}
	if(l<=mid)
		add(Tree,k*2+1,l,mid<r?mid:r,val);
	if(r>mid)
		add(Tree,k*2+2,mid+1>l?mid+1:l,r,val);
}

int find(unit * Tree,int k)
{
	if(Tree[k].same)
		return (Tree[k].r-Tree[k].l+1)*Tree[k].val;
	else
		return find(Tree,k*2+1)+find(Tree,k*2+2);
}

int main()
{
	int N;
	cin>>N;
	int index=0;
	unit * Tree=new unit[500005];
	while(index++<N)
	{
		int num;
		cin>>num;
		build(Tree,0,0,num-1);
		int Q;
		cin>>Q;
		while(Q-->0)
		{
			int l,r,val;
			cin>>l>>r>>val;
			add(Tree,0,l-1,r-1,val);
		}
		cout<<"Case "<<index<<": The total value of the hook is "<<find(Tree,0)<<"."<<endl;
	}
	delete [] Tree;
	return 0;
}