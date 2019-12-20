//accept array from user and check that array is sorted in ascending order or not

#include<iostream>
using namespace std;
#define True 1
#define False 0
typedef int BOOL;

 int ArraySum(int *arr, int size)
 {  
 	int i = 0;
 	for(i=0;i<size-1;i++)
 	{
 		if(arr[i] > arr[i+1])
 			break;
 	}
 
 	if(i == size-1)
 		return True;
 	else
 		return False;
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
 	
 	BOOL result = ArraySum(arr, size);
 	if (result == True)
 	{
 		cout<<"Given array is sorted\n";
 	}
 	else
 	{
 		cout<<"Given array is not sorted\n";
 	}

  return 0;
 }