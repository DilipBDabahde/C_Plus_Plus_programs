/*
accept num from user and check that number is palindrom or not

intput : 234 NO
input: 45654  Yes
*/



#include<iostream>
using namespace std;

typedef int BOOL;
#define True 1
#define False 0



BOOL palindrom(int iNo)
{
	int icnt = 0, itemp = iNo;

	while (iNo != 0)
	{
		icnt = icnt * 10 + iNo % 10;
		iNo /= 10;
	}

	if (icnt == itemp)
		return True;
	else
		return False;
}


int main()
{
  int ival = 0;

  cout<<"Enter num: ";
  cin>>ival;

  BOOL res = palindrom(ival);
  if (res == True)
  	cout<<"given num is palindrom";
  else
  	cout<<"given num is not palindrom";

 return 0;

}