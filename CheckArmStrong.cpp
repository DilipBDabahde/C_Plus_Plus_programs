/*
accept number from user and check that number is armstrong number or not

input: iNo = 1112; 
output: False

input: 145		Total digits are 3    
output: True  

*/

#include<iostream>

using namespace std;

typedef int BOOL;
#define True 1
#define False 0

class CheckArm
{
	private:
	int iNo;
	
	public:
	void Display();
	void Accept();
	int DigitCount();
	BOOL CheckArmStrong();

};


void CheckArm::Accept()
{
	cout<<"Enter number: ";
	cin>>iNo;
}

int CheckArm::DigitCount()
{
	int icnt = 0;
	int ival = iNo;
	while(ival != 0)
	{
		ival /= 10;
		icnt++;
	}	
	return icnt;
}	

BOOL CheckArm::CheckArmStrong()
{
	int TotalCnt = DigitCount();
	int isum1 = 0;
	int ival = iNo;
	int isum2 = 0;
	
	for(int i = 1;i<=TotalCnt;i++)
	{
		isum1 =1;
		for(int j =1; j<= TotalCnt; j++)
		{
			isum1 *= ival % 10;;
		}
		isum2 +=isum1;
		ival /=10;	
	}
	
	if(isum2 == iNo)
	{
	    return True;
	}
	else
	{
		return False;
	}
}

void CheckArm::Display()
{
 cout<<"Given num is: "<<iNo<<endl;
}

int main()
{

 CheckArm obj1;
 obj1.Accept();
 obj1.Display();
 BOOL Res = obj1.CheckArmStrong();
 
 if(Res == True)
 {
  cout<<"Given num is Armstrong"<<endl;
 }
 else
 {
  cout<<"Given num is not ArmStrong"<<endl;
 }
 
 return 0;
}
