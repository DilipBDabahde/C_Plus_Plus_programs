#include<iostream>
using namespace std;

//variable created inside namespace
namespace first
{	
	class A
	{
		public:
		void fun()
		{
			cout<<"inside first fun"<<endl;
		}
	};
}

namespace second
{
	class B
	{	
		public:
		void fun()
		{
			cout<<"inside second fun"<<endl;
		}	
	};
}

//global variable
int val = 50;

int main()
{
	
	first::A aobj;
	aobj.fun();

	second::B bobj;
	bobj.fun();
 return 0;



}
