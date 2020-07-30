#include<iostream>
using namespace std;

class A
{
	public:
		int a;
	private:
		int b;
	protected:
		int c;
	
	public:  //constructor should be public section
	A()	//resource allocation
	{
		a = 10;
		b = 20;
		c = 30;
	}
			
};

class B: public A
{
	public:
		int x;
	private:
		int y;
	protected:
		int z;

	public:  //constructor should be public section
	B()			//resource allocation
	{
		x = 100;
		y = 200;
		z = 300;
	}
	
	
	void show()	//accessible of A class is a,c characteristcs
	{
		cout<<"Value is: "<<c<<endl;
	}
	
};

class C: public B
{
	public:
		int i;
	private:
		int j;
	protected:
		int k;

	public:  //constructor should be public section
	C()		//resource allocation
	{
		i = 1000;
		j = 2000;
		k = 3000;
	
	}

	void show() //accesssible characteristics of A class is "a"c" and b class "x"z are in class c 
	{
		cout<<"Value is: "<<z<<endl;
	}
};

int  main()
{

	A aobj;
	B bobj;
	C cobj;
	
	cout<<"Size of A class: "<<sizeof(aobj)<<endl;
	cout<<"Size of B class: "<<sizeof(bobj)<<endl;
	cout<<"Size of C class: "<<sizeof(cobj)<<endl;	
	
	
	//aobj.a = 10;	//public is accessible everywhere
	//aobj.b = 20;	//due to private access specifier not allowed in main
	//aobj.c = 30; // due to protected access specifier not allowed in main
	
		
	
	
	cobj.show();
	/*
		in class A all characterristics are accessible to aobj
		
		in class B all its own characteristisc are accessible but from A class it can access public and protected 
		
		in class C all its own characteristics can access and from B class it can access all public as well as protected and from A class C_class object can access all public and proteced
	
	*/

	return 0;
}
