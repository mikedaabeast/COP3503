#ifndef PA2_H
#define PA2_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
	
struct Node{
	string data;
	int mem;
	int number;	
	struct Node* next;
	struct Node* prev;
};

class LinkedList
{		
private:
	Node* head;

public:
	//Constructor	
	LinkedList()
	{head = NULL;}
	
	struct Node* GetNewNode(string x, int y, int z);
	void InsertAtHead(string x, int y, int z);
	void InsertAtTail(string x, int y, int z);
	void PrintFoward();
	int AvbMem();
	bool ComName(string Pname);
	void best(int PTA, int loc);
	void adder(int PTA, int loc, int value, string name);
	void kill();	
	int locationNFrag(int PTA, string Scase);

};

struct Node* LinkedList::GetNewNode(string x, int y, int z) 
{
	struct Node* newNode = new struct Node;
	newNode->data = x;
	newNode->mem = y;
	newNode->number = z;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Prints linked list in forward order
void LinkedList::PrintFoward() 
{
	struct Node* temp = head;
	for(int i = 1; temp != NULL;i++) {
		cout << temp->data << " ";
		temp = temp->next;
		if(i%8 == 0){
		cout << endl;		
		}
	}
	cout << endl;
}

//Inserts a Node at head of doubly LL
void LinkedList::InsertAtHead(string x, int y, int z)
{
	struct Node* newNode = GetNewNode(x, y, z);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at tail of Doubly LL
void LinkedList::InsertAtTail(string x, int y, int z)
{
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x, y, z);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL)
	{ 
	temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

int LinkedList::AvbMem(){
	//TMF Total Free Memory
	int TFM = 0;
	struct Node* temp = head;
	for(int i = 1; temp != NULL;i++) {
		if(temp->data.compare("free") == 0){
			TFM += 4;		
		}
		temp = temp->next;
	}
	return TFM;
}

bool LinkedList::ComName(string Pname){
	//Check if program name is already in use
	struct Node* temp = head;
	while(temp != NULL){
		if(Pname.compare(temp->data) == 0){
			return false;
		}		
	temp = temp->next;		
	}
	return true;
}

void LinkedList::adder(int PTA, int loc, int value, string name){	
	//change the contents of the node start from location(loc) 
	//and until enough pages have been used(PTA)
	int remain = value%4;
	struct Node* temp = head;
	while(temp->number != loc) {
		temp = temp->next;
	}
	for(int i = 1; i <= PTA; i++){
		if(i == PTA){
			temp->mem = remain;
			temp->data = name;	
		}		
		else{
		temp->mem = 4;	
		temp->data = name;	
		temp = temp->next;	
		}	
	}
return;
}

//Find location for Worst/Best, and how many fragments
int LinkedList::locationNFrag(int PTA, string Scase){	
	//MAX POSSIBLE SPACE MAX/2 = 16
	int memneed = (PTA* 4);
	int n = 2;
	int m = 32;	
	int mem[n][m];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< m; j++)
		{
			mem[i][j] = 0; 
		}
	}
	struct Node* temp = head;
	for(int i= 0; temp != NULL; i++){		
		if(temp->data.compare("free") ==0){
			mem[0][i] = 4;
			mem[1][i] = temp->number;
		}	
		temp = temp->next;
	}
	for(int i = (m-1); i > 0; i--){
		if(mem[1][i-1] == (mem[1][i] - 1)){
			mem[0][i-1] += mem[0][i];
			mem[0][i] = 0;
			mem[1][i] = 0;
		}
	}
	//Find Largest Free Space
	if(Scase.compare("worst") == 0){
		int largest = 0;
		int loc = 0;
		for(int i=0;i<m;i++)
    		{
			if(mem[0][i] > largest){
				largest = mem[0][i];
				loc = mem[1][i];
			}
		}
		if(memneed > largest){		
			return(-1);	
		}
	return loc;
	}
	//Find smallest location program can fit in
	if(Scase.compare("best") == 0){
		int smallest = 129;
		int loc = 0;
		for(int i=0;i<m;i++)
    		{
			if(mem[0][i] < smallest and mem[0][i] >= memneed){
				smallest = mem[0][i];
				loc = mem[1][i];
			}
		}
		if(loc == 0){
			return(-1);	
		}
		return loc;
	}
	//Counts the fragments
	int frag = 0;
	if(Scase.compare("frag") == 0){
		for(int i=0;i<m;i++)
    		{
			if(mem[1][i] !=0){
				frag += 1;
			}
		}
		cout << "There are " << frag << " fragment(s)\n\n";
		return(frag);	
	}
	return(-1);	
}

void LinkedList::kill(){
	string Kname;
	//Used to see if name doesnt exist
	bool killed = false;
	int PK = 0;
	cout << "Program Name - ";
	getline(cin, Kname);
	
	struct Node* temp = head;
		
	while(temp != NULL){
		if(Kname.compare(temp->data) == 0){
			temp->data = "free";
			temp->mem = 0;
			//if a node is changed, then there was a programing running with that name
			killed = true;
			PK += 1; 
		}		
	temp = temp->next;		
	}
	if(killed == true){
		cout << "Program " << Kname << " successfully killed, " << PK << " page(s) reclaimed." << endl;
	}
	else{
		//Since there was no programs killed with that name
		//then that program was never running
		cout << "No program with that name running" << endl; 	
	}
}
#endif