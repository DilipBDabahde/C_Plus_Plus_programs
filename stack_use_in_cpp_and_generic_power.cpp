//if we are takking diff types of values then we have to use generic prograammig approach to fill stack

//hereis example of generic programming in cpp
//two way programming can be done first specific way second genereic way


#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class Stack
 {
    private:
    T *ptr;
    int size;
    int top;
    public:
    
    Stack(int length=10)
     {
       this->size=length;
       this->top=-1;
       this->ptr=new T[size];
     }
     
    ~Stack(); 
    
    T Pop();
    void Push(T);
      
 };
 
 template <class T>
 Stack<T>::~Stack()
 {
   if(this->ptr != NULL)
   {
    delete []ptr;
   }	 
 }
 
 template <class T>
 void Stack<T>::Push(T value)
 {
   if((this->size)-1 == this->top)
   {
      return;
   }
   
   else
   {
     ++top;
     ptr[top]=value;
   }
 }
 
 template <class T>
 T Stack<T>::Pop()
 {
   if(top==-1)
   {
    return 0;
   }   
   else
   {     
     T iret=ptr[top];
     top--;
     return iret;   
   } 
 }
 
 int main()
 {
   
   Stack <int>obj1;
   Stack <char>obj2;
   Stack <float>obj3;
   Stack <double>obj4;
   
   
   obj1.Push(10);
   obj1.Push(33);
   obj2.Push('A');
   obj3.Push(10.22);
   obj4.Push(15.5);
   cout<<obj1.Pop()<<endl;
   cout<<obj1.Pop()<<endl;
   cout<<obj2.Pop()<<endl;
   cout<<obj3.Pop()<<endl;
   cout<<obj4.Pop()<<endl;  
 
 }
