//in this program we are create a stack using structure 

#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;	


struct node
 {
   int data;
   struct node *next;
 };
 
 typedef struct node NODE;
 typedef struct node *PNODE;
 typedef struct node **PPNODE;
 
 
 class Stack
  {
    
    private:
    	   PNODE Head;
    
    public:
     	  
     	  Stack();    //constructor
     	  ~Stack();   //destructor
     	  Stack(Stack&);
     	  void Push(int);
   	  int Pop();
   	  void Display();
  };
  
  Stack::Stack()
  {
    Head=NULL;	
  }
  
  
  Stack::~Stack()
  {    
    PNODE Temp=NULL;
    
    while(1)
   {
      Temp=Head;
      if(Temp==NULL)
      {
         break;
      }
      Head=Head->next;
      delete Temp;   
   }  
  } 
  
  void Stack::Push(int value)
   {
     PNODE newn=NULL;
     newn=new NODE;
     
     newn->data=value;
     newn->next=NULL;
    
       newn->next=Head;
       Head=newn;    
      
   }
   
   int Stack::Pop()
   {
    int iNo=0;
    PNODE Temp=NULL;
    
    if(Head==NULL)
     {
       return -1;
     }
     else
     {
     
       Temp=Head;
       Head=Head->next;
       iNo=Temp->data;
       delete Temp;
       return iNo;     
     }  
   }
   
   
   void Stack::Display()
   {
     PNODE Temp=Head;
     
     while(Temp != NULL)
     {
       cout<<"|"<<Temp->data;
       Temp=Temp->next;
     }
     cout<<"|NULL--->"<<endl;
   }
  
  //copy constructor in c++
  
  Stack::Stack(Stack &ref)
  {    
     this->Head=ref.Head; 
  }
  
  int main()
  {
  
    Stack obj1;
    int iret=0;
    
    obj1.Push(11);
    obj1.Push(43);
    obj1.Push(95);
    obj1.Push(73);
    obj1.Push(34);
    obj1.Push(46);
    obj1.Display();
    cout<<"Last Pop\n";
    cout<<obj1.Pop()<<endl;
    
    cout<<"--------------------------------\n";
    cout<<"Second obj\n";
    Stack obj2;
    obj2.Push(5);
    obj2.Push(6);
    obj2.Push(3);
    obj2.Push(7);
    obj2.Display();	
    
    cout<<"Last Pop\n";
    cout<<obj2.Pop()<<endl;    
    
    cout<<"------------------------------------\n";
    cout<<"Copy constructor\n";
    Stack obj3(obj2);
    obj3.Display();
    obj3.Pop();
    obj3.Display();  
    
    
    return 0;
  }
