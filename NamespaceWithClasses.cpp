/*
till now use ready made namespace we can create our own namespacce and access it as below

*/

#include<iostream>

using namespace std;

namespace Demo
{
	int i =10;
	
	class Base
	{
		public:
		Base()
		{
			cout<<"Demo Base"<<endl;
			cout<<"Val of i in Base Demo: "<<i<<endl;
		}	
	};
	
	
	class Base2
	{
		public:
		Base2()
		{
			cout<<"Demo Base2 "<<endl;
			cout<<"Val of i in Base2 Demo: "<<i<<endl;
		}	
	};
}  //end of Demo namespace

namespace Hello
{
	int i = 21;
	
	class ABC
	{
		public:
		ABC()
		{
			cout<<"Hello ABC"<<endl;
			cout<<"val of i in ABC Hello: "<<i<<endl;
		}
	};
} //end of Helllo  namespace

using namespace Demo;
using namespace Hello;

int main()
{
	Demo::Base bobj;
	Demo::Base2 b2obj;
	
	Hello::ABC obj;


 return 0;
}

