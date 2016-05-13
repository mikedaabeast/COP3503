#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "pa3.h"
using namespace std;   

void cuttingCaps(string c);
void UpperVsLower(string s);
int location(char c);
void constVsIdent(string s);

DynStack stack;  
DynQueue errors; 
DynQueue ident;
DynQueue cons;
DynQueue Key;

int main()   
{   
	string fname;
	string fline;
	string tt2;
	char choice;
	string test;
	string tmp;
	string catchVar;
	bool IE = false;
	int loc;
	int FWc=0;
	int end=0;
	int begin=0;
	const int maxDelim = 4; 
	const int maxOper = 13;
	// 40, 41, 59 , 44 are the ASCII number for
	// ( ) ; ,	
	int delim[][maxDelim] = {{40,0},{41,0},{59,0},{44,0}}; 
	// the numbers are the ASCII number. 1, 2, 3, 4 we represent the double operators
	// + − * / = < > ! ++ −− == && ||
	int oper[][maxOper] = {{43, 0}, {45, 0}, {42,0}, {47,0}, {61,0}, {60,0}, {62,0}, {33,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5, 0}};
	
	cout << "Please enter the file path:\n";
	cin >> fname;
	ifstream file(fname.c_str());
	if (file.fail()){
			cout <<"This File does not exist\nEnding Program" << endl;
			return 0;
	}	
	while(getline(file, fline)) {
		istringstream line(fline);

		while(line >> fline) {
			int l = fline.length();
			char buffer[l];
			strcpy(buffer, fline.c_str());
	
			for(int i = 0; i < l; i++){
				choice = buffer[i];
				switch (choice)  
				{	  
					case '(':;   
					case ')':; 
					case ';':;
					case ',':;
					case '*':;
					case '/':;
					case '<':;
					case '>':;
					case '!':;
							if(!test.empty()){
								UpperVsLower(test);	
								test.clear();
							}		
							loc = location(choice);
							if (loc > 19)
							{			
								loc = loc - 20;
								delim[loc][1]= delim[loc][1] + 1;
							}
							else{
								oper[loc][1] = 1;
							} 
							tmp.assign(1, choice);
							stack.push(tmp);
							tmp.clear();
							break;
					case '+':;
					case '-':;
					case '=':;
					case '&':;
					case '|':;
							if(!test.empty()){
								UpperVsLower(test);
								test.clear();
							}
							if((i+1) < l)
							{
								if(buffer[i+1] == choice)
								{
									char tmpL;
									if(choice == '+'){
										tmpL = '1';
									}
									if(choice == '-'){
										tmpL = '2';
									}
									if(choice == '='){
										tmpL = '3';
									}
									if(choice == '&'){
										tmpL = '4';
									}
									if(choice == '|'){
										tmpL = '5';
									}
									loc = location(tmpL);
									string twos;
									twos.assign(2, choice);
									stack.push(twos);
									i++;
								}
								else
								{
									loc = location(choice);
									tmp.assign(1, choice);
									stack.push(tmp);
									tmp.clear();
								}	
							}
							else
							{
								loc = location(choice);
								tmp.assign(1, choice);								
								stack.push(tmp); 
								tmp.clear();
							}
							if (loc > 19)
							{			
								loc = loc - 20;
								delim[loc][1]++;
							}
							else{
							oper[loc][1] = 1;
							}
							break;
					default:
							test.append(1, choice);
							;	  
				} 
			}
			if(!test.empty()){
				UpperVsLower(test);
				test.clear();
			}	
		}
	}
	
	while(!stack.isEmpty())
	{
		stack.pop(catchVar);
		if(catchVar.compare("FOR") == 0 || catchVar.compare("WHILE") == 0)
		{
			FWc++;
		}		
	}
	cout << "\nThe depth of nested loop(s) is " << FWc << endl;

	cout << "\nKeywords: ";
	while (!Key.isEmpty())
	{
		string value;
		Key.dequeue(value);
		if(value.compare("BEGIN") == 0)
		{
			begin++;	
		}
		if(value.compare("END") == 0)
		{
			end++;
		}
		if(value.compare("ELSE") == 0 || value.compare("ELSEIF") == 0)
		{
			string val;
			Key.dequeue(val);
			if(value.compare("IF") != 0 || value.compare("ELSEIF") != 0)
			{
				IE = true;
			}
			Key.enqueue(val);
		}
		cout << value << " ";
	}
	cout << "\nIdentifier: ";
	while (!ident.isEmpty())
	{
		string value;
		ident.dequeue(value);
		cout << value << " ";
	}
	
	cout <<"\nConstant: ";
	while (!cons.isEmpty())
	{
		string value;
		cons.dequeue(value);
		cout << value << " ";
	}

	cout << "\nOperators: ";
	
	for(int i = 0; i < 13; i++)
	{
			if(oper[i][1] != 0)
			{
				if(oper[i][0] == 1)
				{
					cout << "++ ";
				}
				if(oper[i][0] == 2)
				{
					cout << "-- "; 
				}
				if(oper[i][0] == 3)
				{
					cout << "== ";
				}
				if(oper[i][0] == 4)
				{
					cout << "&& ";
				}
				if(oper[i][0] == 5)
				{
					cout << "|| ";
				}
				if(oper[i][0] != 1 && oper[i][0] != 2 && oper[i][0] != 3 && oper[i][0] != 4 && oper[i][0] != 5)
				{	
					char asciiChar = oper[i][0];
					cout << asciiChar << " ";
				}	
			}
	}
	cout << "\nDelimiter: ";	
	for(int i=0; i < 4; i++)
	{
			if(delim[i][1] != 0)
			{
				char asciiChar = delim[i][0];
				cout << asciiChar << " ";
			}
	}
	cout << "\n" << endl;
	
	int error = 0; 
	while (!errors.isEmpty())
	{	
		error++;
		string value;
		errors.dequeue(value);
		cout << "Error(" << error << "): "  << value << endl;
	}
	if(delim[0][1] != delim [1][1])
	{
			error++;
			cout << "Error(" << error << "): Invalid parentheses." << endl;
	}
	if(end > begin)
	{
		error++;
		cout << "Error(" << error << "): Missing BEGIN(s)." << endl;
	}
	if(begin > end)
	{
		error++;
		cout << "Error(" << error << "): Missing END(s)." << endl;
	}
	if(IE){
		error++;
		cout << "Error(" << error << "): Missing IF/ELSEIF(s)" << endl;
	}
	file.close();
exit(0);
}

