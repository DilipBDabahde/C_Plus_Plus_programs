/*
create two class such as Digit and AdvDigit

in Digit class 
	add sum behavious such as
	1) Accept();
	2) Display();
	3) CountDigit();
	4) SumDigit();
	
	charactristics
	int iNo
	
int AdvDigit Class
	behaviours
	CheckStrong();
	CheckArmStrong();
	
*/



#include<iostream>

#define True 1
#define False 0

typedef int BOOL;
using namespace std;

class Digit
{
	protected:
	int iNo;
	
	public:
	
	void Accept();
	void Display();
	int DigitSum();
	int DigitCount();
};

class AdvDigit:public Digit
{
	public:
	BOOL CheckStrong();
	BOOL CheckArmStrong();
	int NumFactorial();
	static int Power();
};
///////////////////////////////////////////////////////////////////////////////////////////////////
void Digit::Accept()
{
	cout<<"Enter value: ";
	cin>>iNo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void Digit::Display()
{
	cout<<"Given Number is: "<<iNo<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int 	Digit::DigitCount()
{
	int ival = iNo;
	int icnt = 0;
	while(ival != 0)
	{
		icnt++;
		ival /= 10;
	}
	return icnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int AdvDigit::NumFactorial()
{
	int itemp = 0;
	int isum1 = 1;
	int isum2 = 0;
	int ival = iNo;
	
	while(ival != 0)
	{
		itemp = ival%10;  //allcatign single digit to itemp
		
		while(itemp != 0)
		{
			isum1 = isum1 * itemp;
			itemp--;
		}
		
		ival /= 10;
		isum2 += isum1;
		isum1 = 1;
	}
	 return isum2;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int Digit::DigitSum()
{
	int isum = 0;
	int ival = iNo;
	while(ival != 0)
	{
		isum += ival % 10;
		ival /= 10;
	}
	return isum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BOOL AdvDigit::CheckStrong()
{
	int iresult = NumFactorial();
	
	if(iresult == iNo)
	{
		return  True;
	}
	else
	{
		return False;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AdvDigit::CheckArmStrong()
{
	int TotDigit = DigitCount();
	int isize1 =0, isize2 = 0, itemp = 0, ival = iNo;
	for(int i = 1; i<= TotDigit; i++)
	{
		isize1 = 1;
		for(int j = 1; j<=TotDigit; j++)
		{
			isize1 *= (ival%10);
		}
		isize2 += isize1;
		ival /= 10;
	}
	
	if(isize2 == iNo)
	{
		return True;
	}
	else
	{
		return False;	
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	AdvDigit obj1;
	
	obj1.Accept();
	obj1.Display();
	cout<<"Total Digits are: "<<obj1.DigitCount()<<endl;
	cout<<"Sum of all Digits is: "<<obj1.DigitSum()<<endl;
	BOOL iresult = obj1.CheckStrong();
	if(iresult == True)
	{
		cout<<"Given number is Strong number"<<endl;
	}
	else
	{
		cout<<"Given number is not strong"<<endl;
	}
	
 	iresult = obj1.CheckArmStrong();
 	if(iresult == True)
	{
		cout<<"Given number is ArmStrong number"<<endl;
	}
	else
	{
		cout<<"Given number is not ArmStrong"<<endl;
	}
	
	return 0;
}

