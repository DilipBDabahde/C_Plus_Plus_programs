// in this demo we can see how to access parents properties as child

#include<iostream>
using namespace std;

class Demo
{
	public:
		int x;
		int y;
		
	void fun()
	{
		cout<<"Fun of A class"<<endl;
	}
	void show_values()
	{
		cout<<"Value of x :"<<x<<endl;
		cout<<"Value of y :"<<y<<endl;
	}
};

class Hello: public Demo
{
	public:
		int i;
		int j;
		Demo dobj; //creating object into another class is known as conposition
	
	void run()
	{
		cout<<"Run of Hello"<<endl;
	}
	
	void My_values()
	{
		cout<<"Value of i :"<<i<<endl;
		cout<<"Value of j :"<<j<<endl;
	}
	
};

int main()
{
	//without inheritance
	Demo dobj;
	dobj.fun();
	dobj.x=10;
	dobj.y=20;
	dobj.show_values();
	
	//with inheritance
	Hello hobj;
	hobj.run();
	hobj.x = 100; //inherited characteristic x
	hobj.y = 200; // inherited characteristic y
	hobj.show_values(); /// This method is defined in Demo we are able to reuse it with clild class obj
	hobj.i = 1000;
	hobj.j = 2000;
	hobj.My_values();
	
	return 0;
}
