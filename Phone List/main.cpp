#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isCon(vector<string> & PhoneList)
{
	sort(PhoneList.begin(),PhoneList.end());
	bool out=true;
	for(int i=0;i<PhoneList.size()-1;++i)
	{
		if(PhoneList[i].size()<=PhoneList[i+1].size())
		{
			if(PhoneList[i+1].find(PhoneList[i])==0)
			{
				out=false;
				break;
			}
		}
	}
	return out;
}
int main()
{
	int N;
	cin>>N;
	vector<string> PhoneList;
	int nLine;
	while(N-->0)
	{
		PhoneList.clear();
		cin>>nLine;
		while(nLine-->0)
		{
			string temp;
			cin>>temp;
			PhoneList.push_back(temp);
		}
		if(isCon(PhoneList))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}