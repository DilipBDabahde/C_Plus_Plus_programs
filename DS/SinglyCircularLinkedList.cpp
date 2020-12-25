//singly circular linked list in c++

#include<iostream>
#include<stdlib.h>

using namespace std;

#define True 1
#define False 0

typedef int BOOL;

struct node
{
	int data;
	struct node *next;
};

typedef node NODE;
typedef NODE *PNODE;
typedef PNODE *PPNODE;

//class forming with characters and behavirous

class Singly_Circular_LinkedList
{
	private:
		PNODE Head;
		PNODE Tail;
	
	public:
		Singly_Circular_LinkedList();
		~Singly_Circular_LinkedList();
		
		BOOL InsertFirst(int);
		BOOL InsertLast(int);
		BOOL InsertAtPose(int,int);
		
		BOOL DeleteFirst();
		BOOL DeleteLast();
		BOOL DeleteAtPose(int);
		
		void Display();
		int Count();
};//when we create obj of this class then we can access chars and behaviour of this class


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
Singly_Circular_LinkedList::Singly_Circular_LinkedList()
{
	//resource allocation
	Head = NULL;
	Tail = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//destructor
Singly_Circular_LinkedList::~Singly_Circular_LinkedList()
{
	PNODE Temp = NULL, Navigate = Head;
	int icnt = Count();
	
	cout<<"de structure free all pending nodes"<<endl;
	cout<<"Total nodes are: "<<icnt<<endl;
		//resource deallocation
	
	if(Head != NULL  && Tail != NULL)
	{
		while(icnt != 0)
		{
			cout<<icnt<<endl;
			Temp = Head->next;
			delete Head;
			Head = Temp;
			icnt--;			
		}			
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//node Count
int Singly_Circular_LinkedList::Count()
{
	int icnt = 0;
	PNODE Temp = Head;
	
	if(Head == NULL && Tail == NULL)
	{
		return icnt;
	}
	
	do
	{
		icnt++;
		Temp = Temp->next;
	}while(Temp != Tail->next);
	
	return icnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//display nodes of list
void Singly_Circular_LinkedList::Display()
{
	PNODE Temp = Head;
	
	if(Head == NULL && Tail == NULL)
	{
		cout<<"There is no node in list"<<endl;
		return;
	}
	
	if(Head == Tail)// when there is one node in list
	{
		cout<<"|"<<Head->data<<"|->|NULL|"<<endl;		
	}
	else
	{	int icnt = Count();
		
		while(icnt != 0)
		{
			cout<<"|";
			cout<<Temp->data;
			cout<<"|->";
			Temp = Temp->next;	
			icnt--;		
		}
		cout<<"|NULL|"<<endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//insert first node
BOOL Singly_Circular_LinkedList::InsertFirst(int value)
{
	PNODE newn = NULL;
	
	//memory allocation
	newn = new NODE;
	
	if(newn == NULL)
	{
		cout<<"There is no enogh memory"<<endl;
		return False;
	}
	
	//memory initialization
	newn->next = NULL;
	newn->data = value;
	
	if(Head == NULL && Tail == NULL)
	{
		Head = newn;
		Tail = newn;
		Tail->next = Head;		
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Tail->next = Head;
	}
	return True;	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//insert node at last of ourlist
BOOL Singly_Circular_LinkedList::InsertLast(int value)
{
	PNODE newn = NULL;
	
	//memory allocation
	newn = new NODE;
	
	if(newn == NULL)
	{
		cout<<"There is no enough memory"<<endl;
		return False;
	}
	
	newn->next = NULL;
	newn->data = value;	
	
	if(Head == NULL && Tail == NULL) //when there is no node in list
	{
		Head = newn;
		Tail = newn;
		Tail->next = Head;
	}
	else	//when there is at least one node in list
	{
		Tail->next = newn;
		Tail = newn;
		Tail->next = Head;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//insert node at perticular position
BOOL Singly_Circular_LinkedList::InsertAtPose(int pose, int value)
{
	int icnt = Count();
	
	if(pose < 0 || pose > icnt+1)
	{
		cout<<"invalid position"<<endl;
		return False;
	}
	
	if(pose == 1)
	{
		return (InsertFirst(value));
	}
	else if(pose == icnt+1)
	{
		return (InsertLast(value));
	}
	else
	{
		PNODE Temp1 = Head;
		PNODE newn  = NULL;
		
		newn  = new NODE;
		
		newn->next = NULL;
		newn->data = value;
		
		for(int i = 1; i <= (pose-2); i++)
		{
			Temp1 = Temp1->next;
		}
		
		newn->next = Temp1->next;
		Temp1->next = newn;
	}
	
	return True;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//delete first node of list
BOOL Singly_Circular_LinkedList::DeleteFirst()
{
	PNODE Temp = Head;
	
	if(Head == NULL && Tail == NULL)
	{
		cout<<"There is no node in list"<<endl;
		return False;
	}
	else if(Head == Tail)
	{
		delete Head;
		Tail = NULL;
		Head = NULL;
	}
	
	Head = Head->next;
	Tail->next = Head;	
	 
	delete Temp;	
	
	return True;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//delete last node from list
BOOL Singly_Circular_LinkedList::DeleteLast()
{
	if(Head == NULL && Tail == NULL)
	{
		return False;
	}	
	else if(Head == Tail)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		PNODE Temp = Head;
		
		while(Temp->next != Tail)
		{
			Temp = Temp->next;
		}
		
		Temp->next = Head;
		Tail->next = NULL;
		delete Tail;
		Tail = Temp;
	}
	
	return True;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//delete node at particular position
BOOL Singly_Circular_LinkedList::DeleteAtPose(int pose)
{

	if(pose <= 0 || pose > (Count()) || (Head == NULL && Tail == NULL))
	{
		return False;
	}
	else if(pose == 1)
	{
		return (DeleteFirst());
	}
	else if(pose == (Count()))
	{
		return (DeleteLast());
	}
	else
	{
		PNODE Temp1 = Head, Temp2 = NULL;
		
		for(int i = 1; i <= (pose-2); i++)
		{
			Temp1 = Temp1->next;
		}
		
		Temp2 = Temp1->next;
		Temp1->next = Temp2->next;
		Temp2->next = NULL;
		delete Temp2;
	}
	
	return True;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//entry point function
int main()
{
	cout<<"inside main"<<endl;
	
	//object creating
	Singly_Circular_LinkedList scllObj;
	
	
	//insert node at first
	cout<<"\nInsertFirst node in list"<<endl;
	scllObj.InsertFirst(11);
	scllObj.InsertFirst(21);
	scllObj.InsertFirst(51);
	scllObj.InsertFirst(101);
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	
	//insert node at last of list
	cout<<"InsertLast node in list"<<endl;
	scllObj.InsertLast(151);
	scllObj.InsertLast(221);
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	
	//insert node at perticular position in list
	cout<<"Insert at particular position"<<endl;
	scllObj.InsertAtPose(3, 111);
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	
	scllObj.InsertAtPose(5, 222);
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	//deleting nodes of list
	//delete first node
	cout<<"Delete first node from list"<<endl;
	scllObj.DeleteFirst();
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	
	//delete last node of list
	cout<<"Delete last node from list"<<endl;
	scllObj.DeleteLast();
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	
	//delete node at particular position
	cout<<"Delete node at particular position"<<endl;
	scllObj.DeleteAtPose(3);
	scllObj.Display();
	cout<<"Nodes are: "<<scllObj.Count()<<"\n\n";
	

	
	return 0;
}
