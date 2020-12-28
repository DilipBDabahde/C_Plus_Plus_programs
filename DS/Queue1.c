/*
Linear queue implementation in  c++
*/


//file inclusion
#include<iostream>

using namespace std;

//creating user defined data type
typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;


//class declaration
class Queue
{
	private:
		PNODE Head;
	
	
	public:
		Queue();	//constructor
		~Queue();
		
		void Enqueue(int);
		int Dequeue();
		void Display();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Queue::Queue()	//constructor
{
	Head = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Queue::~Queue()	//destructor
{
	PNODE Temp = Head;
	while(Head != NULL)
	{
		Head = Head->next;
		delete Temp;
		Temp = Head;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//

void Queue::Display()
{
	PNODE Temp = Head;
	
	if(Head == NULL)
	{
		cout<<"There is no elements into queue\n";
		return;	
	}
	else
	{
		while(Temp != NULL)
		{
			cout<<"|"<<Temp->data;
			Temp = Temp->next;
		}
		cout<<"|NULL|"<<endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//inserting elements into queue
void Queue::Enqueue(int value)
{
	//creating pointer
	PNODE newn = NULL;
	
	//memory allocation
	newn = new NODE;
	
	//memory initialization
	newn->next = NULL;
	newn->data = value;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		PNODE Temp = Head;
		
		while(Temp->next != NULL)
		{
			Temp = Temp->next;
		}
		
		Temp->next = newn;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//remove elements from queue

int Queue::Dequeue()
{
	if(Head == NULL)
	{
		return 0;
	}
	else
	{
		PNODE Temp = Head;
		int ret = Head->data;
		Head = Head->next;
		delete Temp;
		return ret;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int  main()
{
	Queue obj1;
	Queue obj2;
	
	//Enqueu elements into queue
	cout<<"Enqueuing elements into queue"<<endl;
	obj1.Enqueue(11);
	obj1.Enqueue(21);
	obj1.Enqueue(51);
	obj1.Enqueue(101);
	
	cout<<"Displaying elements of queue"<<endl;
	obj1.Display();
	
	cout<<"\nElements removed is: "<<obj1.Dequeue()<<endl;
	cout<<"Displaying elements of queue"<<endl;
	obj1.Display();
	
		
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

