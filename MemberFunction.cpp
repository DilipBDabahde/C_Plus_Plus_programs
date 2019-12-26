/*
class member become friends
*/

#include<iostream>
using namespace std;

class Hello;

class Demo
{

private:
	int x;

public: Demo()
	{
		x = 111;
	}

	friend void Hello::fun();
};

class Hello
{

public:
	void fun()
	{
		Demo dobj;
		cout<<dobj.x<<endl;
	}
};

int main()
{
	Hello hobj;
	hobj.fun();
 return 0;
}

