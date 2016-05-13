//pa2.cpp
//Michael Arboleda
//3/16/2015
#include <iostream>
#include <iomanip>
#include <string>
#include "pa2.h"
using namespace std;

//Prototypes
bool menu(string, LinkedList);
bool valNum(string input, string Pname, LinkedList);
bool valPro(string Pname, LinkedList);
int getMS(string input);
void AddPages(string input, LinkedList);
		
int main(int argc, char* argv[]){
	string fitcase;	
	if(argc == 2){
		fitcase = argv[1];	
	}
	else{
		fitcase = "false";
	}
	bool exit = false;
	LinkedList LL;	
	for(int i = 1; i < 33; i++ ){
		LL.InsertAtTail("free", 0, i);	
	}
	do{
		exit = menu(fitcase, LL);
	}while(exit == false);
		return 0;
}

bool menu(string fit, LinkedList LL){
	char choice;
	string input;
	int siz;
	bool ValSize = false, exit = false;
	//validate algorithm type 
	if(fit.compare("worst") == 0){
		cout << "Using worst fit algorithm" << endl;
	}
	else if(fit.compare("best") == 0){
		cout << "Using best fit algorithm" << endl;
	}
	else{
		cout << "you did not enter \"best\" or \"worst\"!\nEnding Program" << endl;
		return(true);
	}
	
	cout<< "\t1. Add program\n\t2. Kill program\n\t3. Fragmentation\n\t4. Print memory\n\t5. Exit\n";
	do{	
		do{

			cout << "Choice - ";
			getline(cin, input);
			//IF user enters ENTER
			if(input.empty()){
				cout << "\nError, invalid input\n\n";		
			}			
			else{	
				siz = input.size();
				//IF user enters more than one character 
				if(siz > 1){
					cout << "\nError, invalid input\n\n";			
				}
				else{
					ValSize = true;
					choice = input.at(0);			
				}
			}
		}while(ValSize == false);
	 	//False for next time used
		ValSize = false;
		
		switch(choice)
		{
			case '1': 
				AddPages(fit, LL);
				break; 
			case '2':
				LL.kill();
				break;
			case '3':
				LL.locationNFrag(0, "frag"); 
				break;
			case '4':
				LL.PrintFoward();				
				break;
			case '5':
				return(true);
				exit = true;
				break;	
			default: cout << "\nError, invalid number\n\n";
		}
	}while(exit == false);
	return true;
}

void AddPages(string WBcase, LinkedList LL){
	string input;
	string Pname;
	int value = 0, PTA = 0;
	bool VN = true, VP = true;

	cout << "Program Name - ";
	getline(cin, Pname);
	VP = valPro(Pname, LL);
	cout << "Program Size (KB) - ";	
	getline(cin, input);
	VN = valNum(input, Pname, LL);

	//Validate input
	if(VP == false){
	cout << "\nError, Program " << Pname << " already running\n\n";
	return;	
	}	
	if(VN == true){
		int loc = 0;		
		value = getMS(input);
		//Num of Pages to add	
		if(value%4 ==0 ){
			PTA = (value/4); 	
		}
		else{
			PTA = (value/4) + 1;		
		}
		//location of where to add program based on case
		loc = LL.locationNFrag(PTA, WBcase);					
		//if there is enough total free space, program cannot fit in any block
		if(loc == -1){
			cout << "\nError, continous block with enough memory not found\n\n";	
		}
		else{
			LL.adder(PTA, loc, value, Pname);
			cout << "\nProgram " << Pname << " added successfully: " << PTA << " page(s) used\n\n";	
		}
	}
}
bool valNum(string input, string Pname, LinkedList LL){		
	//MaxMem = 4KB times 32	
	const int MaxMem = 128;
	//MaxDig = number of digits MaxMem has
	const int MaxDig = 3;
	int siz;
	int AvbMem = LL.AvbMem();
	if(input.empty()){
		cout << "\nError, input was empty" << endl;
		return false;
	}			
	else{
		siz = input.size();
		//check if input entered is not a number 
		for(int i = 0; i < siz; i++ ){
			char check = input.at(i);
			if(isdigit(check) == false){
				cout << "\nError, invalid input\n\n";
				return false;					
			}
		}
		//Check if number has more digits than the max	
		if(siz > MaxDig){
			cout << "\nError, not enough memory to run Program "<< Pname << "\n\n";
			return false;			
		}
		int val = getMS(input);
		if(val == 0){
			cout << "\nError, can not run empty program\n\n";
			return false;
		}
		if(val > MaxMem or val > AvbMem){
			cout << "\nError, not enough memory to run Program" << Pname << "\n\n";			
			return false;
		}			
		return true;			
	}
}

int getMS(string input)
{	
	return atoi(input.c_str());						
}

bool valPro(string Pname, LinkedList LL){
	return LL.ComName(Pname);
}