//accept array from user and display such element which ends with 7 digit

//input: [9, 19, 27, 85, 98, 97, 33]   arr[i]%10 == 7  print(arr[i])


#include<iostream>

using namespace std;


void Display(int arr[], int size, int iNo)
{
	
	if(arr == NULL || size <= 0)
	{
		return;
	}

	for(int i = 0 ; i < size; i++)
	{
		if(arr[i]%10 == iNo)
		{
			cout<<arr[i]<<" ";
		}
	}
}


int main()
{
	
	int arr[] = {9, 19, 27, 85, 98, 97, 33};
	
	Display(arr, 7, 7);
	
	return 0;
}
