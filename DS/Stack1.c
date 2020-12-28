/*
Dynamic implementation of stack using C++
*/

//header file inclusion
#include<iostream>

using namespace std;

//structure declaration
struct node
{
	int data;
	struct node *next;
};

//creating user defined types
typedef struct node NODE;
typedef struct node *PNODE;


//class declaration 
class Stack
{
	private:		//for abstraction
		PNODE Head;
	
	public:
		Stack();   //constructor to resource allocation
		~Stack(); //destructor to resource deallocate
		
		
	void push(int);  //to insert element into stack at top
	int pop();		//to remove element from stack at top
	int peep();		//to remove values from this stackframe but do not free memory of that location
	void display();	//it helps to display values of stack
	void freeAll(); 	//this behaviour is used to free all elements from stack
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Stack::Stack()
{	
	//resource allocation
	Head = NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Stack::~Stack()
{
	//resource deallocation 
	
		
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//adding elements into stack 

void Stack::push(int value)
{
	PNODE newn = NULL;	//pointer creation
	
	//memory allocation
	newn  = new NODE;  //allcationg memory of size NODE
	
	
	//memory initialization
	newn->next = NULL;
	newn->data = value;
	
	if(Head == NULL)	//when there is no elements into stack then we add first element into stack
	{
		Head = newn;
	}
	else
	{
		newn->next = Head;
		Head = newn;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//removing elements of stack

int Stack::pop()
{
	if(Head == NULL)
	{
		return 0;
	}
	else
	{
		PNODE Temp = Head;
		Head = Head->next;
		int ret = Temp->data;
		delete Temp;
		return ret;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//free all elements

void Stack::freeAll()
{
	if(Head == NULL)
	{
		cout<<"There is no elements into stack"<<endl;
	}
	else
	{
		PNODE Temp = NULL;
		
		cout<<"free all elements"<<endl;
		
		while(Head != NULL)
		{
			Temp = Head;
			cout<<"|"<<Temp->data<<"|";
			Head = Head->next;
			delete Temp;
		}
		cout<<endl;
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Display elements of Stack

void Stack::display()
{
	PNODE Temp = Head;
	
	while(Temp != NULL)
	{
		cout<<"|"<<Temp->data;
		Temp = Temp->next;
	}
	
	cout<<"|NULL|"<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	cout<<"inside main"<<endl;
	
	Stack obj1;
	Stack obj2;
	
	//adding elements into stack
	cout<<"inserting elements into stack"<<endl;
	obj1.push(11);
	obj1.push(21);
	obj1.push(51);
	
	//display elements of stack
	cout<<"Display elements of stack"<<endl;
	obj1.display();
	
	cout<<endl;
	
	cout<<"poped value is: "<<obj1.pop()<<endl;
	cout<<"Display elements of stack"<<endl;
	obj1.display();
	
	cout<<endl;
	
	obj1.push(199);
	obj1.push(299);
	obj1.push(399);
	cout<<"Display elements of stack"<<endl;
	obj1.display();
	
	obj1.pop();
	cout<<"Display elements of stack"<<endl;
	obj1.display();
	
	obj1.freeAll();
	cout<<"Display elements of stack"<<endl; 
	obj1.display();
	
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
