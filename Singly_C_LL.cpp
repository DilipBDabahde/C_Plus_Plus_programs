//Singly_Circular_Linked_List_Using_C++

#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

typedef struct node
 {
   int data;
   struct node* next;   
 }NODE,*PNODE,**PPNODE;


class Singly_C_G
 {
    private:
      PNODE Head;
      PNODE Tail; 
      int Size;    //we created 3 charactristic they are privte
      
   public:
   	 Singly_C_G();  //default constructor
         ~Singly_C_G();  //destruct
         void InsertFirst(int);
         void InsertLast(int);
         void InsertAtPose(int,int);
         void Display();
         int  Count();
         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPose(int);  
 };  //end of class

 Singly_C_G::Singly_C_G()
 {
   Head=NULL;
   Tail=NULL;
   Size=0;           //private charstics defautl define now here at begining 
 } 
 
 Singly_C_G::~Singly_C_G()
 { 
  PNODE Temp=Head;
      
  for(int i=0;i<Size;i++)
   {
      Head=Head->next;
      delete Temp;
      Tail->next=Head;  //we can skip this line  
      Temp=Head;
   }
 }
 
void Singly_C_G::InsertFirst(int value)
 {
    PNODE newn=NULL;
    newn=new NODE;   //newn gets address of allocated size of heap
    
    newn->next=NULL;
    newn->data=value;
    
    if(Size==0)  //Size==0
    {
        Head=newn;
        Tail=newn;
        Tail->next=Head;
    }
    else
    {
       newn->next=Head;
       Head=newn;
       Tail->next=Head;   
    }
    Size++; 
 }
 
void Singly_C_G::Display()
 {
   PNODE Temp=this->Head;
   for(int i=0;i<Size;i++)
    {
     cout<<Temp->data<<" ";
     Temp=Temp->next;    
    } 
 }
 
 void Singly_C_G::InsertLast(int value)
 {
    PNODE newn=NULL;
    newn=new NODE;     //address allcoated to newn 
    
    newn->data=value;
    newn->next=NULL;	//node created with its data and null ptr
    
    if(Size==0)    
     {
        Head=newn;
        Tail=newn;
        Tail->next=Head;     
     }
     else
     {
        Tail->next=newn;
        Tail=Tail->next;
        Tail->next=Head;        
     } 
      Size++; 
 }
 
 int Singly_C_G::Count()
  {
    return Size;  
  }
 
 void Singly_C_G::InsertAtPose(int value,int Pose)
  {
    PNODE Temp=Head;
    int icnt=Count();
    
    if(Pose<0 || Pose>icnt+1)
    {
     return;
    }
    
    if(Pose==1)
     {
       InsertFirst(value);
     }
     else if(Pose==icnt)
     {
        InsertLast(value);
     }
     else
     {
       PNODE newn=NULL;
       newn=new NODE;
       newn->data=value;
       newn->next=NULL;
       
       for(int i=0;i<Pose-2;i++)
          {
           Temp=Temp->next;          
          }
          
          newn->next=Temp->next;
          Temp->next=newn; 
          Size++;   
     }  
  }
 
  void Singly_C_G::DeleteFirst()
  {
     PNODE Temp=Head;
     if(Size==0)
      {
       return;
      }
      if(Size==1)
      {
        delete Temp;
        Head=NULL;
        Tail=NULL;
      }
      else
       {
          Head=Head->next;
          Tail->next=Head;
          delete Temp;
          
       }
      
       Size--;	 
  }
  
  void Singly_C_G::DeleteLast()
  {
     PNODE Temp1=Head,Temp2=NULL;
     if(Size==0)
     {
      return;
     }
     else if(Size==1)
     {
        delete Temp1;
        Head=NULL;
        Tail=NULL;
     }
     else
     {
          while(Temp1->next != Tail)
          {
            Temp1=Temp1->next;          
          }
          
          Temp2=Temp1->next;          
         // Tail=Temp1;
          Temp1->next=Head;
          Tail=Temp1;
          delete Temp2;
     }     
     Size--;  
  }
  
  
  void Singly_C_G::DeleteAtPose(int Pose)
  {
   
    PNODE Temp1=Head,Temp2=NULL;
    
    int icnt=Count();
    
    if(Size==0)
    {
     return;
    }
    if(Pose<0 || Pose>icnt)
    {
     return;
    }
    
    if(Pose==1)
    {
      DeleteFirst();
    }
    else if(Pose==icnt)
    {
      DeleteLast();
    }
    else
     {
         for(int i=0;i<Pose-2;i++)
         {
          Temp1=Temp1->next;
         }
         
         Temp2=Temp1->next;
         Temp1->next=Temp2->next;
         delete Temp2;
         Size--;    
     }
  
  }
  
  
 int main()
 {
   
   Singly_C_G obj;
   
   cout<<"---------------------\n";
   cout<<"InsertFirst\n";
   obj.InsertFirst(44);
   obj.InsertFirst(67);
   obj.InsertFirst(53);
   obj.InsertFirst(11);
   obj.InsertFirst(51);
   obj.Display();
   cout<<"\n---------------------";
   cout<<endl;
   
   cout<<"Inserted at last\n";
   obj.InsertLast(57);
   obj.Display();
   cout<<"\nTotal Nodes "<<obj.Count();
 

   cout<<"\n---------------------\n";
   cout<<"InsertAtPose\n";
   obj.InsertAtPose(70,2);   
   obj.Display();
   cout<<"\nTotal Nodes "<<obj.Count();
   cout<<endl;
   
   cout<<"---------------------\n";
   cout<<"DeleteFirst\n";
   obj.DeleteFirst();
   obj.Display();
   cout<<"\nTotal Nodes "<<obj.Count();
   cout<<endl;
  
   cout<<"---------------------\n";
   cout<<"DeleteLast\n";
   obj.DeleteLast();
   obj.Display();
   cout<<"\nTotal Nodes "<<obj.Count();
   cout<<endl;
   
   cout<<"---------------------\n";
   cout<<"DeleteLast\n";
   obj.DeleteAtPose(3);
   obj.Display();
   cout<<"\nTotal Nodes "<<obj.Count();
   cout<<endl;
   
   
 
 return 0;
 }
