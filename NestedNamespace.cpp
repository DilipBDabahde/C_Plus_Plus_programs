//nested namespace 

#include<stdio.h>
#include<iostream>
using namespace std;

namespace Outer
{
	class IMOuter
	{
		public:
		IMOuter()
		{
			cout<<"In IMOuter "<<endl;
		}	
		void fun()
		{
			cout<<"inside outer class fun"<<endl;
		}		
	};
	
	
	namespace Inner
	{
		class IMInner
		{
			public:
			IMInner()
			{
				cout<<"in IMInner"<<endl;
			}
			void fun()
			{
				cout<<"inside inner class fun"<<endl;
			}		
		};	
	} //end of inner namespace
}// end of outer namespace

int main()
{
	
	Outer::IMOuter imobj;
	
	Outer::Inner::IMInner imiobj;
	
	imobj.fun();
	imiobj.fun();


 return 0;
}

