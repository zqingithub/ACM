#include<iostream>
#include<string>
using namespace std;

void kmp(const string &str,int *next)
{
	const int len=str.size();
	int pre=0,tar=-1;
	next[0]=-1;
	while(pre<len)
	{
		if(tar==-1||str[pre]==str[tar])
		{
			++pre;
			++tar;
			next[pre]=tar;
		}
		else
			tar=next[tar];
	}
	for(int i=1;i<len;++i)
	{
		int temp=next[i];
		if(str[i]==str[temp])
			next[i]=next[temp];
	}
}

int countMatch(const string &s1,const string &s2)
{
	int s1_len=s1.size(),s2_len=s2.size();
	int *next=new int[s2_len+1];
	int count=0;
	kmp(s2,next);
	int i=0,j=0;
	while(i<s1_len)
	{
		if(j==s2_len)
		{
			++count;
			j=next[j];
		}
		if(j==-1||s1[i]==s2[j])
		{
			++j;
			++i;
		}
		else
			j=next[j];
	}
	if(j==s2_len)
		++count;
	delete[] next;
	return count;
}

int main()
{
	int n;
	cin>>n;
	string s1,s2;
	while(n-->0)
	{
		cin>>s2>>s1;
		cout<<countMatch(s1,s2)<<endl;
	}
	return 0;
}