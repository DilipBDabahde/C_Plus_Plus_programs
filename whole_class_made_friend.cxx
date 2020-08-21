//whole class become friend


#include<stdio.h>
#include<iostream>

using namespace std;

class Demo
{
	private:
	int i;
	
	Demo()
	{
		i = 300;
	}
	
	friend class Hello;
};

class Hello
{
	public:
		
		void gun()
		{
			Demo obj;
			cout<<"val of i is from gun: "<<obj.i<<endl;
		}
		
		void fun()
		{
			Demo obj;
			cout<<"val of i is from fun: "<<obj.i<<endl;
		}
};

int main()
{
	Hello hobj;
	
	hobj.fun();
	
	hobj.gun();
	
	
	return 0;


}
