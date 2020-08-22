/*
accept array from user and one value and return freq of that numbere by using array

-------------------------------------------------
input:
		arr[6] = {12,2,34,1,2,2};
		2
output: 3
-------------------------------------------------
input:	arr[6] = {'q','a','b', 'a', '4', 'p'}
		'a'
output:	2
-------------------------------------------------

*/

#include<iostream>
using namespace std;

class Base
{
	public:
	
	template <class T>
	int all_Type_Accepted(T *arr, T val, int size)
	{	
		int icnt = 0;


		for(int i = 0; i < size; i++)
		{
			if(arr[i] == val)		
			{
				icnt++;
			}
		}
		
		return icnt;	
	}
};


int main()
{
	
	int iarr[6] = {12,2,34,1,2,2};
	int val = 2;
	
	Base obj;
	
	cout<<"Freq is: "<<obj.all_Type_Accepted(iarr, val, 6);
	
	cout<<endl<<"---------------------------------"<<endl;
	
	char carr[6] = {'q','a','b', 'a', '4', 'p'};
	char val2 = 'a';
	cout<<"Freq is: "<<obj.all_Type_Accepted(carr, val2, 6);
	cout<<endl<<"---------------------------------"<<endl;
	
	



	return 0;
}
