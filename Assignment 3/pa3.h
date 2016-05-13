#ifndef PA3_H
#define PA3_H
#include <string>

using namespace std;

class DynStack
{
	private:
		struct StackNode
		{
			string value;        // Value in the node 
			StackNode *next;  // Pointer to the next node 
		};  
		
		StackNode *top;      // Pointer to the stack top 
		
	public: 
		// Constructor 
		DynStack() 
		{  top = NULL; }  
		
		// Destructor 
		~DynStack(); 
		
		// Stack operations 
		void push(string); 
		void pop(string &); 
		bool isEmpty(); 
};

class DynQueue 
{ 
	private: 
	// Structure for the queue nodes 
	struct QueueNode 
	{ 
	string value;       // Value in a node 
	QueueNode *next; // Pointer to the next node 
	}; 

	QueueNode *front;  // The front of the queue 
	QueueNode *rear;   // The rear of the queue 
	int numItems;      // Number of items in the queue 
	public: 
	// Constructor 
	DynQueue();
	// Destructor
	~DynQueue(); 

	// Queue operations 
	void enqueue(string); 
	void dequeue(string &); 
	bool isEmpty() const; 
	bool isFull() const; 
	void clear(); 
}; 

DynStack::~DynStack() 
{ 
	StackNode *nodePtr, *nextNode;

	// Position nodePtr at the top of the stack. 
	nodePtr = top; 

	// Traverse the list deleting each node. 
	while (nodePtr != NULL) 
	{ 
		nextNode = nodePtr->next; 
		delete nodePtr; 
		nodePtr = nextNode; 
	} 
}

void DynStack::push(string ds) 
{
	StackNode *newNode; // Pointer to a new node 
 
	// Allocate a new node and store string there. 
	newNode = new StackNode; 
	newNode->value = ds; 

	// If there are no nodes in the list 
	// make newNode the first node. 
	if (isEmpty()) 
	{ 
		top = newNode; 
		newNode->next = NULL; 
	} 
	else  // Otherwise, insert NewNode before top.
	{ 
		newNode->next = top; 
		top = newNode; 
	} 
}
	
void DynStack::pop(string &ds) 
{ 
	StackNode *temp; // Temporary pointer 

	// First make sure the stack isn't empty. 
	if (isEmpty()) 
	{ 
		cout << "The stack is empty.\n"; 
	} 
	else  // pop value off top of stack
	{ 
		ds = top->value; 
		temp = top->next; 
		delete top; 
		top = temp; 
	} 
} 
	
bool DynStack::isEmpty()
{
	bool status; 
	
	if (!top) 
	status = true; 
	else 
	status = false; 
	
	return status; 
}
//Constructor
DynQueue::DynQueue() 
{ 
	front = NULL; 
	rear = NULL; 
	numItems = 0; 
}

//Destructor
DynQueue::~DynQueue()
{
	clear();
}

void DynQueue::enqueue(string num) 
{ 
	QueueNode *newNode; 

	// Create a new node and store num there. 
	newNode = new QueueNode; 
	newNode->value = num; 
	newNode->next = NULL; 

	// Adjust front and rear as necessary. 
	if (isEmpty()) 	
	{ 
		front = newNode; 
		rear = newNode;
	} 
	else 
	{
		rear->next = newNode; 
		rear = newNode; 
	} 
	
	// Update numItems. 
	numItems++;
}

void DynQueue::dequeue(string &num) 
{ 
	QueueNode *temp; 

	if (isEmpty()) 
	{ 
		cout << "The queue is empty.\n"; 
	} 
	else 
	{ 
		// Save the front node value in num. 
		num = front->value; 

		// Remove the front node and delete it. 
		temp = front; 
		front = front->next; 
		delete temp; 
	
		// Update numItems. 
		numItems--; 
	} 
}

bool DynQueue::isEmpty() const 
{ 
	bool status; 

	if (numItems > 0){ 
		status = false;
	}	
	else{ 
		status = true; 
	}
	return status; 
}

void DynQueue::clear()
{
	string value;   // Dummy variable for dequeue 

	while(!isEmpty()){ 
	dequeue(value);
	}
}
#endif