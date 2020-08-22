	/*
	accept two values from user and return max value from them
	input: 11   21
	output: 21


	input: A   P
	output: P

	input: 12.42		43.12
	output: 43.12
	*/

	#include<iostream>
	using namespace std;

	class Base
	{
		public:
		
		//all specific
		int Max(int ival1, int ival2)	//here we can achieve fucntion overloading depends on input type
		{
			if(ival1 > ival2)
			{
				return ival1;
			}
			else
			{
				return ival2;
			}
		}
		
		float Max(float fval1, float fval2)
		{
			if(fval1 > fval2)	
			{
				return fval1;
			}
			else
			{
				return fval2;
			}
		}
		
		char Max(char cval1, char cval2)
		{
			if(cval1 > cval2)
			{
				return cval1;
			}
			else
			{
				return cval2;
			}
		}

	};

	class Derived: public Base
	{
		public:
			template <class T>
			T AllType(T alltype1, T alltype2)
			{
				cout<<alltype1<< " "<<alltype2<<endl;
				
				if(alltype1 > alltype2)
				{
					return alltype1;
				}
				else
				{
					return alltype2;
				}		
			}
	};



	int main()
	{

		Base obj;
		
		int ix = 10, iy = 20;
		float fx = 10.10, fy = 20.20;
		char cx = 'A', cy = 'Z';
		
		
		int iresult = obj.Max(ix, iy);
		cout<<"Input is: "<<ix<<" "<<iy<<endl;
		cout<<"Max is: i :"<<iresult<<endl;
		cout<<"--------------------------------"<<endl;
		
		cout<<"Input is: "<<fx<<" "<<fy<<endl;
		float fresult = obj.Max(fx, fy);
		cout<<"Max is: f :"<<fresult<<endl;
		cout<<"--------------------------------"<<endl;
		
		cout<<"Input is: "<<cx<<" "<<cy<<endl;
		char cresult = obj.Max(cx, cy);
		cout<<"Max is: c :"<<cresult<<endl;
		
		Derived dobj;
		cout<<"Below is generic programming ouutput"<<endl;
		
		cout<<dobj.AllType(111,222)<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<dobj.AllType(1211.11, 12.21)<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<dobj.AllType('A', 'P')<<endl;

		
		
		return 0;
	}
