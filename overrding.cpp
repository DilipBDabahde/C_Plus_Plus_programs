/*
use of virtual in c++ to make use of virtual/overriding we have to first know upcasting then we can implement virtual as we as overriding concept in c++

to achieve concept of upcasting we have to create pointer of Base class and need to create object of derived class
where baseptr can point to derivedclass obj
this process is known as upcasting 
Base *ptr = NULL;
Derived dobj;

ptr = &dobj;

now ptr is able to make overriding but to achive overrding we have to make use of virtual keyword with function definition

Example: Below
*/

#include<iostream>
using namespace std;

class Base
{
	public:
	void gun()
	{
		cout<<"Gun  of Base"<<endl;
	}
	
	virtual void fun()  //can be overriden, virtual keyword make method as abstract so inherited class has to pro def
	{
		cout<<"Fun of Base"<<endl;
	}

	void sun()
	{
		cout<<"Sun of Base"<<endl;
	}
};

class Derived :public Base
{
	public:
	
	void gun()
	{
		cout<<"Derived Gun"<<endl;
	}
	
	void fun()
	{
		cout<<"Derived fun"<<endl;
	}
	
	void mun()
	{
		cout<<"Derived mun"<<endl;
	}
};


int main()
{
	Derived dobj;
	Base *bptr = &dobj; //upcasting
	
	bptr->fun();  //overriding is done by (calling+upcasing+virtualkeyword)
		
	return 0;

}