void UpperVsLower(string s)
{
	char choice;
	string tU;
	string tL;
	int l = s.length();
	char buffer[l];
	
	strcpy(buffer, s.c_str());
	
	for(int i = 0; i < l; i++){
		choice = buffer[i];
		if(isupper(choice))
		{	
			if(!tL.empty())
			{
				constVsIdent(tL); 
				tL.clear();
			}
			tU.append(1, choice);
		}
		else{
			if(!tU.empty())
			{	
				cuttingCaps(tU);
				tU.clear();
			}
			tL.append(1, choice);
		}
	}
	if(!tL.empty())
	{
		constVsIdent(tL); 
		tL.clear();
	}
	if(!tU.empty())
	{	
		cuttingCaps(tU);
		tU.clear();
	}
}

void constVsIdent(string s){
		stack.push(s);
		int l = s.length();
		char buffer[l];
		strcpy(buffer, s.c_str());
		bool num = true;
		for(int i = 0; i<l;i++){
			if (!isdigit(buffer[i])){
				num = false;
			}				
		}
		if(num){
			cons.enqueue(s);	
		}
		else{
			ident.enqueue(s);
		}	
}	
	
void cuttingCaps(string c){
	bool key;
	char choice;
	char temp;
	string t;
	int l = c.length();
	int size;
	int tknSize;
	char buffer[l];
	strcpy(buffer, c.c_str());
	for(int i = 0; i < l; i++){
		choice = buffer[i];
		tknSize = 0;
		key = false;
		switch (choice)  
		{
				case 'W':;
				case 'B':;
					tknSize = 4;
					break;
				case 'F':;
					tknSize = 2;
					break;
				case 'I':;
					tknSize = 1;
					break;
				case 'E':;
					if(i+2<l)
					{
						if(buffer[i+1] == 'N' && buffer[i+2] == 'D')
						{
							tknSize = 2;
						}
					}	
					if(i+5<l)
					{ 
							if(buffer[i+1] == 'L' && buffer[i+2] == 'S' && buffer[i+3] == 'E' && buffer[i+4] == 'I' && buffer[i+5] == 'F')
							{
								tknSize = 5;
							}		
					}
					if(i+3<l)
					{ 
							if(buffer[i+1] == 'L' && buffer[i+2] == 'S' && buffer[i+3] == 'E' && tknSize != 5)
							{
								tknSize = 3;
							}		
					}
					if(tknSize ==0)
					{
						tknSize = l-1;
					}
					break;
				default:;
					tknSize = 0;
		}
		if(tknSize != 0)
		{	
			size = i;
			if(i+tknSize<l)
			{
				for(int j = size; j<size+tknSize+1;j++,i++)
				{
					temp = buffer[j];
					t.append(1,temp);
				}
				//”BEGIN”, ”END”, ”FOR”, ”WHILE”, ”IF”, ”ELSE”, ”ELSEIF”
				if(t.compare("END") == 0 || t.compare("BEGIN") == 0|| t.compare("FOR") ==0 || t.compare("WHILE") ==0 
						|| t.compare("IF") == 0 || t.compare("ELSE") == 0|| t.compare("ELSEIF")==0)
				{
					key = true;
				}
				if(key == false){
					errors.enqueue(t);
				}
				if(key){
					Key.enqueue(t);
				}	
				stack.push(t); 
				t.clear(); 
			}
			else{
				for(int j = size; j < l; j++,i++)
				{	
					temp = buffer[j];
					t.append(1, temp);
				}
				stack.push(t); 
				t.clear();
				continue; 
			}
			i=i-1;
		}
	}
}

int location(char c){
	int loc;
	switch (c)  
	{
		case '(':;
			loc=20;
			break;		
		case ')':;
			loc=21;
			break;		
		case ';':;
			loc=22;
			break;
		case ',':;
			loc=23;
			break;
		// 	+ − * / = < > ! ++ −− == && ||
		case '+':;
			loc=0;
			break;
		case '-':;
			loc=1;
			break;
		case '*':;
			loc=2;
			break;
		case '/':;
			loc=3;
			break;
		case '=':;
			loc=4;
			break;
		case '<':;
			loc=5;
			break;
		case '>':;
			loc=6;
			break;
		case '!':;
			loc=7;
			break;		
		case '1':;
			loc=8;
			break;		
		case '2':;
			loc=9;
			break;		
		case '3':;
			loc=10;
			break;		
		case '4':;
			loc=11;
			break;		
		case '5':;
			loc=12;
			break;
	}
	return(loc);
}