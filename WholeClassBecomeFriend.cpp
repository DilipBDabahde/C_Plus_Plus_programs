/*
whole class become friend
*/


#include<iostream>

using namespace std;

class Demo
{
private:
	int i;

	public: Demo()
	{
		i = 110;
	}
	friend class Hello;
};


class Hello
{
public:
	void fun()
	{
		Demo obj;
		cout<<obj.i<<endl;
	}
};

int main()
{
	Hello hobj;
	hobj.fun();
 
 return 0;	
}
