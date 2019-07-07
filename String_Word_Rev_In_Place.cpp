//accept string from user and Rev String inplace
//input:this is game
//output: siht  si emag

#include<stdio.h>
#include<iostream>
using namespace std;
 
 void  String_Word_Rev_In_Place(char arr[])
 {
   int icnt=0,i=0,j=0,pose=0,k=0;
   
   while(arr[i]!= '\0' || icnt==0)
   {    
      if(arr[i]=='\0' && icnt==0)
      {
        icnt++;
      }
      
      if(arr[i]!=' ' && k==0)
      {
        pose=i;
        k++;
      }
      
      if(arr[i]==' ' || arr[i]=='\0')
      {     
        j=i-1;        
        while(pose<j)
        {
          char ch=arr[pose];
          arr[pose]=arr[j];
          arr[j]=ch;         
          pose++;
          j--;        
        }
        k=0;      
      }   
      i++;
   }   
   cout<<"Inside function:"<<arr<<endl;
 }
 
 int main()
{
  int size=50;
  int x=0;
  char arr[size];
  
  cout<<"Enter string :"<<endl;
  cin.getline(arr,size);
  

  
  cout<<"Before inplace reverse:"<<arr<<endl;
   
  String_Word_Rev_In_Place(arr); 
 
  cout<<"After inplace reverse:"<<arr<<endl;
 return  0;
}
