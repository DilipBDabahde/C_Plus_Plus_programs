//pure virtual function example

#include<iostream>
using namespace std;

class Demo
{
	public:
		int i;
		int j;
	
	void fun()
	{
		cout<<"Inside Demo fun"<<endl;
	}
	
	virtual void gun() = 0; //pure virtual function
	
	virtual void sun() //virtual function
	{
		cout<<"Demo sun"<<endl;
	}
	
	virtual void run()	//virtual function
	{
		cout<<"Demo run"<<endl;
	}
};

class Hello: public Demo
{
	public:
		int x;
	
	void gun()  //pure virtual function definition 
	{
		cout<<"Gun of Hello"<<endl;
	}
	
	void run()  //redifining
	{
		cout<<"Run of Hello"<<endl;
	}
	
	void sun()	//redifining
	{
		cout<<"Sun of Hello"<<endl;
	}
	
	virtual void mun()  ////virtual function
	{
		cout<<"mun of Hello"<<endl;
	}
};

int main()
{
	Demo  *ptr = NULL;
	Hello hobj;
	
	ptr = &hobj;
	
	
	ptr->fun(); //Demo fun
	ptr->gun(); //Hello fun
	ptr->sun(); //Hello sun
	ptr->run(); //Hello run
	//ptr->mun(); //error	
	
	return 0;
}
