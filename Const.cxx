#include<iostream>

using namespace std;

class Demo
{
	public:
		int i;
		static int j;
		const int k = 50; 
		//const int k; //will generate it should intantiate immediately
		const int m;

		
		Demo(int ival = 999):m(ival) //default argument with const initialization
		{
			i = 10;	
			//j = 20; //not allowed to define in class		
		}
		
		
		void Display()
		{
			cout<<"Inside Display"<<endl;
			cout<<i<<endl;
			cout<<j<<endl;
			cout<<k<<endl;
			cout<<m<<endl;						
		}
		
		void increment()  //we ++ chars but non-constant 
		{
			cout<<"Inside increment"<<endl;
			cout<<i<<endl;
			cout<<m<<endl;	
			
			cout<<"After increment by 1"<<endl;
			i++;
			// m++; // not allowed bcs its constant
			cout<<i<<endl;
			cout<<m<<endl;				
		}
		
		//defining constant function
		//in this below function we can not increment or ++ charactristics in constatnt function
		void not_increment() const
		{
			cout<<"Inside not increment"<<endl;
			cout<<i<<endl;
			cout<<m<<endl;
			
		//	i++; // error: increment of member ‘Demo::i’ in read-only object
		//	m++;// error: increment of member ‘Demo::m’ in read-only object					
		}
};

	int Demo::j=20;  // must define static char in outside class

int main()
{

	Demo obj;	
	obj.Display();	
	obj.increment();
	obj.not_increment();
	
	return 0;
}
