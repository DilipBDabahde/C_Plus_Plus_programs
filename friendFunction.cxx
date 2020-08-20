//friend function with neked demo
/*
	in this class we declared fun as friend function so we defined method of fun as naked after class
	and fun method gets call from main method when control come to fun method then in this method we created obj of Demo
	class and by using obj we are able to access private as we as protected characteristics in fun method which is declared as friend in class.

*/
#include<iostream>
using namespace std;

class Demo
{
	private:
		int x;
	protected:
		int y;
	
	public:
		Demo()
		{
			x = 30;
			y = 40;	
		}
	
	friend void fun(); //declared as friend function
};

//now defining neked method of friend declared in class

void fun()  //friend function definition
{
	Demo obj;
	cout<<"gun x "<<obj.x<<endl;
	cout<<"gun y "<<obj.y<<endl;
}

void gun() //compile time error 
{							//remove comment to check error
	//Demo obj;
	//cout<<"gun x"<<obj.x<<endl;
	//cout<<"gun y"<<obj.y<<endl;
}

int main()
{
	fun();
	//gun();
	
	return 0;
}
