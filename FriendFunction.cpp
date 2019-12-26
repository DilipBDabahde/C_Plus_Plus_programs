/*
how to use friend function 
in this class we have define public private and proctected accesss specifier with some values 
they are accessible from other too
*/


#include<iostream>

using namespace std;



class Demo
{
	public:
		int i;
		int j;

	private:
		int x;
		int y;
	protected:
		int z;

	public: Demo() //constructor
	{

		i = 10;
		j = 12;

		//private
		x = 22;
		y = 33;

		//protected 
		z =55;
	} //end of contructor


	friend void fun(); // declared methood as friend
};

void fun()
{
	Demo dobj;
	cout<<dobj.i<<endl;
	cout<<dobj.j<<endl;
	cout<<dobj.x<<endl;
	cout<<"size of class is "<<sizeof(dobj)<<endl;
	cout<<dobj.y<<endl;
	cout<<dobj.z<<endl;
}

void gun()
{
	Demo dobj;
	cout<<dobj.i<<endl;  //f for this method we can access public mems but can'not access private and protected
}

int main()
{
	
	fun();
	gun();
	return 0;
}