#include <iostream> //cout and cin
#include <iomanip> //Edit spacing and output
#include <string> //Use string
#include <cmath> //Does Math operations
#include <string> //
#include <cstring> //
#include <cstdlib> //
#include <fstream> //Works with files
#include "class.h"
using namespace std;

//Prototypes
bool valNum(string input);
bool ValDoub(string theString);
int getMS(string input);
double getDS(string input);
void checkQuiz(unsigned int);
void checkTest(unsigned int);
void checkAssignments(unsigned int);
void checkHW(unsigned int);
void checkETCS(unsigned int);
double addOne();
double addTotal();
void catList(unsigned int place);
char Choice();
void readSavedFile();
void saveFile();
void Stats(unsigned int);

//Global vector
vector<Class> courses;

int main(){
    char choice;
    string input; string nmbr;
    int siz;
    bool exit = false, ValInput = false;
	unsigned int vCount = 0;
	
	
	
	cout << " $$$$$$\\                           $$\\                  $$$$$$\\            $$\\           "<<endl;
	cout << "$$  __$$\\                          $$ |                $$  __$$\\           $$ |          "<<endl;
	cout << "$$ /  \\__| $$$$$$\\  $$$$$$\\   $$$$$$$ | $$$$$$\\        $$ /  \\__| $$$$$$\\  $$ | $$$$$$$\\ "<<endl;
	cout << "$$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$ |$$  __$$\\       $$ |       \\____$$\\ $$ |$$  _____|"<<endl;
	cout << "$$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ /  $$ |$$$$$$$$ |      $$ |       $$$$$$$ |$$ |$$ /      "<<endl;
	cout << "$$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$   ____|      $$ |  $$\\ $$  __$$ |$$ |$$ |      "<<endl;
	cout << "\\$$$$$$  |$$ |     \\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\       \\$$$$$$  |\\$$$$$$$ |$$ |\\$$$$$$$\\ "<<endl;
	cout << " \\______/ \\__|      \\_______| \\_______| \\_______|       \\______/  \\_______|\\__| \\_______|"<<endl;                              
	cout << "\n\t\tPress keyboard to continue" << endl;	
    getline(cin, input);	
	input.clear();
	cout << "\n\t          			FOR UF GATORS!!!\n\n";
	cout <<"                    _.---._     .---."<< endl;
	cout <<"            __...---' .---. `---'-.   `."<< endl;
	cout <<"  ~ -~ -.-''__.--' _.'( | )`.  `.  `._ :"<< endl;
	cout <<" -.~~ .'__-'_ .--'' ._`---'_.-.  `.   `-`."<< endl;
	cout <<"  ~ ~_~-~-~_ ~ -._ -._``---. -.    `-._   `."<< endl;
	cout <<"   ~- ~ ~ -_ -~ ~ -.._ _ _ _ ..-_ `.  `-._``--.._"<< endl;
	cout <<"     ~~-~ ~-_ _~ ~-~ ~ -~ _~~_-~ -._  `-.  -. `-._``--.._.--''. ~ -~_"<< endl;
	cout <<"         ~~ -~_-~ _~- _~~ _~-_~ ~-_~~ ~-.___    -._  `-.__   `. `. ~ -_~"<< endl;
	cout <<"             ~~ _~- ~~- -_~  ~- ~ - _~~- _~~ ~---...__ _    ._ .` `. ~-_~"<< endl;
	cout <<"                ~ ~- _~~- _-_~ ~-_ ~-~ ~_-~ _~- ~_~-_~  ~--.....--~ -~_ ~"<< endl;
	cout <<"                     ~ ~ - ~  ~ ~~ - ~~-  ~~- ~-  ~ -~ ~ ~ -~~-  ~- ~-~	" << endl;	
	cout << "===========================================================================================\n";
	//Read from a save file if found		
	readSavedFile();
	//Set vector count to size
	vCount = courses.size();
	
	do{
		vCount = courses.size();
        do {
			cout << "\n\nPlease Enter a choice\n";
			cout << "1. Add a course \n"; //Add a course to vector
			cout << "2. Edit a course \n"; //edit grades in vector
			cout << "3. View course(s)\n"; //view a list of courses and grades
			cout << "4. Delete a course \n"; //deletes a course from the vector
			cout << "5. Exit Program\n\n"; //Exit Program
			cout << "Choice: "; //user inputs number
			getline(cin, input); 

			//If user enters ENTER
			if(input.empty()){
				cout << "\nError, invalid input\n\n";
			}
			else {
				siz = input.size(); 
				//If user enters more than one character
				if (siz > 1) {
				cout << "\nError, invalid input\n\n";
				}
				else {
					ValInput = true;
					choice = input.at(0);
				}
			}
		}while (ValInput == false);
		ValInput = false;//False for next time used
		
		//FIRST-MAIN  MENU
		switch(choice){
		case '1': 
	    {
			//Sets dummy variable 
			string ProfName; string ClassName; string CourseCode;
			int creditHours;

			//adds to vector
			Class newClass;
			courses.push_back(newClass);
			
			do{
				cout << "What is your professor's name?\n";
				ProfName.clear();
				getline(cin, ProfName); 
				//IF input is empty
				if(ProfName.empty()){
					cout << "\nError, invalid input\n\n";
				}
				else {
					ValInput = true; 
				}
			}while (ValInput == false);
			ValInput = false;//False for next time used
			
			//Takes course details
			do{
				cout << "What is the name of your Course?(ex: Calc 1)\n";
				ClassName.clear();
				getline(cin, ClassName); 
				//IF input is empty
				if(ClassName.empty()){
					cout << "\nError, invalid input\n\n";
				}	
				else {
					ValInput = true; 
				}
			}while (ValInput == false);
			ValInput = false; //False for next time used
			
			do{
				cout << "What is your Course Code?(ex: MAC2311)\n";
				CourseCode.clear();
				getline(cin, CourseCode);
				//IF input is empty
				if(CourseCode.empty()){
					cout << "\nError, invalid input\n\n";
				}
				else {
					ValInput = true; 
				}
			}while(ValInput == false);
			ValInput = false; //False for next time used
			
			while(ValInput == false){
				nmbr.clear();
				cout << "How many credit hours is this course?\n";
				getline(cin, nmbr);
				ValInput = valNum(nmbr);
			}
			creditHours = getMS(nmbr);
			ValInput = false;
			//Set method to object
			courses[vCount].setDescription(ProfName, ClassName, CourseCode, creditHours);

			cout << "Please enter 0 for assessment type, if you don't have that in\n";
			cout << "your grading scale. Thank you\n\n";
			
			//Sets Categories for course
			checkQuiz(vCount);
			checkTest(vCount);
			checkAssignments(vCount);			
			checkHW(vCount);
			checkETCS(vCount);
			courses[vCount].setGrade();
			cout << "Your current grade in the class is " << courses[vCount].getGrade() << endl;			
	        vCount++;
			ValInput = false;
			break;
		}
        case '2': 
        {
			//EDIT A CLAS
			cout << "You want to EDIT course(s)" << endl;
			//CHECKS IF THERE ARE COURSES SAVED
			if(courses.size() > 0)
			{	
				//Unsigned int for vector looping
				unsigned int place =  0;
				cout << "These are the course you have saved:" << endl;
				for(unsigned int i = 0; i < courses.size(); i++){
					cout << (i+1) << ". " << courses[i].getClassName() << endl;
				}
				//temp bool for user-validation
				bool valnum = false; 
				while(valnum == false){			
					while(ValInput == false)
					{
						nmbr.clear();
						cout << "Please type the number next to the course name to edit more: ";
						getline(cin, nmbr);
						ValInput = valNum(nmbr);
					}	
					ValInput = false;
					//Abs for unsigned int, -1 for one off start position
					place = (abs(getMS(nmbr)) - 1);
					if(place < courses.size())
					{
							valnum = true;
					}
					else{
						cout << "Not a valid choice" << endl;
					}
				}
				//Variables for submenu
				bool miniExit = false;
				char minichoice;
				do{
					do{
						cout << "Please Enter a choice\n";
						cout << "1. Add a category\n"; //Adds a category
						cout << "2. Edit a category\n"; //Edit a category 
						cout << "3. Delete a category\n"; //Delete a category
						cout << "4. Stop editing\n\n"; 
						cout << "Choice: "; //user inputs number
						getline(cin, input); 

						//If user enters ENTER
						if(input.empty()){
							cout << "\nError, invalid input\n\n";
						}
						else {
							siz = input.size(); 
							//If user enters more than one character
							if (siz > 1) {
								cout << "\nError, invalid input\n\n";
							}
							else {
								ValInput = true;
								minichoice = input.at(0);
							}
						}					
					}while (ValInput == false); //False for next time used
					ValInput = false;
					switch(minichoice){
						case '1': 
						{
								
								cout << "You want to ADD a category" << endl;
								cout << "Please enter 0 for assessment type, if you don't have that in\n";
								cout << "your grading scale. Thank you\n\n";
								//Check if user wants to add the quiz category
								if(courses[place].getQuizConfrim() ==false){
									checkQuiz(place);
								}
								//Check if user wants to add the test category
								if(courses[place].getTestConfrim() == false){
									checkTest(place);
								}	
								//Check if user wants to add the assignment category
								if(courses[place].getAssignmentsConfrim() == false){
									checkAssignments(place);
								}
								////Check if user wants to add the HW category
								if(courses[place].getHwConfrim() == false){
									checkHW(place);
								}
								//Check if user wants to add extra categories
								if(courses[place].getE5Confrim() == false || courses[place].getE6Confrim() == false 
									|| courses[place].getE7Confrim() == false || courses[place].getE8Confrim() == false 
									|| courses[place].getE9Confrim() == false|| courses[place].getE10Confrim() == false)
								{
									checkETCS(place);
								}
								//IF all ten categories are used, you cannot add more
								if(courses[place].getQuizConfrim() == true && courses[place].getTestConfrim() == true 
									&& courses[place].getAssignmentsConfrim() == true && courses[place].getHwConfrim() == true
									&& courses[place].getE5Confrim() == true && courses[place].getE6Confrim() == true 
									&& courses[place].getE7Confrim() == true && courses[place].getE8Confrim() == true 
									&& courses[place].getE9Confrim() == true && courses[place].getE10Confrim() == true)
								{
									cout << "You cannot add any more categories, Sorry" << endl;
								}
								break;
							}
						case '2': 
						{
								cout << "You want to EDIT a category\n" << endl;
								char editChoice;
								bool editExit = false;
								do{
									//Display what can be edited 
									catList(place);	
									editChoice = Choice();
									switch(editChoice){
										
										//========================================================================
										//The NEXT 10 CASES are the same, except the fact of which vector from the
										//Class/object is being used. WE commented only the first case, to keep 
										//Simple and neat
										//=========================================================================
										
										case '1': 
										{
											if(courses[place].getQuizConfrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												//Sub menu for editing 
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														//Add a grade
														case '1':
														{
															//Prints grades from category 
															courses[place].printQuiz();
															//Temp double 
															double grd, grdTotal;
															//Grade to add
															grd = addOne();		
															//How many points the item is worth
															grdTotal = addTotal();
															//Adds new grade
															courses[place].addQuiz(grd, grdTotal);
															//Resets the percent of category
															courses[place].setQuizPercent();
															break;
														}
														case '2':
																valnum = false;
																if(courses[place].getQuizLength() > 0)
																{	
																	unsigned int loc =  0;
																	cout << "These are the grades you have saved:" << endl;
																	courses[place].printQuiz();
																	while(valnum == false){			
																		do{
																			nmbr.clear();
																			cout << "Please type the number next to the grade you would like to remove: ";
																			getline(cin, nmbr);
																			ValInput = valNum(nmbr);
																		}while(ValInput == false);
																		
																		ValInput = false;
																		loc = (abs(getMS(nmbr)));
																		
																		unsigned int comp = abs(courses[place].getQuizLength());			
																		if(place < comp)
																		{
																				valnum = true;
																				courses[place].removeQuiz(loc);
																				courses[place].setQuizPercent();
																		}
																		else{
																			cout << "Not a valid choice" << endl;
																		}
																	}
																}
																else
																{
																	cout << "There are no grades" << endl; 
																}
																valnum = false; 							
																break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}	
											break; 
										}
										case '2': 
										{
											if(courses[place].getTestConfrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printTest();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addTest(grd, grdTotal);
															courses[place].setTestPercent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getTestLength() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printTest();
																while(valnum == false){			
																	do{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}while(ValInput == false);;
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getTestLength());
																	if(place < comp)
																	{
																		courses[place].removeTest(loc);
																		courses[place].setTestPercent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false; 
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}
											break; 
										}
										case '3': 
										{
											if(courses[place].getAssignmentsConfrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printAssignments();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addAssignments(grd, grdTotal);
															courses[place].setAssignmentsPercent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getAssignmentsLength() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printAssignments();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getAssignmentsLength());
																	if(place < comp)
																	{
																		courses[place].removeAssignments(loc);
																		courses[place].setAssignmentsPercent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false; 
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}
											break;
										}
										case '4': 
										{
											if(courses[place].getHwConfrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printHw();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addHW(grd, grdTotal);
															courses[place].setHWPercent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getHwLength() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printHw();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getHwLength());
																	if(place < comp)
																	{
																		courses[place].removeHW(loc);
																		courses[place].setHWPercent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false; 
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}											
											break; 
										}
										case '5': 
										{
											if(courses[place].getE5Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc5();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc5(grd, grdTotal);
															courses[place].setEtc5Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc5Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc5();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc5Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc5(loc);
																		courses[place].setEtc5Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}																
											break; 
										}
										case '6': 
										{
											if(courses[place].getE6Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc6();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc6(grd, grdTotal);
															courses[place].setEtc6Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc6Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc6();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc6Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc6(loc);
																		courses[place].setEtc6Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}									
											break; 
										}
										case '7': 
										{
											if(courses[place].getE7Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc7();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc7(grd, grdTotal);
															courses[place].setEtc7Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc7Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc7();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc7Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc7(loc);
																		courses[place].setEtc7Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}										
											break; 
										}
										case '8': 
										{
											if(courses[place].getE8Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc8();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc8(grd, grdTotal);
															courses[place].setEtc8Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc8Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc8();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc8Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc8(loc);
																		courses[place].setEtc8Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}
											break; 
										}
										case '9': 
										{
											if(courses[place].getE9Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc9();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc9(grd, grdTotal);
															courses[place].setEtc9Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc9Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc9();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc9Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc9(loc);
																		courses[place].setEtc9Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}											
											break; 
										}
										case '0': 
										{
											if(courses[place].getE10Confrim() == false){
												cout << "Cannot edit an empty category"<< endl;
											}
											else
											{
												char pick;
												bool exit2 = false;
												do{
													cout << "Enter\n1 to add a grade\n2 to delete a grade\nE to exit" << endl;   
													pick = Choice();
													switch(pick){
														case '1':
															courses[place].printEtc10();
															double grd, grdTotal;
															grd = addOne();							
															grdTotal = addTotal();
															courses[place].addEtc10(grd, grdTotal);
															courses[place].setEtc10Percent();
															break;
														case '2':
															valnum = false;
															if(courses[place].getEtc10Length() > 0)
															{	
																unsigned int loc =  0;
																cout << "These are the grades you have saved:" << endl;
																courses[place].printEtc10();
																courses[place].setEtc10Percent();
																while(valnum == false){			
																	while(ValInput == false)
																	{
																		nmbr.clear();
																		cout << "Please type the number next to the grade you would like to remove: ";
																		getline(cin, nmbr);
																		ValInput = valNum(nmbr);
																	}
																	ValInput = false;
																	loc = (abs(getMS(nmbr)));
																	unsigned int comp = abs(courses[place].getEtc10Length());
																	if(place < comp)
																	{
																		courses[place].removeEtc10(loc);
																		courses[place].setEtc10Percent();
																		valnum = true;
																	}
																	else{
																		cout << "Not a valid choice" << endl;
																	}
																}
															}
															else
															{
																cout << "There are no grades" << endl; 
															}
															valnum = false;
															break;
														case 'E':
															exit2 = true;
															break;
														default:
															cout << "Not a valid choice" << endl;
													}
												}while(exit2 == false);
											}
											break;
										}
										case 'E':
										{
											editExit = true;
											break;
										}
										default: 
											cout << "\nError, invalid input\n\n";
									}
								}while(editExit == false);							
							break;		
						}
						case '3': 
						{
							//Allow deletion of a category
							cout << "You want to DELETE a category" << endl;
							char editChoice;
							bool editExit = false;
							do{
								//Print all categories
								catList(place);
								editChoice = Choice();
								switch(editChoice){
									case '1': 
									{
										//deletes this category if chosen
										if(courses[place].getQuizConfrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteQuiz();
										}
										break; 
									}
									case '2': 
									{
										//deletes this category if chosen
										if(courses[place].getTestConfrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteTest();	
										}										
										break; 
									}
									case '3': 
									{
										//deletes this category if chosen
										if(courses[place].getAssignmentsConfrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}	
										else{
											courses[place].deleteAssignments();
										}
										break; 
									}
									case '4': 
									{
										//deletes this category if chosen
										if(courses[place].getHwConfrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteHW();
										}
										break; 
									}
									case '5': 
									{
										//deletes this category if chosen
										if(courses[place].getE5Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteEtc5();	
										}
										break; 
									}
									case '6': 
									{
										//deletes this category if chosen
										if(courses[place].getE6Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}	
										else{
											courses[place].deleteEtc6();	
										}
										break; 
									}
									case '7': 
									{
										//deletes this category if chosen
										if(courses[place].getE7Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteEtc7();	
										}
										break; 
									}
									case '8': 
									{
										//deletes this category if chosen
										if(courses[place].getE8Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteEtc8();	
										}
										break; 
									}
									case '9': 
									{
										//deletes this category if chosen
										if(courses[place].getE9Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}
										else{
											courses[place].deleteEtc9();	
										}
										break; 
									}
									case '0': 
									{
										//deletes this category if chosen
										if(courses[place].getE10Confrim() == false){
											cout << "Cannot delete an empty category"<< endl;
										}	
										else{
											courses[place].deleteEtc10();	
										}
										break; 
									}
									case 'E':
									{
										editExit = true;
										break;
									}
									default: 
										cout << "\nError, invalid number\n\n";
								}
							}while(editExit == false);
							break;
						}
						case '4':
						{
							//EXITS edit sub-menu
							miniExit = true;
							break;
						}
						default: 
							cout << "\nError, invalid number\n\n";
						}
				}while(miniExit == false);
			}		
			else
			{
				cout << "You have no courses to edit" << endl;
			}	
	        break;
		}
	    case '3':
	    {
			//Option to view a course
			cout << "You want to VIEW course(s)" << endl;
			if(courses.size() > 0)
			{
				//DISPLAY courses saved
				cout << "These are the course you have saved:" << endl;
				unsigned int place =  0;
				for(unsigned int i = 0; i < courses.size(); i++){
					cout << (i+1) << ". " << courses[i].getClassName() << endl;
				}
				bool valnum = false; 
				while(valnum == false){
					//Validated user input
					while(ValInput == false)
					{
						nmbr.clear();
						cout << "please type the number next to the course name to view more: ";
						getline(cin, nmbr);
						ValInput = valNum(nmbr);
					}	
					ValInput = false;
					place = (abs(getMS(nmbr))-1);
					if(place < courses.size())
					{
							valnum = true;
					}
					else{
						cout << "Not a valid choice" << endl;
					}
				}
				//Display course name
				cout <<"\nNow Viewing " << courses[place].getClassName() << endl;;
				//Display course details
				courses[place].displayDescription(); 
				//Sets-updates grade after
				courses[place].setGrade();
				//Sets-updates total weight
				courses[place].setFullWeight();
				//Display grade
				cout << "You currently have a " << courses[place].getGrade() << endl;
				//Display if weights do not add up to 100%
				if(courses[place].getTotalWeight() > 1){
					cout << "WARNING, your the percent weights add up to MORE than 100%" << endl;
				}
				if(courses[place].getTotalWeight() < 1){
					cout << "WARNING, your the percent weights  add up to LESS than 100%" << endl;
				}
				
				//Let user vire grades in categories
				char viewChoice;
				bool viewExit = false;
				do{
					catList(place);
					cout << "Enter S to view get a predicted grade" << endl;
					viewChoice = Choice();
					switch(viewChoice){
						case '1': 
						{
							//If category is empty, it cannot be displayed 
							if(courses[place].getQuizConfrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printQuiz();
							}
							break; 
						}
						case '2': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getTestConfrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printTest();	
							}										
							break; 
						}
						case '3': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getAssignmentsConfrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}	
							else{
								courses[place].printAssignments();
							}
							break; 
						}
						case '4': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getHwConfrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printHw();
							}
							break; 
						}
						case '5': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE5Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printEtc5();	
							}
							break; 
						}
						case '6': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE6Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}	
							else{
								courses[place].printEtc6();	
							}
							break; 
						}
						case '7': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE7Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printEtc7();	
							}
							break; 
						}
						case '8': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE8Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printEtc8();	
							}
							break; 
						}
						case '9': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE9Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}
							else{
								courses[place].printEtc9();	
							}
							break; 
						}
						case '0': 
						{
							//If category is empty, it cannot be displayed
							if(courses[place].getE10Confrim() == false){
								cout << "Cannot view an empty category"<< endl;
							}	
							else{
								courses[place].printEtc10();	
							}
							break; 
						}
						case 'S':
						{
							Stats(place);
							break;
						}
 						case 'E':
						{
							viewExit = true;
							break;
						}
						default: 
							cout << "\nError, invalid choice\n\n";
					}
				}while(viewExit == false);
			}	
			else
			{
				cout << "You have no courses to view" << endl;
			}			
	        break;
		}
	    case '4': 
	    {
			//Delete a course
			cout << "You want to DELETE course(s)" << endl;
			//Make sure there are courses in the vector
			if(courses.size() > 0)
			{	
				//Display courses
				unsigned int place =  0;
				cout << "These are the course you have saved:" << endl; ;
				for(unsigned int i = 0; i < courses.size(); i++){
					cout << (i+1) << ". " << courses[i].getClassName() << endl;
				}

				//User-validation to make sure no out of bounds
				bool valnum = false; 
				while(valnum == false){			
					while(ValInput == false)
					{
						nmbr.clear();
						cout << "please type the number next to the course name to delete: ";
						getline(cin, nmbr);
						ValInput = valNum(nmbr);
					}	
					ValInput = false;
					place = (abs(getMS(nmbr))-1);
					if(place < courses.size())
					{
							valnum = true;
					}
					else{
						cout << "Not a valid choice" << endl;
					}
				}
				//Edge case of first element
				if(place == 0){
					courses.erase(courses.begin());
				}	
				else if(place == (courses.size() -1)){
					//Edge case if at end
					courses.pop_back();
					cout << "Course was succesfully deleted" << endl;
					vCount--;
				}//
				else{
					//normal case
					courses.erase(courses.begin()+place-1);
					cout << "Course was succesfully deleted" << endl;
					vCount--;
				}
			}	
			else
			{
				cout << "You have no courses to edit" << endl;
			}	
	        break;
		}
	    case '5':
	    {
			cout << "Now exiting program" << endl;
			cout << "           .-._   _ _ _ _ _ _ _ _\n";
			cout << ".-''-.__.-'00  '-' ' ' ' ' ' ' ' '-.\n";
			cout << "'.___ '    .   .--_'-' '-' '-' _'-' '._\n";
			cout << " V: V 'vv-'   '_   '.       .'  _..' '.'.\n";
			cout << "   '=.____.=_.--'   :_.__.__:_   '.   : :\n";
			cout << "           (((____.-'        '-.  /   : :\n";
			cout << "                              (((-'\\ .' /\n";
			cout << "                            _____..'  .'\n";
			cout << "                            '-._____.-'\n";	
			cout << "\t\tGO GATORS" << endl;
			//Save data
			saveFile();
			exit = true;
			break;
		}
	    default: 
	        cout << "\nError, invalid number\n\n";
	        }
    } while (exit == false);
    
    return 0;
}

