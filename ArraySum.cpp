//accept array size from user aswellas elements and return sum of all elements
#include<iostream>
using namespace std;

 int ArraySum(int *arr, int size)
 {
 	int sum=0;
 	for(int i = 0;i<size; i++)
 	{
 		sum += arr[i];
 	}
 	return sum;
 }


 int main()
 {
 	int size = 0;
 	cout<<"Enter array size: ";
 	cin>>size;
 	int arr[size];

 	cout<<"enter elemts for array\n";

 	for(int i = 0;i<size;i++)
 	{	cout<<"Enter num: ";
 		cin>>arr[i];
 	}
 	
 	int result = ArraySum(arr, size);
 	cout<<"Sum of all elements is : "<<result<<endl;

  return 0;
 }