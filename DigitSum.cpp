/*
accept num from user and return summation of each digit

ino = 2432
output: 11
*/


#include<iostream>

using namespace std;

int digitsum(int iNo)
{
	int isum = 0, icnt = 0;

	while(iNo != 0)
	{
		isum += iNo%10;
		iNo /= 10;
	}

	return isum;
}


int main()
{
	int ival = 0;
	cout<<"Enter num: ";
	cin>>ival;
	int res = digitsum(ival);
	printf("sum of all digits is: %d\n",res);

	return 0;
}