bool valNum(string input){		
	//MaxDig = number of valid digits 
	const int MaxDig = 4;
	int siz;
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
				cout << "\nError, invalid input\n";
				return false;					
			}
		}
		//Check if number has more digits than the max	
		if(siz > MaxDig){
			cout << "\nError, over max digits";
			return false;			
		}			
		return true;			
	}
}

bool ValDoub(string theString){
	//
	
	string p1; string p2;
	bool all = false, p1b = false, p2b = false;
	//Location of period
	int location =  -1;
	//Length of string
	int l = theString.length();
	//char array of string
	char buffer[l];
	strcpy(buffer, theString.c_str());
	//look for period
	for(int i = 0; i < l; i++){
		char choice = buffer[i];
		if(choice == '.')
		{
			location = i;
		}
	}
	//if a period was found
	if(location != -1){ 
		//separate into two string, one afer the period, one before
		p1 = theString.substr(0, (location));
		p2 = theString.substr((location+1), (theString.length()-1));
		//make sure both substring are ints, since there cannot be another non-digit char
		//Ex 19.87
		//p1 = 19, p2 = 87
		//validates p1 and p2
		p1b = valNum(p1);
		p2b = valNum(p2);
		if(p1b == false || p2b == false){
			return (false);
		}
	}
	else
	{
	//If not period was found, check if input was invlad or an int 	
		all = valNum(theString);			
		return all;
	}
	return (true);
}

