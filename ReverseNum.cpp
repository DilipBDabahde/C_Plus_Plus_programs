//accept num from user and return its reverse

#include<iostream>
using namespace std;


int reverseNum(int iNo)
{
	int ichange = 0;

	while(iNo != 0)
	{
		ichange = ichange * 10 + iNo % 10;
		iNo /= 10;
	}

	return ichange;
}

int main()
{

	int ival = 0;
	cout<<"Enter num: ";
	cin>>ival;

	int res = reverseNum(ival);
	cout<<"Reverse is: "<<res<<endl;

 return 0 ;
}