//accept two string from user and print strings are angram or not
/*
   input1: dilip
   input2: lipdi          TRUE
   
   input1: dilip
   input2: lipd		 FALSE
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define FAILURE -1
#define MAXSIZE 80
typedef int BOOL;

using namespace std;

class Anagram
 {   
  
   public:
   int angram(char *arr,char *brr);
 };
 
 int main()
 {
 
   Anagram obj1;
   char *ch1=NULL,*ch2=NULL;
   BOOL bret=FALSE;
   ch1=(char*)malloc(sizeof(char));   
   ch2=(char*)malloc(sizeof(char));
   cout<<"Enter first string\n";
   cin.getline(ch1,MAXSIZE);
  
  
   cout<<"Enter second string\n";
   cin.getline(ch2,MAXSIZE);
   bret=obj1.angram(ch1,ch2);
   if(bret==FAILURE)
   {
    cout<<"Both string have not same length\n";
   }
   if(bret==TRUE)  
   {
    cout<<"ANAGRAM\n";
   }
   else if(bret==FALSE)
   {
    cout<<"NOT ANAGRAM\n";
   }
   
   return 0;
 }
 
 int Anagram::angram(char *str1,char *str2)
  {
    char *ch1=NULL,*ch2=NULL;
    int len=0,len1=0,len2=0,i=0,j=0,get=0,n_get=0;
    
    ch1=str1;
    ch2=str2;
    
    while(*ch1 != '\0')
    {
       len1++;
       ch1++;
    }
    ch1=str1;
  
   while(*ch2 != '\0' )
    {
      len2++;
      ch2++;
    }
    ch2=str2;
 
   if(len1==len2)
    {
      len=len1;
         for(i=0;i<len;i++) //tea eap
         {
            get=0;
            for(j=0;j<len;j++)
            {
              if(str1[i]==str2[j])
              {
                  get=1;
                  break;
              }            
            }
            
            if(get==0)
           {
             n_get=1;
             break;
           }
         }
         
         if(n_get==1)
         {
           return 0;
         }
         else
         {
          return 1;
         }     
    }    
    else
    {
      return FAILURE;
    } 
  }
