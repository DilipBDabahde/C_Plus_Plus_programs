//anonymouse namespace

#include<iostream>

using namespace std;

namespace
{
	int i = 10;
	class Demo
	{
		public:
		void fun()
		{
			cout<<"inside anonymouse Demo class fun"<<endl;
		}
	};
}

int main()
{
	cout<<i<<endl;
 	
 	Demo dobj;
 	dobj.fun();
 	
 	
 return 0;
}

