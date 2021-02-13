/*
accept three nums from user and perform addition of max two nums
input: 9 12 84
output: 96

input: 84 12 9
output:
	   96

input:	12 84 9
output:
	    96
*/


#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	
	cout<<"Enter first number: ";
	cin>>a;
	
	cout<<"Enter second number: ";
	cin>>b;
	
	cout<<"Enter third number: ";
	cin>>c;
	
	
	if(a > c && b > c)
	{
		cout<<"Max two num sum is: "<<a + b<<endl;
	}
	else if(b > a && c > a)
	{
		cout<<"Max two num sum is: "<<b + c<<endl;	
	}
	else
	{
		cout<<"Max two num sum is: "<<a + c<<endl;	
	}
	return 0;
}
