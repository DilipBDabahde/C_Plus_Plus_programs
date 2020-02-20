//singlyCircular Linked list


#include<iostream>

using namespace std;

#define True 1
#define False 0

typedef int BOOL;


 struct  node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


class SinglyCircularLinkedList
{
	private:
		PNODE Head;
		PNODE Tail;
		
	public:
	
	SinglyCircularLinkedList();
	~SinglyCircularLinkedList();
	
	BOOL InsertAtFirst();
	


};

SinglyCircularLinkedList::SinglyCircularLinkedList()
{
	cout<<"Inside constructor\n";
	Head = NULL;
	Tail = NULL;
}

SinglyCircularLinkedList::~SinglyCircularLinkedList()
{
	cout<<"Inside Destructor\n";
	PNODE Temp;
	int icnt = Count();
	
}

int main()
{

	SinglyCircularLinkedList obj1;
	
	






	return 0;
}
