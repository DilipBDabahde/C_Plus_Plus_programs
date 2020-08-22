//initializing consta as well as non-const chars in constructor

#include<iostream>
using namespace std;	

class Base
{
	public:
		int i;
		const int j;
		
	
	Base()/*:i(10)*/: j(20)
	{
		i = 10;   //allowed
		//j = 20; //not allowed
	}
	
	void Addition()
	{
		cout<<"inside addition: "<<endl;
		cout<<i+j<<endl;
		
		cout<<"After increment"<<endl;
		i++;
//		j++; //j++ not allowed bcs its const once its defined then there no change is available
		cout<<"after increment addition: "<<endl;
		cout<<i+j<<endl;
	}
};

int main()
{
	cout<<"Inside main"<<endl;
	
	Base bobj;	
	bobj.Addition();
		
	return 0;
}
