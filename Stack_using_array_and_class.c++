/*
  in this program we take array size from user and allocated that size of memory on heap and hand over the address of allocated momory to arrr by using that array addrees and index we complete all operation of stack in Array

*/
#include<iostream>
#include<stdlib.h>

using namespace std;
class Stack_c
 {
   
    private:
    	  int Top;
    	  int *arr;
    	  int size;
    	  
    public:
    	  Stack_c(int); 	  
  	  Stack_c(Stack_c&);
 	  ~Stack_c();
 	  int Pop();
 	  void Push(int);
 	  void Display();
 };
 
 Stack_c::Stack_c(int length=5)
 {
    //resource allocation start we obj is created
    
    this->size=length;
    this->arr=new int[size];
    this->Top=-1;
 }
 
 Stack_c::~Stack_c()
 {
  delete []arr;
 }
 
 void Stack_c::Push(int value)
 {
      if(Top==size-1)
      {
         return;      
      }
      else
      {
         Top++;
         arr[Top]=value;      
      }
 }
 
 void Stack_c::Display()
 {
    for(int i=0;i<=Top;i++)
     {
     cout<<"|"<<arr[i];
    }
    cout<<"|NULL-->>\n"; 
 }
 
 int Stack_c::Pop()
 {
   int temp=0;
   
   if(Top==-1)
   {
    return -1;
   }
   else
   { 
   temp=arr[Top];
   Top--;
   return Top;
   } 
 }


 // now we have to create copy constructor
 
 Stack_c::Stack_c(Stack_c&ref)
 {
    this->size=ref.size;
    this->Top=ref.Top;
    this->arr=new int[size];
    
    for(int i=0;i<=Top;i++)
     {
      this->arr[i]=ref.arr[i];           
     } 
 }
 
 

 int main()
  {
     Stack_c obj1,obj2,obj3(3);  //4 object created
     cout<<"----------------------------------------\n";
     cout<<"First obj inserted values"<<endl;
     obj1.Push(11);
     obj1.Push(54);
     obj1.Push(25);
     obj1.Push(41);
     obj1.Display();
     cout<<"one Pop\n";
     obj1.Pop();     //remove last index 
     obj1.Display();
     cout<<"----------------------------------------\n";
 
     cout<<"Second obj inserted values"<<endl;
     obj2.Push(111);
     obj2.Push(222);
     obj2.Push(333);
     obj2.Push(444);
     obj2.Push(555);
     obj2.Display();
     cout<<"one Pop\n";
     obj2.Pop();
     obj2.Display();
     
     cout<<"----------------------------------------\n";
     cout<<"Third obj inserted values"<<endl;
     obj3.Push(30);
     obj3.Push(20);
     obj3.Push(10);
     obj3.Push(40);   //in this case we can Push only insert 3 values bcs we lock obj size while creating obj(3)
     obj3.Display();
     cout<<"one Pop--->> we inserted 4 but added actual  3 ingnored because object located at 3\n";
     obj3.Display();
     
     
     cout<<"----------------------------------------\n";
     cout<<"copy constructor"<<endl;
     Stack_c obj4(obj2);
     obj4.Display();
     obj4.Pop();
     cout<<"One Pop\n";
     obj4.Display();     
     
     cout<<"----------------------------------------\n";
     cout<<"by using class pointer\n";
     Stack_c *sptr=NULL;
     sptr=new Stack_c(7);
          
     sptr->Push(200);
     sptr->Push(300);
     sptr->Display();
     
     delete sptr;

     
     
   return 0;  
  }
