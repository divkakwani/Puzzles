#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	long int t,q,rot,l,kl,kr,c;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s>>kl>>kr>>q;
		l = s.length();
		while(q--)
		{
			cin>>c;
			rot = c-kr+kl;
			(rot<0)?(rot = rot+l):rot = rot;
			rot = rot%l;
			cout<<s[rot]<<endl;
		}
	}
	return 0;
}
