#include<iostream>
#include<string>
using namespace std;

string solu(string s1,string s2)
{
	s1=string(1,'A')+s1;
	s2=string(s1.size()-s2.size(),'A')+s2;
	string outcome=string(s1.size(),'A');
	int temp=0;
	for(int i=s1.size()-1;i>=0;--i)
	{
		outcome[i]=(s1[i]-'A'+s2[i]-'A'+temp)%26+'A';
		temp=(s1[i]-'A'+s2[i]-'A'+temp)/26;
	}
	int size=outcome.size();
	int i=0;
	while(i<size&&outcome[i]=='A')++i;
	if(i==size)
		return "A";
	return outcome.substr(i,size-i);
	return outcome;
}

int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		if(s1.size()>s2.size())
			cout<<solu(s1,s2)<<endl;
		else
			cout<<solu(s2,s1)<<endl;
	}
	return 0;
}