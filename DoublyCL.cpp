/*
2.Implement Doubly Circular linked list in C++?
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct node
 {
   int data;
   struct node *next;
   struct node *prev; 
 }NODE,*PNODE,**PPNODE;
 
 class DoublyCL
 {
    private:
    	PNODE Head;
    	PNODE Tail;
    	int Size;
    
    public: 	
    	DoublyCL();
	~ DoublyCL();
	int Count();
	void DisplayF();
	void InsertFirst(int);
	void SumAll();
	void DisplayB();
	void InsertLast(int);
	void InsertAtPos(int,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);	 
 };
 
 DoublyCL::DoublyCL()
 {
    Head=NULL;
    Tail=NULL;
    Size=0; 
 }
 
 DoublyCL::~DoublyCL()
 {
   
 
 }
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void DoublyCL::InsertFirst(int value)
  {
     PNODE newn=new NODE;
     newn->next=NULL;
     newn->prev=NULL;
     newn->data=value;
    
     if(Head==NULL && Tail==NULL)
    {
      Head=newn;
      Tail=newn;
      Head->prev=newn;
      Tail->next=newn;
      Size++;
    }
    else
    {
      newn->next=Head;
      Head->prev=newn;
      Head=newn;
      Head->prev=Tail;
      Tail->next=Head;  
      Size++;
    }    
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void DoublyCL::DisplayF()
 {
   PNODE Temp=Head;
   
   for(int i=1;i<=this->Size;i++)
    {
        cout<<"|"<<Temp->data;
        Temp=Temp->next;
    } 
    cout<<"|-->>NULL"<<endl;
 }  


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 int DoublyCL::Count()
 {
  return Size;
 }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::InsertLast(int value)
 {
    PNODE newn=new NODE;
    
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=value;
    
     if(Head==NULL && Tail==NULL)
    {
      Head=newn;
      Tail=newn;
      Head->prev=newn;
      Tail->next=newn;
      Size++;
    }
    else
    {
      Tail->next=newn;
      newn->prev=Tail;
      Tail=newn;
      Head->prev=newn;
      Tail->next=Head;      
      Size++;
    }     
 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::SumAll()
 {
   PNODE Temp=Head;
   
   int i=0,total=0;
   for(i=1;i<=this->Size;i++)
    {
     total+=Temp->data;
     Temp=Temp->next;
    }
    
    cout<<"SumAll is "<<total<<endl;   
 }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::InsertAtPos(int value,int Pose)
 {
    
    int icnt=this->Size;
    
    if(Pose<0 || Pose>icnt+1)
     {
      return;
     }
    
    if(Pose==1)
     {
       InsertFirst(value);
     }
     else if(Pose==icnt+1)
     {
       InsertLast(value);
     }
     else
     {
       PNODE newn=new NODE,Temp=Head;
       
       newn->next=NULL;
       newn->prev=NULL;
       newn->data=value;
       
       for(int i=0;i<Pose-2;i++)
       {
         Temp=Temp->next;        
       }
      
        newn->next=Temp->next;
        //newn->next->prev=newn; 
        Temp->next->prev=newn;    //we can above too
        Temp->next=newn;
        newn->prev=Temp;
        Size++;     
     }
 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::DisplayB()
  {
     PNODE Temp=Tail;
     for(int i=0;i<this->Size;i++)
     {
       cout<<"|"<<Temp->data;
       Temp=Temp->prev;     
     }
     cout<<"|"<<endl;
     cout<<endl;  
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::DeleteFirst()
  {
      
    if(Head==NULL || Tail==NULL)
     {
      return;
     }  
     
    if(Head==Tail)
     {
       delete Head;
       Head=NULL;
       Tail=NULL;
               
        Size--;
     }
     else
     {
        Head=Head->next;
        Head->prev=Tail;
        delete Tail->next;
        Tail->next=Head;        
        Size--;
     }  
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::DeleteLast()
 {
     if(Head==NULL || Tail==NULL)
     {
      return;
     }  
          
    if(Head==Tail)
     {
       delete Head;
       Head=NULL;
       Tail=NULL;               
       Size--;
     }
     else
     {     
       Tail=Tail->prev;
       delete Head->prev;
       Tail->next=Head;
       Head->prev=Tail;
       Size--;
     }
 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 void DoublyCL::DeleteAtPos(int Pose) 
  {
     if(Head==NULL || Tail==NULL)
      {
       return;
      }
     
     if(Pose<1 || Pose>this->Size) 
      {
       return;
      }
      
      if(Pose==1)
       {
          DeleteFirst();
       }
       else if(Pose==this->Size)
       {
          DeleteLast();
       }
       else
       {
       	      PNODE Temp1=Head,Temp2=NULL;
       
              for(int i=0;i<Pose-2;i++)
                {
                 Temp1=Temp1->next;
                }
                
                Temp2=Temp1->next;
                Temp1->next=Temp2->next;
                Temp2->next->prev=Temp1;
                delete Temp2;
                Size--;                
       } 
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 int main()
 {
 
    
  DoublyCL obj;
  cout<<"----------------------------------------------\n";
  cout<<"InsertedFirst\n";
  obj.InsertFirst(15);
  obj.InsertFirst(25);
  obj.InsertFirst(35);
  obj.InsertFirst(45);
  obj.InsertFirst(55);
  obj.DisplayF();
  cout<<"Total Notes are --> "<<obj.Count()<<endl;
  
  
  cout<<"----------------------------------------------\n";
  cout<<"InsertedLast\n";
  obj.InsertLast(65);
  obj.InsertLast(75);
  obj.DisplayF();
  cout<<"Total Notes are --> "<<obj.Count()<<endl;  
  
  
  cout<<"----------------------------------------------\n";
  cout<<"SumOfAll\n";
  obj.SumAll();
  
  
  cout<<"----------------------------------------------\n";
  cout<<"InsertedAtPose\n";
  obj.InsertAtPos(50,4);
  obj.DisplayF();
  obj.DisplayB();
  cout<<"Total Notes are --> "<<obj.Count()<<endl;  
  
  
  cout<<"----------------------------------------------\n";
  cout<<"DeleteFirst\n"; 
  obj.DeleteFirst();
  obj.DisplayF();
  obj.DisplayB();
  cout<<"Total Notes are --> "<<obj.Count()<<endl; 
  
  
  
  cout<<"----------------------------------------------\n";
  cout<<"DeleteLast\n"; 
  obj.DeleteLast();
  obj.DisplayF();
  obj.DisplayB();
  cout<<"Total Notes are --> "<<obj.Count()<<endl; 
  
  
  cout<<"----------------------------------------------\n";
  cout<<"DeleteAtPose\n"; 
  obj.DeleteAtPos(6);
  obj.DisplayF();
  obj.DisplayB();
  cout<<"Total Notes are --> "<<obj.Count()<<endl;  
  
 return  0;
 }
 