int getMS(string input){
	//return char array was number
	return atoi(input.c_str());						
}

double getDS(string input){
	//return string as double
	//NULL needed to go to the end of string
	return strtod(input.c_str(), NULL);
}

void checkQuiz(unsigned int vCount){
	
	bool ValInput = false, qC = false;	
	double quizWeight;
	int ql;
	string nmbr;
	while(ValInput == false){
		nmbr.clear();
		cout << "Number of quizzes taken: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
	}
	ValInput = false;
	ql = getMS(nmbr);
	
	if(ql != 0){
		qC = true;
		
		double quiz[ql];
		double quizTotal[ql];
		
		while(ValInput == false){
			nmbr.clear();
			cout << "How much are quizzes weighted in grading scale(Enter 70 for 70%): ";
			getline(cin, nmbr);
			ValInput = ValDoub(nmbr);
		}
		ValInput = false;
		quizWeight = (getDS(nmbr)/100.0); 
				
		for(int i = 0; i < ql;i++){
			while(ValInput == false){
				nmbr.clear();
				cout << "\nPlease enter grade on quiz " << i+1 << ": ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			quiz[i] = getDS(nmbr);
			while(ValInput == false){
				nmbr.clear();
				cout << "Out of how many points/percent: ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);				
				if(ql==1)
				{
					if(getDS(nmbr) == 0){
						ValInput = false;
						cout << "Not Valid" << endl; 
					}	
				}
			}
			
			ValInput = false;
			quizTotal[i] = getDS(nmbr);
		}
		courses[vCount].setQuiz(quiz, quizTotal, ql, qC, quizWeight);
	}
}	

void checkTest(unsigned int vCount){
	bool ValInput = false, tC = false; 
	double testWeight; 
	int tl;
	string nmbr;
		
	while(ValInput == false){
		nmbr.clear();
		cout << "Number of tests taken: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
	}
	ValInput = false;
	tl = getMS(nmbr);
	
	if(tl != 0){
		tC = true;
		
		double test[tl];
		double testTotal[tl];
		
		while(ValInput == false){
			nmbr.clear();
			cout << "How much are tests weighted in grading scale(Enter 70 for 70%): ";
			getline(cin, nmbr);
			ValInput = ValDoub(nmbr);
		}
		ValInput = false;
		testWeight = (getDS(nmbr)/100.0); 
		
		for(int i = 0; i < tl;i++){
			while(ValInput == false){
				nmbr.clear();
				cout << "\nPlease enter grade on test " << i+1 << ": ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			test[i] = getDS(nmbr);
			while(ValInput == false){
				nmbr.clear();
				cout << "Out of how many points/percent: ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
				if(tl==1)
				{
					if(getDS(nmbr) == 0){
						ValInput = false;
						cout << "Not Valid" << endl; 
					}	
				}				
			}
			ValInput = false;
			testTotal[i] = getDS(nmbr);
		}
		courses[vCount].setTest(test, testTotal, tl, tC, testWeight);
	}	
}

void checkAssignments(unsigned int vCount){
	bool aC = false, ValInput = false;
	double assignmentsWeight;
	int al;
	string nmbr;
	
	while(ValInput == false){
		nmbr.clear();
		cout << "Number of assignments completed: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
	}
	ValInput = false;
	al = getMS(nmbr);
		
	if(al != 0){
		aC = true;
		
		double assignments[al];
		double assignmentsTotal[al];
		
		while(ValInput == false){
			nmbr.clear();
			cout << "How much are the assignments weighted in grading scale(Enter 70 for 70%): ";
			getline(cin, nmbr);
			ValInput = ValDoub(nmbr);
		}
		ValInput = false;
		assignmentsWeight = (getDS(nmbr)/100.0);
		cout << "aSS WEIGHT IS " << assignmentsWeight << endl;
		
		for(int i = 0; i < al;i++){
			while(ValInput == false){
				nmbr.clear();
				cout << "\nPlease enter grade on assignments " << i+1 << ": ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			assignments[i] = getDS(nmbr);
			while(ValInput == false){
				nmbr.clear();
				cout << "Out of how many points/percent: ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);	
				if(al==1)
				{
					if(getDS(nmbr) == 0){
						ValInput = false;
						cout << "Not Valid" << endl; 
					}	
				}
			}
			ValInput = false;
			assignmentsTotal[i] = getDS(nmbr);
		}
		courses[vCount].setAssignments(assignments, assignmentsTotal, al, aC, assignmentsWeight);
	}
}

void checkHW(unsigned int vCount){
	bool hC = false,  ValInput = false;
	double hwWeight;
	int hl;
	string nmbr;
	
	while(ValInput == false){
		nmbr.clear();
		cout << "Number of Homeworks completed: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
	}
	ValInput = false;
	hl = getMS(nmbr);
			
	if(hl != 0){
		hC = true;
		
		double hw[hl];
		double hwTotal[hl];
				
		while(ValInput == false){
			nmbr.clear();
			cout << "How much are Homeworks weighted in grading scale(Enter 70 for 70%): ";
			getline(cin, nmbr);
			ValInput = ValDoub(nmbr);
		}
		ValInput = false;
		hwWeight = (getDS(nmbr)/100.0); 
		
		for(int i = 0; i < hl;i++){
			while(ValInput == false){
				nmbr.clear();
				cout << "\nPlease enter grade on Homework " << i+1 << ": ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			hw[i] = getDS(nmbr);
			while(ValInput == false){
				nmbr.clear();
				cout << "Out of how many points/percent: ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);	
				if(hl==1)
				{
					if(getDS(nmbr) == 0){
						ValInput = false;
						cout << "Not Valid" << endl; 
					}	
				}
			}
			ValInput = false;
			hwTotal[i] = getDS(nmbr);
		}
		courses[vCount].setHW(hw, hwTotal, hl, hC, hwWeight);
	}
}

void checkETCS(unsigned int vCount){
	bool ValInput = false;		
	bool e5C = courses[vCount].getE5Confrim();
	bool e6C = courses[vCount].getE6Confrim();
	bool e7C = courses[vCount].getE7Confrim();
	bool e8C = courses[vCount].getE8Confrim();
	bool e9C = courses[vCount].getE9Confrim();
	bool e10C = courses[vCount].getE10Confrim();
	double etc5Weight, etc6Weight, etc7Weight, etc8Weight, etc9Weight, etc10Weight;
	int   e5l = 0, e6l = 0, e7l = 0, e8l = 0, e9l =0, e10l; 
	string nmbr;
	
	cout << "\nIf you have any other categories for grades, we will allow\nup to 6 "
	<<"additional categories to fill out\nAgain, please enter 0 if these are not used" << endl;
	if(e5C == false)
	{
		while(ValInput == false){
			nmbr.clear();
			cout << "Number of items taken for category 1: ";
			getline(cin, nmbr);
			ValInput = valNum(nmbr);
		}
		ValInput = false;
		e5l = getMS(nmbr);
		
		if(e5l != 0){
			e5C = true;
			string ectName;
			double etc5[e5l];
			double etc5Total[e5l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			etc5Weight = (getDS(nmbr)/100.0); 
			
			for(int i = 0; i < e5l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
				}
				ValInput = false;
				etc5[i] = getDS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);				
					if(e5l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}
				}
				ValInput = false;
				etc5Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc5(etc5, etc5Total, e5l, e5C, etc5Weight, ectName);
		}
	}	
// e6 e6 e6 e6 E6 E6 E6 E6 E6 E6 E6 E6 6E 		
	if(e5C == true && e6C == false)
	{
		while(ValInput == false){
		nmbr.clear();
		cout << "Number of items taken for category 2: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
		}
		ValInput = false;
		e6l = getMS(nmbr);
		
		if(e6l != 0){
			e6C = true;
			string ectName;
			double etc6[e6l];
			double etc6Total[e6l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			etc6Weight = (getDS(nmbr)/100.0); 
		
			for(int i = 0; i < e6l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
				}
				ValInput = false;
				etc6[i] = getDS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
					if(e6l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}					
				}
				ValInput = false;
				etc6Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc6(etc6, etc6Total, e6l, e6C, etc6Weight, ectName);
		}
	}
// E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 		
	if(e6C == true && e7C == false)
	{
		while(ValInput == false){
		nmbr.clear();
		cout << "Number of items taken for category 3: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
		}
		ValInput = false;
		e7l = getMS(nmbr);
		
		if(e7l != 0){
			e7C = true;
			string ectName;
			double etc7[e7l];
			double etc7Total[e7l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			etc7Weight = (getDS(nmbr)/100.0); 
		
			for(int i = 0; i < e7l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
				}
				ValInput = false;
				etc7[i] = getDS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);		
					if(e7l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}
				}
				ValInput = false;
				etc7Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc7(etc7, etc7Total, e7l, e7C, etc7Weight, ectName);
		}
	}
// E8 E8 E8 E8 E8 E8 E8 E8 E8 E8 E8 E8
	if(e7C == true && e8C == false)
		{
		while(ValInput == false){
		nmbr.clear();
		cout << "Number of items taken for category 4: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
		}
		ValInput = false;
		e8l = getMS(nmbr);
		
		if(e8l != 0){
			e8C = true;
			string ectName;
			double etc8[e8l];
			double etc8Total[e8l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			etc8Weight = (getDS(nmbr)/100.0); 
		
			for(int i = 0; i < e8l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = valNum(nmbr);
				}
				ValInput = false;
				etc8[i] = getMS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
					if(e8l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}
				}
				ValInput = false;
				etc8Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc8(etc8, etc8Total, e8l, e8C, etc8Weight, ectName);
		}				
		
	}
//E9 E9 E9 E9 E9 E9 E9 E9 E9 E9 E9 E9 E9			
	if(e8C == true && e9C == false)
	{
		while(ValInput == false){
		nmbr.clear();
		cout << "Number of items taken for category 5: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
		}
		ValInput = false;
		e9l = getMS(nmbr);
		
		if(e9l != 0){
			e9C = true;
			string ectName;
			double etc9[e9l];
			double etc9Total[e9l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = valNum(nmbr);
			}
			ValInput = false;
			etc9Weight = (getMS(nmbr)/100.0); 
		
			for(int i = 0; i < e9l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
				}
				ValInput = false;
				etc9[i] = getDS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
					if(e9l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}
					
				}
				ValInput = false;
				etc9Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc9(etc9, etc9Total, e9l, e9C, etc9Weight, ectName);
		}				
	}
	
	if(e9C == true && e10C == false)
	{
		while(ValInput == false){
		nmbr.clear();
		cout << "Number of items taken for category 6: ";
		getline(cin, nmbr);
		ValInput = valNum(nmbr);
		}
		ValInput = false;
		e10l = getMS(nmbr);
				
		if(e10l != 0){
			e10C = true;
			string ectName;
			double etc10[e10l];
			double etc10Total[e10l];
			cout << "Please enter name of category: ";
			getline(cin, ectName);
			while(ValInput == false){
				nmbr.clear();
				cout << "How much is " << ectName  << " weighted in grading scale(Enter 70 for 70%): ";
				getline(cin, nmbr);
				ValInput = ValDoub(nmbr);
			}
			ValInput = false;
			etc10Weight = (getDS(nmbr)/100.0); 
			
			for(int i = 0; i < e10l;i++){
				while(ValInput == false){
					nmbr.clear();
					cout << "\nPlease enter grade on "<< ectName << ", item " << i+1 << ": ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
				}
				ValInput = false;
				etc10[i] = getDS(nmbr);
				while(ValInput == false){
					nmbr.clear();
					cout << "Out of how many points/percent: ";
					getline(cin, nmbr);
					ValInput = ValDoub(nmbr);
					if(e10l==1)
					{	
						if(getDS(nmbr) == 0){
							ValInput = false;
							cout << "Not Valid" << endl; 
						}	
					}
				}
				ValInput = false;
				etc10Total[i] = getDS(nmbr);
			}
			courses[vCount].setEtc10(etc10, etc10Total, e10l, e10C, etc10Weight, ectName);
		}
	}
}

double addOne(){
	//Get new grade to add
	bool ValInput = false;
	string nmbr;
	while(ValInput == false){
		nmbr.clear();
		cout << "Please enter new grade: ";
		getline(cin, nmbr);
		ValInput = ValDoub(nmbr);
	}
	return getDS(nmbr);
}
	
double addTotal(){
	//get total points of new grade
	bool ValInput = false;
	string nmbr;
	while(ValInput == false){
		nmbr.clear();
		cout << "Out of how many points/percent: ";
		getline(cin, nmbr);
		ValInput = ValDoub(nmbr);
	}
	return getDS(nmbr);
}

//Display categories and if they are empty or not
void catList(unsigned int place){
	cout << "Listing possible categories:" << endl;
	if(courses[place].getQuizConfrim() == true)
	{
		cout << "1. Quiz" << endl;	
	}
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getTestConfrim() == true)
	{
		cout << "2. Test" << endl;
	}	
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getAssignmentsConfrim() == true)
	{
		cout << "3. Assignments" << endl;
	}	
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getHwConfrim() == true)
	{
		cout << "4. Homework (HW)" << endl;
	}
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE5Confrim() == true)
	{
		cout << "5. " << courses[place].getE5Name() << endl;
	}
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE6Confrim() == true)
	{
		cout << "6. " << courses[place].getE6Name() << endl;
	}	
	else{
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE7Confrim() == true)
	{
		cout << "7. " << courses[place].getE7Name() << endl;
	}	
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE8Confrim() == true)
	{
		cout << "8. " << courses[place].getE8Name() << endl;
	}	
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE9Confrim() == true)
	{
		cout << "9. " << courses[place].getE9Name() << endl;
	}
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	if(courses[place].getE10Confrim() == true)
	{
		cout << "0. " << courses[place].getE10Name() << endl;
	}
	else{ 
		cout << "\tEmpty Category" << endl;
	}
	cout << "Enter E to exit" << endl;
	cout << "please enter corresponding number/character: ";	
}

