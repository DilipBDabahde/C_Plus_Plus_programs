//static implementation of stack in c++

#include<iostream>
#include<stdlib.h>
#include<string.h>
#define FAILURE -1

using namespace std;

class  Stack  //class body start
 {
    protected:
    int *iptr;
    int length;
    int top;
    
    public:
    Stack(int len=10)
     {
      this->length=len;
      this->top=FAILURE;
      this->iptr=new int[length];     
     }
     
     ~Stack();
     
     void Push(int);
     int Pop(); 
 };  //end of class body
 
 Stack::~Stack()
  {
   if(this->iptr != NULL)
   {
     delete []iptr;
   }  
  }
  
  void Stack::Push(int value)
  {
    if((this->length)FAILURE == (this->top))
    {
     return;
    } //if this body excute then stack is full
    else
    {
     ++top;
     iptr[top]=value;  //index wise FAILUREues will be added to stack FILO
    }   
  }
  
  int Stack::Pop()
  {
     if(top==FAILURE)
     {
      return FAILURE;
     }
     else
     {
        int ret=0;
        ret=iptr[top];
        top--;
        return ret;
     }  
  }
  
  int main()
  {
    Stack obj2; //obj created  stack length is 10
    Stack obj1(4);     // if we use obj2 we can add only four buckets
    
    obj2.Push(11);
    obj2.Push(21);
    obj2.Push(31);
    obj2.Push(41);
    obj1.Push(111);
    
    cout<<obj1.Pop()<<endl;
    cout<<obj2.Pop()<<endl;
    cout<<obj2.Pop()<<endl;
    cout<<obj2.Pop()<<endl;
    cout<<obj2.Pop()<<endl;
    
   return 0;
  }
  
  
