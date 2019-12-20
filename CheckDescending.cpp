//accept array size from user and elements from user and check that array is in descending order or not


#include<iostream>
using namespace std;

#define True 1
#define False 0

typedef int BOOL;



BOOL CheckDescending(int arr[], int size)
 {	
 	int i = 0;

 	for( i = 0; i<size-1; i++)
 	{
 		if(arr[i] < arr[i+1])
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

   cout<<"Enter values for array\n";

   for(int i = 0; i< size;i++)
   {
   		cout<<"Enter num: ";
   		cin>>arr[i];
   }

   BOOL result = CheckDescending(arr, size);
   if(result == True)
   	{
   		cout<<"Given array is in descending order\n";
    }
   else
   {
   		cout<<"Given arr is not in descending order\n";
   }

 return 0; 
 }