char Choice(){	
	//Make sure choice is a valid char
	int siz;
	bool ValInput = false;
	string input;
	char choice;
	do{
		input.clear();
		getline(cin, input);
		//If user enters ENTER
		if(input.empty()){
			cout << "\nError, invalid input\n\n";
		}
		else {
			siz = input.size(); 
			//If user enters more than one character
			if (siz > 1) {
				cout << "\nError, invalid input\n\n";
			}
			else {
				ValInput = true;
				choice = input.at(0);
			}
		}					
	}while (ValInput == false); //False for next time used	
	return choice;
}

void readSavedFile(){
	//Open file in read mode, if it exists
	ifstream dataFile("course.txt");
	if(!dataFile)
	{
		//If no file, assume new user
		cout << "Save File does not exist, you must be a new user!" << endl; 
	}
	else
	{
		//if save found, take input
		cout << "A save file exists, Welcome Back!" << endl;
		int CC;
		dataFile >> CC;
		dataFile.ignore();
		unsigned int i = 0;
		for(int j = 0; j < CC; j++){
			string CN;
			string CID;
			string PN;
			string TFtemp;
			int Creds;
			Class newClass;
			courses.push_back(newClass);
		
			getline(dataFile, CN);
			//classname = CN;
		
			getline(dataFile, CID);
			//CourseCode = CID;

			getline(dataFile, PN);
			//ProfName = PN;

			dataFile >> Creds;
			dataFile.ignore();
			//creditHours = Creds;
	
			courses[i].setDescription(PN, CN, CID, Creds);
	//-------------------------Course Details are done -----------------
			//K represents what category
			for(int k = 1; k < 11; k++)
			{
				getline(dataFile, TFtemp);
				if(TFtemp.compare("true") == 0)
				{
					bool truth = true;
					string name;
					int count;
					double weight;
					dataFile >> count;
					dataFile >> weight;
					if(k>4){
							dataFile.ignore();
							getline(dataFile, name); 
					}
					double tempCount[count];
					for(int m = 0; m < count; m++)
					{
						dataFile >> tempCount[m];
					}		
				
					double tempTotal[count];
					for(int n = 0; n < count; n++)
					{
						dataFile >> tempTotal[n];
					}
					dataFile.ignore();
					if(k==1){
						courses[i].setQuiz(tempCount, tempTotal, count, truth, weight);
					}
					if(k==2){
						courses[i].setTest(tempCount, tempTotal, count, truth, weight);
					}
					if(k==3){
						courses[i].setAssignments(tempCount, tempTotal, count, truth, weight);
					}
					if(k==4){
						courses[i].setHW(tempCount, tempTotal, count, truth, weight);
					}
					if(k==5){
						courses[i].setEtc5(tempCount, tempTotal, count, truth, weight, name);
					}
					if(k==6){
						courses[i].setEtc6(tempCount, tempTotal, count, truth, weight, name);
					}
					if(k==7){
						courses[i].setEtc7(tempCount, tempTotal, count, truth, weight, name);
					}
					if(k==8){
						courses[i].setEtc8(tempCount, tempTotal, count, truth, weight, name);
					}
					if(k==9){
						courses[i].setEtc9(tempCount, tempTotal, count, truth, weight, name);
					}
					if(k==10){
						courses[i].setEtc10(tempCount, tempTotal, count, truth, weight, name);
					}
				}
				TFtemp.clear();
			}
			i++;
		}
	}
	
}

