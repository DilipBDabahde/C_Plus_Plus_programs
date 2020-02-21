//DoublyCircular linked list using c++

#include<iostream>

using namespace std;

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}NODE, *PNODE;

class DoublyCircularLL
{
	private:
	PNODE Head;
	PNODE Tail;
	int size;
	
	public:
	DoublyCircularLL();
	~DoublyCircularLL();
	
	void InsertAtFirst(int);
	void InsertAtLast(int);
	void InsertAtPose(int,int);
	void DeleteAtFirst();
	void DeleteAtLast();
	void DeleteAtPose(int);
	void DisplayF();
	void DisplayB();
	int  Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////

DoublyCircularLL::DoublyCircularLL()
{
	//allocated resources initialization
	cout<<"Inside constructor"<<endl;
	Head = NULL;
	Tail = NULL;
	size = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

DoublyCircularLL::~DoublyCircularLL()
{
	//allocated resources deallocation
	
	cout<<"Inside destructor"<<endl;

}

////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::InsertAtFirst(int value)
{
	cout<<"inside InsertAtFirst"<<endl;
	PNODE Newn = NULL;
	Newn = new NODE; //memory allocation
						//       ____________________
	Newn->next = NULL;  //		| NULL |value | NULL |
	Newn->prev = NULL;  // 		|______|______|______|
	Newn->data = value; //		100    104    108   112

	if(Head == NULL && Tail == NULL && size == 0)
	{
		Head = Newn;
		Tail = Newn;
		size++;
	}
	else
	{
		Newn->next = Head;
		Head->prev = Newn;
		Head = Newn;	
		
		Tail->next = Head;
		Head->prev = Tail;
		size++;		
	}
	
}	


////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::DisplayF()
{
	cout<<"Inside DisplayF"<<endl;
	PNODE Temp1 = Head, Temp2 = Tail;
	do
	{
		cout<<"|"<<Temp1->data<<"|->";
		Temp1 = Temp1->next;
	}while(Temp1 != Temp2->next);
	cout<<"|NULL|"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void DoublyCircularLL::DisplayB()
{
	PNODE Temp1 = Head, Temp2 = Tail;
	cout<<"inside DisplayB"<<endl;
	do	
	{
		cout<<"|"<<Temp2->data<<"|->";
		Temp2 = Temp2->prev;	
	}while(Temp2 != Temp1->prev);
	cout<<"|NULL|"<<endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::InsertAtLast(int value)
{
	cout<<"inside InsertAtLast"<<endl;
	PNODE newn = NULL;
	newn = new NODE;
	
	newn->next = NULL;
	newn->prev = NULL;
	newn->data = value;
	
	if(Head == NULL  && Tail == NULL && size == 0)
	{
		Head=Tail=newn;
		size++;
	}
	
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
		
		Tail->next = Head;
		Head->prev = Tail;	
		size++;
	}

}


////////////////////////////////////////////////////////////////////////////////////////////////
int DoublyCircularLL::Count()
{
	return size;
}


////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::InsertAtPose(int value, int Pose)
{
	if(Pose < 1 || Pose > size+1)
	{
		return;
	}
	
	if(Pose == 1)
	{
		 InsertAtFirst(value);
	}
	else if(Pose == size+1)
	{
		InsertAtLast(value);
	}
	else
	{
		PNODE newn = NULL, Temp1 = Head;
		newn = new NODE;
		newn->data =value;
		newn->next = NULL;
		newn->prev = NULL;
		
		for(int i = 1; i<=(Pose-2);i++)
		{
			Temp1 = Temp1->next;
		}	
		
		newn->next = Temp1->next;
		Temp1->next->prev = newn;
		Temp1->next = newn;
		newn->prev =Temp1;	
		size++;	
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::DeleteAtFirst()
{
	cout<<"inside DeleteAtFirst"<<endl;
	
	if(Head==NULL && Tail == NULL && size==0)
	{
		return;
	}
	
	if(Head == Tail)
	{
		delete Head;
		Head = Tail = NULL;
		size--;
	}
	else
	{
		PNODE Temp = Head;
		
		Head = Head->next;
		Tail->next = Head;
		Head->prev = Tail;
		
		delete Temp;	
		size--;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::DeleteAtLast()
{
	cout<<"inside DeleteAtLast"<<endl;
	if(Head == Tail)
	{
		delete Head;
		Head = Tail = NULL;
		size--;
	}
	else
	{
		PNODE Temp = Tail;
		Tail = Tail->prev;
		Tail->next= Head;
		Head->prev = Tail;
		delete Temp;
		size--;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCircularLL::DeleteAtPose(int Pose)
{
	cout<<"inside DeleteAtPose"<<endl;
	
	if(Pose < 1 || Pose > size)
	{
		return;	
	}
	
	if(Pose==1)
	{
		DeleteAtFirst();
	}
	else if(Pose==size)
	{
		DeleteAtLast();	
	}
	else
	{
		PNODE Temp1 = Head, Temp2 = NULL;
		
		for(int i = 1; i<=(Pose-2);i++)
		{
			Temp1 = Temp1->next;
		}
		
		Temp2 = Temp1->next;
		Temp1->next = Temp2->next;
		Temp2->next->prev = Temp1;
		delete Temp2;	
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	cout<<"Inside main"<<endl;

	DoublyCircularLL obj1;
	
	obj1.InsertAtFirst(11);
	obj1.InsertAtFirst(32);
	obj1.InsertAtFirst(42);
	obj1.DisplayF();
	obj1.DisplayB();
	
	obj1.InsertAtLast(55);
	obj1.DisplayF();
	obj1.InsertAtLast(99);
	obj1.DisplayF();
	cout<<"Total nodes are: "<<obj1.Count()<<endl;
	
	obj1.InsertAtPose(17,3);
	obj1.InsertAtPose(18,1);
	obj1.DisplayF();
	cout<<"Total nodes are: "<<obj1.Count()<<endl;

	obj1.DeleteAtFirst();
	obj1.DisplayF();
	cout<<"Total nodes are: "<<obj1.Count()<<endl;

	
	obj1.DeleteAtLast();
	obj1.DisplayF();
	cout<<"Total nodes are: "<<obj1.Count()<<endl;
	
	obj1.DeleteAtPose(3);
	obj1.DisplayF();
	cout<<"Total nodes are: "<<obj1.Count()<<endl;
	
	
	return 0;
}
