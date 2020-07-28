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

class Hello
{
	public:
		int i;
		int j;
		Demo dobj; //creating object into another class is known as conposition
	
	void run()
	{
		cout<<"Run of Hello"<<endl;
	}
	
	void show_values()
	{
		cout<<"Value of i :"<<i<<endl;
		cout<<"Value of j :"<<j<<endl;
		cout<<"Value of dobj.x: "<<dobj.x<<endl;
		cout<<"Value of dobj.y: "<<dobj.y<<endl;
	}
};

int main()
{
	cout<<"Inside main "<<endl;
	
	Demo dobj1;	//memory allocated to class
	cout<<"size of Demo class: "<<sizeof(dobj1)<<endl;
	dobj1.fun(); //calling fun which is inside Demo class
	
	dobj1.x = 10; //initializing allocated memory
	dobj1.y = 20;	
	
	//check memory is initialized or not
	dobj1.show_values();
	
	cout<<"-------------------------------"<<endl;
	//Creating obj of Hello
	Hello hobj;
	hobj.run();
	cout<<"size of Hello class: "<<sizeof(hobj)<<endl;
	
	hobj.i = 15;
	hobj.j = 25;
	hobj.dobj.x = 115;
	hobj.dobj.y = 225;
	
	hobj.show_values();
	hobj.dobj.show_values();

	return 0;
}
