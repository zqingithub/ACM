#include<iostream>
using namespace std;

struct block
{
	int s;
	int e;
	int count;
	block *left;
	block *right;
	block(){}
	block(const int s,const int e):s(s),e(e),count(0),left(NULL),right(NULL)
	{}
};

class Tree
{
public:
	Tree(const int n)
	{
		root=new block(0,n-1);
	}
	~Tree()
	{
		if(NULL!=root)
			release(root);
	}
	void insert(const int i)
	{
		recInsert(i,root);
	}
	int Count(const int s,const int e)
	{
		return recCount(s,e,root);
	}
private:
	block *root;
	void release(block *root)
	{
		if(NULL!=root->left)
			release(root->left);
		if(NULL!=root->right)
			release(root->right);
		delete root;
	}
	void recInsert(const int i,block *root)
	{
		++root->count;
		if(root->s==root->e)
			return;
		int mid=(root->s+root->e)/2;
		if(i<=mid)
		{
			if(NULL==root->left)
				root->left=new block(root->s,mid);
			recInsert(i,root->left);
		}
		else
		{
			if(NULL==root->right)
				root->right=new block(mid+1,root->e);
			recInsert(i,root->right);
		}
	}
	int recCount(const int s,const int e,block *root)
	{
		if(s==root->s&&e==root->e)
			return root->count;
		int mid=(root->s+root->e)/2;
		if(e<=mid)
			return NULL==root->left?0:recCount(s,e,root->left);
		if(s>mid)
			return NULL==root->right?0:recCount(s,e,root->right);
		int Sum=0;
		if(NULL!=root->left)
			Sum+=recCount(s,mid,root->left);
		if(NULL!=root->right)
			Sum+=recCount(mid+1,e,root->right);
		return Sum;
	}
};

int store[5001];
int solu(const int n)
{
	Tree tree(n);
	int min=0;
	for(int i=0;i<n;++i)
	{
		min+=tree.Count(store[i]+1,n-1);
		tree.insert(store[i]);
	}
	int pre=min;
	for(int i=0;i<n-1;++i)
	{
		pre=pre-store[i]+n-1-store[i];
		if(pre<min)
			min=pre;
	}
	return min;
}

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>store[i];
		cout<<solu(n)<<endl;
	}
	return 0;
}