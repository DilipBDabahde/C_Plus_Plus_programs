//queue ds use in c++

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

class Queue
{

	private:
		PNODE Head;
	
	public:
	Queue();
	Queue(Queue&);
	~Queue();
	
	void Count();
	void Enqueue(int);
	int Dequeue();
	void Display();
};

////////////////////////////////////////////////////////////////////////////////////
Queue::Queue()
{
	cout<<"inside constructor"<<endl;
	Head = NULL;

}

////////////////////////////////////////////////////////////////////////////////////

Queue::~Queue()
{
	cout<<"inside destructor"<<endl;
	
}

////////////////////////////////////////////////////////////////////////////////////

void Queue::Enqueue(int value)
{
	PNODE newn = NULL;
	newn = new NODE;
	
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

////////////////////////////////////////////////////////////////////////////////////

void Queue::Display()
{
	PNODE Temp = Head;
	while(Temp != NULL)
	{
		cout<<"|"<<Temp->data<<"|->";
		Temp = Temp->next;
	}
	cout<<"|NULL|"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////

void Queue::Count()
{	
	int icnt = 0;
	PNODE Temp = Head;
	while(Temp != NULL)
	{
		icnt++;
		Temp = Temp->next;
	}
	cout<<"Total elements in queue is :"<<icnt<<endl;
}
////////////////////////////////////////////////////////////////////////////////////

int Queue::Dequeue()
{
 	int icnt = 0;
 	
 	if(Head == NULL)
	{
		return -1;
	}
	else if(Head->next == NULL)
	{
		icnt = Head->data;
		delete Head;
		Head = NULL;
	}
	else
	{
		PNODE Temp = Head;
		icnt = Head->data;
		Head = Head->next;
		delete Temp;	
	}

	return icnt;

}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Queue obj1;
	
	obj1.Enqueue(11);
	obj1.Enqueue(22);
	obj1.Enqueue(33);
	obj1.Display();
	obj1.Count();
	
	Queue obj2;
	obj2.Enqueue(111);
	obj2.Enqueue(222);
	obj2.Enqueue(333);
	obj2.Display();
	obj1.Count();
	
	int value = obj1.Dequeue();
	cout<<"Dequeue value from elements: "<<value<<endl;
	obj1.Display();
	
	value = obj2.Dequeue();
	cout<<"Dequeue value from elements: "<<value<<endl;
	obj2.Display();
 return 0;

}