void saveFile()
{
	//Open-create file
	//if file is own, trunc-delete all items
	fstream outFile("course.txt", ios::out | ios::trunc);
	outFile << courses.size() << endl;
	for(unsigned int i = 0;  i < courses.size(); i++)
	{	
		outFile << courses[i].getClassName() << endl;	
		outFile << courses[i].getCourseCode() << endl;	
		outFile << courses[i].getProfName() << endl;
		outFile << courses[i].getcreditHours() << endl;
		
		if(courses[i].getQuizConfrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getQuizLength() << endl;
			outFile << courses[i].getQuizWeight() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getQuizLength();j++)
			{
				outFile << courses[i].getQuiz(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getQuizLength();j++)
			{
				outFile << courses[i].getQuizTotal(t) << endl;
				t++;
			}
		}	
		if(courses[i].getQuizConfrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getTestConfrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getTestLength() << endl;
			outFile << courses[i].getTestWeight() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getTestLength();j++)
			{
				outFile << courses[i].getTest(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getTestLength();j++)
			{
				outFile << courses[i].getTestTotal(t) << endl;
				t++;
			}
		}	
		if(courses[i].getTestConfrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getAssignmentsConfrim() == true)
		{
			cout << "HELLO" << endl;
			outFile << "true" <<endl;
			outFile << courses[i].getAssignmentsLength() << endl;
			cout << courses[i].getAssignmentsLength() << endl;
			outFile << courses[i].getAssignmentsWeight() << endl;
			cout << courses[i].getAssignmentsWeight() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getAssignmentsLength();j++)
			{
				outFile << courses[i].getAssignments(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getAssignmentsLength();j++)
			{
				outFile << courses[i].getAssignmentsTotal(t) << endl;
				t++;
			}
		}
		if(courses[i].getAssignmentsConfrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getHwConfrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getHwLength() << endl;
			outFile << courses[i].getHwWeight() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getHwLength();j++)
			{
				outFile << courses[i].getHw(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getHwLength();j++)
			{
				outFile << courses[i].getHwTotal(t) << endl;
				t++;
			}
		}
		if(courses[i].getHwConfrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE5Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc5Length() << endl;
			outFile << courses[i].getEtc5Weight() << endl;
			outFile << courses[i].getE5Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc5Length();j++)
			{
				outFile << courses[i].getEtc5(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc5Length();j++)
			{
				outFile << courses[i].getEtc5Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE5Confrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE6Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc6Length() << endl;
			outFile << courses[i].getEtc6Weight() << endl;
			outFile << courses[i].getE6Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc6Length();j++)
			{
				outFile << courses[i].getEtc6(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc6Length();j++)
			{
				outFile << courses[i].getEtc6Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE6Confrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE7Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc7Length() << endl;
			outFile << courses[i].getEtc7Weight() << endl;
			outFile << courses[i].getE7Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc7Length();j++)
			{
				outFile << courses[i].getEtc7(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc7Length();j++)
			{
				outFile << courses[i].getEtc7Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE7Confrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE8Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc8Length() << endl;
			outFile << courses[i].getEtc8Weight() << endl;
			outFile << courses[i].getE8Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc8Length();j++)
			{
				outFile << courses[i].getEtc8(t)  << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc8Length();j++)
			{
				outFile << courses[i].getEtc8Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE8Confrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE9Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc9Length() << endl;
			outFile << courses[i].getEtc9Weight() << endl;
			outFile << courses[i].getE9Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc9Length();j++)
			{
				outFile << courses[i].getEtc9(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc9Length();j++)
			{
				outFile << courses[i].getEtc9Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE9Confrim() == false)
		{outFile << "false" <<endl;}
		
		if(courses[i].getE10Confrim() == true)
		{
			outFile << "true" <<endl;
			outFile << courses[i].getEtc10Length() << endl;
			outFile << courses[i].getEtc10Weight() << endl;
			outFile << courses[i].getE10Name() << endl;
			unsigned int t =0; 
			for(int j = 0; j < courses[i].getEtc10Length();j++)
			{
				outFile << courses[i].getEtc10(t) << endl;
				t++;
			}
			t = 0;
			for(int j = 0; j < courses[i].getEtc10Length();j++)
			{
				outFile << courses[i].getEtc10Total(t) << endl;
				t++;
			}
		}
		if(courses[i].getE10Confrim() == false)
		{outFile << "false" <<endl;}
	}
	outFile.close();
}

void Stats(unsigned int x){
	//Stats, takes data from user to use in stats part
	if(courses[x].getTestConfrim() == true)
	{
		int questionaire[5];
		bool q1 = false, q2 = false, q3 = false, q4 = false, q5 = false;
		string nmbr;
		while(q1 == false){
			nmbr.clear();
			cout<<"On a scale of one to ten did you study more or less this time?"<<endl;
			getline(cin, nmbr);
			q1 = valNum(nmbr);
		}
		questionaire[0] = getMS(nmbr);
		
		while(q2 = false){
			nmbr.clear();
			cout<<"On a scale of one to ten did your workload increase?"<<endl;
			getline(cin,nmbr);
			q2 = valNum(nmbr);
		}
		questionaire[1] = getMS(nmbr);
		
		while(q3 == false){
			nmbr.clear();
			cout<<"On a scale of one to ten did the course difficulty increase?"<<endl;
			getline(cin,nmbr);
			q3 = valNum(nmbr);
		}
		questionaire[2] = getMS(nmbr);

		while(q4 == false){
			nmbr.clear();
			cout<<"On a scale of one to ten do you feel confident of getting a high grade on the assessment?"<<endl;
			getline(cin,nmbr);
			q4 = valNum(nmbr);
		}
		questionaire[3] = getMS(nmbr);		
		
		while(q5 == false){
			nmbr.clear();
			cout<<"On a scale of one to ten how was your week socially, academically, and your mood overall"<<endl;
			getline(cin,nmbr);
			q5 = valNum(nmbr);
		}
		questionaire[4] = getMS(nmbr);
		courses[x].statsPrediction(questionaire);
	}
	else{
	cout << "You need a test category!!" << endl;
	}	
}