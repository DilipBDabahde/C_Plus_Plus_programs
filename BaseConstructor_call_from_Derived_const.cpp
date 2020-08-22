//construct call from Derived to Base

#include<iostream>
using namespace std;

class Base
{
	public:
	
	int i;
	
	Base(int x = 0)
	{
		i = x;
	}
	
	virtual void Display()//overrding and its virtual fucntion
	{
		cout<<"Base Values is: "<<--i<<endl;
	}
	
	virtual void Displayx()= 0;// pure virtual fuction and also abstract method so we can't create obj of this class


};

class Derived : public Base
{
	public:
	
	Derived(int val):Base(val)	//calling base constructor
	{	}
	
	void Display()
	{
		cout<<"Derived Values is: "<<i++<<endl;
	}
	
	void Displayx()
	{
		cout<<"Derived Pure virtual fun defined :"<<i<<endl;
	}
	
};

int main()
{

	Derived dobj(11);
	dobj.Display();
	dobj.Displayx();
	
	return 0;


}
