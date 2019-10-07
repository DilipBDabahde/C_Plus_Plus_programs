#include<stdio.h>
#include<iostream>

using namespace std;

class Fibonacci_Series
{
  public:
  int iNo1,iNo2,A,B,k;

  Fibonacci_Series()
  {
      iNo1=0;
      iNo2=0;
      A=0;
      B=1;
      k=0;
  }

  void Dis_Fibo_Ser(int val)
  {
      for(int i=1;i<=val;i++)
      {
         k=A+B;
         A=B;
         B=k;
         printf("%d ",B);
      }
  }
};

int main()
 {
    int val=0;
    printf("Enter a val: ");
    scanf("%d",&val);
    
    Fibonacci_Series fb;
    fb.Dis_Fibo_Ser(val);    
    printf("\n");

     return 0;
 }