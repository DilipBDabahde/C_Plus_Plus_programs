/*
accept num as we as one digit from user and check that digit occured into number

input:  num --> 3423
		digit -> 3

output:	True

input: num -> 342
	   digit : 5
output:False
*/

#include<iostream>

using namespace std;
typedef int BOOL;

#define True 1
#define False 0


BOOL checkDigit(int iNo, int digit)
{
	
	int icnt = 0;

	while(iNo != 0)
	{
		icnt = iNo % 10;
		if (icnt == digit)
		{
			break;
		}
		iNo /= 10;
	}

	if(iNo == 0)
	{
		return False;
	}
	else
	{
		return True;
	}


}

int main()
{

	int num = 0, digit = 0;
	cout<<"Enter num: ";
	cin>>num;

	cout<<"Enter digit: ";
	cin>>digit;

	int res = checkDigit(num, digit);
	if (res == True)
		cout<<"digit occured"<<endl;
	else
		cout<<"digit not occured"<<endl;

 

 return 0;
}