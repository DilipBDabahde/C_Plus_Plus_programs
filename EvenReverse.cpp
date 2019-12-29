//accept number from user and return even reverse
// input: 34266   output: 662
//input: 5903    output: 0



#include<iostream>
using namespace std;


int reverseEven(int iNo)
{

	int ichage = 0, idigit = 0;

	while( iNo != 0)
	{
		idigit = iNo % 10;
		if(idigit % 2 == 0)
		{
			ichage = ichage * 10 + idigit;
		}

		iNo /= 10;
	}

	return ichage;

}



int main()
{
	int  ival = 0, res =0;

	cout<<"Enter a val: ";
	cin>>ival;

	res = reverseEven(ival);

	cout<<"Revesr of Enve is :"<<res<<endl;

 return 0;
}