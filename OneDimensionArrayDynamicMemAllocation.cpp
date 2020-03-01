//dynamic memory allocation in c++ 

#include<iostream>
using namespace std;
#include<stdlib.h>

class OneDimension
{
	private:
		int isize;
	public:
		int iCol, iRow;
		int *ptr;
	OneDimension(int);
	OneDimension(OneDimension &);
	~OneDimension();
	
	void Accept();
	void Display();
	int Maximum();
	int Minimum();
};

////////////////////////////////////////////////////////////////////////////////////////

OneDimension::OneDimension(int length = 5)
{
	cout<<"Inside default constructor"<<endl;
	isize = length;
	iCol = 0;
	iRow = 0;
	ptr = new int[isize];
}

////////////////////////////////////////////////////////////////////////////////////////

OneDimension::~OneDimension()
{
	cout<<"Inside destructor"<<endl;
	delete []ptr;

}

////////////////////////////////////////////////////////////////////////////////////////

void OneDimension::Accept()
{
	cout<<"Enter Elements for array"<<endl;
	for(int i =0; i<isize; i++)
	{
		cin>>ptr[i];	
	}
}

////////////////////////////////////////////////////////////////////////////////////////

void OneDimension::Display()
{
	for(int i = 0; i<isize; i++)
	{
		cout<<ptr[i]<<" ";	
	}
	cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////

int OneDimension::Maximum()
{
	int imax = ptr[0];
	for(int i=1; i<isize; i++)
	{
		if(ptr[i] > imax)
		{
			imax = ptr[i];
		}
	}
	return imax;
}


////////////////////////////////////////////////////////////////////////////////////////

int OneDimension::Minimum()
{
	int imax = ptr[0];
	for(int i=1; i<isize; i++)
	{
		if(ptr[i] < imax)
		{
			imax = ptr[i];
		}
	}
	return imax;
}


////////////////////////////////////////////////////////////////////////////////////////

int main()
{

 
	OneDimension obj1;
	obj1.Accept();
	obj1.Display();
	cout<<"Max number from elements is: "<<obj1.Maximum()<<endl;
	cout<<"Min number from elements is: "<<obj1.Minimum()<<endl;


 return 0;
}
