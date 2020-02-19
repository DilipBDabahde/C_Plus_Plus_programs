#include<iostream>

#define True 1
#define False 0

using namespace std;

typedef int BOOL;


typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE, **PPNODE;


class SinglyLinkedList
{
	private:
	PNODE Head;
	
	public:
	SinglyLinkedList();
	~SinglyLinkedList();
	BOOL InsertAtFirst(int);
	BOOL InsertAtLast(int);
	BOOL InsertAtPose(int,int);
	BOOL DeleteAtFirst();
	BOOL DeleteAtLast();
	BOOL DeleteAtPose(int);
	void Display();
	int Count();
		


};

///////////////////////////////////////////////////////////////////////////////////////////////

SinglyLinkedList::SinglyLinkedList()
{
	
	cout<<"Inside Constructor\n";
	Head = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////


SinglyLinkedList::~SinglyLinkedList()
{
	cout<<"Inside Destructor\n";
	PNODE Temp, Navigate;
	int icnt = 0;
	if(Head != NULL)
	{
		Navigate = Head;
		while(Navigate != NULL)
		{
			icnt++;
			Temp = Navigate->next;
			delete Navigate;
			Navigate = Temp;
		}
		Head = NULL;
	}
	cout<<icnt<<" "<<Head<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

BOOL SinglyLinkedList::InsertAtFirst(int value)
{
	printf("InsertAtFirst\n");
	PNODE newn = NULL;
	newn = new NODE;    //by using new kw,NODE type memory gets allocated and return address of allcated memory to newn
	
	if(newn == NULL)
	{
		return False;
	}
	
	newn->next = NULL;
	newn->data = value;
	
	if(Head == NULL)
	{	
		Head = newn;
	}
	else
	{
		newn->next = Head;
		Head=newn;	
	}
	return True;
}	//end of InsertAtFirst
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLinkedList::Display()
{
	cout<<"Inside Display"<<endl;
	
	PNODE Temp = Head;
	
	while(Temp != NULL)
	{
		cout<<"|"<<Temp->data<<"|->";
		Temp = Temp->next;
	}	
	cout<<"|NULL|"<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLinkedList::Count()
{
	int icnt = 0;
	
	PNODE Temp = Head;
	while(Temp != NULL)
	{
		icnt++;
		Temp = Temp->next;
	}
	return icnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////
BOOL SinglyLinkedList::InsertAtLast(int value)
{
	PNODE newn = NULL;
	newn = new NODE;	//memory allocation
	
	if(newn == NULL)
	{
		return False;
	}
	
	newn->data= value;
	newn->next= NULL;
	
	if(Head == NULL)	//there is no NODE then get in
	{
		Head = newn;
	}
	else	// there is more than one node
	{
		PNODE Temp = Head;
		while(Temp->next != NULL)
		{
			Temp = Temp->next;
		}
		
		Temp->next = newn;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL SinglyLinkedList::InsertAtPose(int value, int Pose)
{
	cout<<"InsertAtPose"<<endl;
	
	int size = Count();
	
	if(Pose < 1 || Pose >size+1)	
	{
		return False;
	}
	
	if(Pose==1)
	{
		InsertAtFirst(value);
	}
	else if(Pose==size+1)
	{
		InsertAtLast(value);
	}
	else
	{
		PNODE newn = NULL;
		PNODE Temp = Head;
		newn = new NODE;
		
		newn->next = NULL;
		newn->data = value;
		
		for(int i= 1; i<=(Pose-2);i++)
		{
			Temp = Temp->next;
		}
		
		newn->next= Temp->next;
		Temp->next = newn;	
	}
	return True;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL SinglyLinkedList::DeleteAtFirst()
{

	cout<<"DeleteAtFirst\n";
	
	PNODE Temp = Head;
	
	if(Temp == NULL)
	{
		return False;
	}
	else
	{
		Head = Head->next;
		//free(Temp);	
		delete (Temp);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL SinglyLinkedList::DeleteAtLast()
{
	cout<<"DeleteAtLast\n";
	
	PNODE Temp =Head;
	
	if(Head == NULL)
	{
		return False;
	}
	else if(Temp->next == NULL)
	{
		delete (Temp->next);
		Head = NULL;
	}
	else
	{
		while(Temp->next->next != NULL)	
		{
			Temp = Temp->next;
		}
		delete (Temp->next);
		Temp->next = NULL;
	}	
}	

////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL SinglyLinkedList::DeleteAtPose(int Pose)
{
	int size = Count();
	
	if(Pose < 1 || Pose>size)
	{
		return False;
	}
	
	if(Pose == 1)
	{
		DeleteAtFirst();
	}
	else if(Pose == size)
	{
		DeleteAtLast();
	}
	else
	{
		PNODE Temp1= NULL, Temp2 = Head;
		for(int i = 1; i<=(Pose-2); i++)
		{
			Temp2 = Temp2->next;		
		}
		
		Temp1 = Temp2->next;
		Temp2->next = Temp1->next;
		delete Temp1;
		Temp1 = NULL;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

	SinglyLinkedList obj1;	
	SinglyLinkedList *obj2 = new SinglyLinkedList();
	
	BOOL Res = False;
	
	obj1.InsertAtFirst(11);
	obj1.InsertAtFirst(22);
	obj1.InsertAtFirst(33);		
	obj1.Display();
	
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	
	obj1.InsertAtLast(44);
	obj1.InsertAtLast(55);
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	
	
	obj1.InsertAtPose(155,4);
	obj1.InsertAtPose(202,2);
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	
	//now delete req nodes
	
	obj1.DeleteAtFirst();
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	obj1.DeleteAtFirst();
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	
	obj1.DeleteAtLast();
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;
	
	obj1.DeleteAtLast();
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;

	
	obj1.InsertAtFirst(33);
	obj1.InsertAtFirst(52);
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;

	obj1.DeleteAtPose(5);
	obj1.Display();
	cout<<"Totol nodes in linked list are "<<obj1.Count()<<endl;

 return 0;
}
